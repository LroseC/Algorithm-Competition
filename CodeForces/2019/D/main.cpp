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

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt;
	read >> tt;
	while (tt--) {
		i32 n; read >> n;
		std::priority_queue<pii> heap;
		std::vector<i32> a(n + 1);
		std::vector<i32> pre(n + 1), nex(n + 1);
		std::vector<i32> sum(n + 1);
		for (i32 i = 1; i <= n; ++i) {
			read >> a[i];
			heap.emplace(a[i], i);
		}
		for (i32 i = 1; i <= n; ++i) {
			pre[i] = i - 1;
			nex[i] = i + 1;
		}
		pre[1] = 0;
		nex[n] = 0;
		nex[0] = 1;
		pre[0] = n;
		bool fail = 0;
		for (i32 i = n; i >= 1; --i) {
			while (heap.size() && heap.top().first > i) {
				i32 pos = heap.top().second;
				heap.pop();
				nex[pre[pos]] = nex[pos];
				pre[nex[pos]] = pre[pos];
			}
			i32 l = nex[0], r = pre[0];
			if (l == 0 && r == 0) continue;
			if (r - l + 1 > i) fail = 1;
			i32 seg_l = std::max(1, r - i + 1), seg_r = std::min(n, l + i - 1);
			sum[1] -= 1;
			sum[seg_l] += 1;
			if (seg_r != n) {
				sum[seg_r + 1] -= 1;
			}
		}
		sum[1] += 1;
		i32 res = 0;
		for (i32 i = 1; i <= n; ++i) {
			sum[i] += sum[i - 1];
			if (sum[i] == 1) res += 1;
		}
		std::cout << (fail ? 0 : res) << std::endl;
	}
	return 0;
}
