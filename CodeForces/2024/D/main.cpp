#include <queue>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstdint>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
using pli = std::pair<i64, i32>;
#define read std::cin

const int N = 4e5 + 10;

std::vector<i32> G[N];

void work(void)
{
	i32 n;
	read >> n;
	std::vector<i32> a(n), b(n);
	std::vector<i64> sum(n);
	std::vector<i64> f(n);
	for (i32 i = 0; i < n; ++i) {
		read >> a[i];
		sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
	}
	f[n - 1] = sum[n - 1];
	for (i32 i = 0; i < n; ++i) {
		read >> b[i];
		b[i] -= 1;
		G[b[i]].emplace_back(i);
	}
	std::priority_queue<pli> heap;
	for (i32 i = n - 2; i >= 0; --i) {
		for (auto v: G[i + 1]) {
			heap.emplace(f[i + 1] - a[v], v);
		}
		while (heap.size() && heap.top().second > i) {
			heap.pop();
		}
		f[i] = std::max(sum[i], heap.size() ? heap.top().first : 0);
	}
	printf("%lld\n", f[0]);
	for (i32 i = 0; i < n; ++i) {
		G[i].clear();
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
