#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 2e5 + 10;

i32 n;
i32 a[N], res, max, cnt_even, cnt_odd, cnt_at_odd;
i32 L[N], R[N], fa[N], vis[N], max_val[N], max_pos[N];

void clear(void)
{
	cnt_even = 0;
	cnt_odd = 0;
	cnt_at_odd = 0;
	res = 0;
	max = 0;
	std::fill(vis + 1, vis + 1 + n, 0);
}
void self_swap(i32 &x)
{
	x = ((x >> 1) & 1) | ((x << 1) & 2);
}
i32 get_contri(i32 u, i32 flg)
{
	i32 ret = 0;
	ret += (R[u] - L[u] + 1) / 2;
	if (((R[u] - L[u] + 1) & 1)) {
		if (max_val[u] == max) {
			cnt_odd += flg;
			if (max_pos[u] >> 1 & 1) {
				cnt_at_odd += flg;
			}
		}
		ret += 1;
	} else if (max_val[u] == max) {
		cnt_even += flg;
	}
	return ret;
}
void insert(i32 pos)
{
	L[pos] = pos;
	R[pos] = pos;
	fa[pos] = pos;
	vis[pos] = 1;
	max_val[pos] = a[pos];
	max_pos[pos] = 2;
	res += get_contri(pos, 1);
}
i32 find(i32 x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(i32 l, i32 r)
{
	l = find(l);
	r = find(r);
	res -= get_contri(l, -1);
	res -= get_contri(r, -1);
	i32 lb = L[l], rb = R[r];
	if ((R[l] - L[l] + 1) & 1) {
		self_swap(max_pos[r]);
	}
	if (max_val[l] < max_val[r]) {
		max_val[l] = max_val[r];
		max_pos[l] = max_pos[r];
	} else if (max_val[l] == max_val[r]) {
		max_pos[l] |= max_pos[r];
	}
	L[l] = lb;
	R[l] = rb;
	fa[r] = l;
	res += get_contri(l, 1);
}
void work(void)
{
	read >> n;
	std::priority_queue<pii> heap;
	std::vector<i32> vec;
	i32 final_res = 0;
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
		heap.emplace(a[i], i);
		max = std::max(a[i], max);
		vec.emplace_back(a[i]);
	}
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	std::reverse(vec.begin(), vec.end());
	for (auto v: vec) {
//		printf("v = %d\n", v);
		while (heap.size() && heap.top().first == v) {
			i32 pos = heap.top().second;
			heap.pop();
			insert(pos);
			if (vis[pos - 1]) merge(pos - 1, pos);
			if (vis[pos + 1]) merge(pos, pos + 1);
		}
//		printf("cnt_even = %d, cnt_odd = %d, cnt_at_odd = %d\n", cnt_even, cnt_odd, cnt_at_odd);
		final_res = std::max(final_res, res + v + max - (cnt_even == 0 && cnt_odd > 0 && cnt_at_odd == 0));
	}
	printf("%d\n", final_res);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	return 0;
}
