#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 2e5 + 10;

i32 n, idx;
i32 w[N];
std::vector<i32> G[N];

void clear(void)
{
	idx = 0;
	for (i32 i = 1; i <= n; ++i) {
		G[i].clear();
	}
}

void dfs(i32 u, i32 fa)
{
	w[u] = ++idx;
	if (fa != 0) {
		if (std::abs(w[u] - w[fa]) != 1 && (w[u] - w[fa]) & 1) w[u] = ++idx;
		if (std::abs(w[u] - w[fa] == 2)) {
			idx += 2;
			w[u] = idx;
		}
	}
	for (i32 v: G[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
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
	dfs(1, 0);
	for (i32 i = 1; i <= n; ++i) {
		printf("%d ", w[i]);
	}
	puts("");
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
