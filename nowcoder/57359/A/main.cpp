#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 5e5 + 10, B = 700;

i32 n, m;
i32 a[N], pos[N];
std::vector<i32> sum[N];

void addL(i32 id)
{
	if (pl[a[id]] == -1) {
		pl[a[id]] = pr[a[id]] = pos[id];
	}
	else {
		--pl[a[id]];
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> m;
	for (int i = 1; i <= n; ++i) {
		read >> a[i];
	}
	for (i32 i = 1; i <= n; ++i) {
		BIT::add(a[i]);
		pos[i] = sum[a[i]].size();
		sum[a[i]].emplace_back(BIT::query(a[i] - 1));
	}

	for (i32 i = 1; i <= m; ++i) {
		i32 l, r;
		read >> l >> r;
		q.emplace_back(l, r, i);
	}
	auto cmp = [](Query x, Query y)->bool {
		i32 idx = x.l / B, idy = y.l / B;
		return idx == idy ? ((idx & 1) ? x.r < y.r : x.r > y.r) : idx < idy;
	};
	std::sort(q.begin(), q.end(), cmp);

	std::memset(pl, -1, sizeof pl);
	std::memset(pr, -1, sizeof pr);
	i32 L = 1, R = 0;
	for (auto op : q) {
		while (L > q.l) addL(--L);
		while (L < q.l) decL(L++);
		while (R < q.r) addR(++R);
		while (R > q.r) decR(R--);
		res[q.id] = getRes();
	}
	for (i32 i = 1; i <= m; ++i) {
		printf("%ld\n", res[i]);
	}
	return 0;
}
