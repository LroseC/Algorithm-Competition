#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 5e5 + 10;

int n;
i32 dep[N], max_dep[N];
std::vector<i32> G[N];
i32 sum_sub[N], sum_edge[N];

void clear(void)
{
	for (i32 i = 1; i <= n; ++i) G[i].clear();
	std::fill(sum_sub, sum_sub + 2 + n, 0);
	std::fill(sum_edge, sum_edge + 2 + n, 0);
}

void dfs(i32 u, i32 fa, i32 d)
{
	dep[u] = d;
	max_dep[u] = d;
	for (auto v: G[u]) {
		if (v == fa) continue;
		dfs(v, u, d + 1);
		max_dep[u] = std::max(max_dep[u], max_dep[v]);
	}
	sum_sub[max_dep[u]] += 1;
	sum_edge[dep[u]] += 1;
}

void work(void)
{
	read >> n;
	for (i32 i = 1; i < n; ++i) {
		i32 u, v;
		read >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1, 1, 0);
	sum_sub[0] = sum_edge[0] = 0;
	for (i32 i = 1; i <= n; ++i) {
		sum_sub[i] += sum_sub[i - 1];
	}
	for (i32 i = n; i >= 1; --i) {
		sum_edge[i] += sum_edge[i + 1];
	}
	i32 res = n - 1;
	for (i32 i = 1; i <= n; ++i) {
		res = std::min(res, sum_sub[i - 1] + sum_edge[i + 1]);
	}
	printf("%d\n", res);
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
