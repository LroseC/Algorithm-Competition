#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 64;

i32 n, m;
i32 vis[N];
std::vector<i32> G[N];

i32 dfs(i32 u)
{
	std::vector<i32> vec;
	for (auto v : G[u]) {
		if (vis[v] != 1) {
			vec.emplace_back(v);
			vis[v] = 1;
		}
	}
	i32 res = 0;
	for (auto v : vec) {
		res = std::max(res, dfs(v));
	}
	for (auto v : vec) {
		vis[v] = 0;
	}
	return res + 1;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> m;
	for (i32 i = 1; i <= m; ++i) {
		i32 u, v; read >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	i32 res = 1;
	for (i32 i = 1; i <= n; ++i) {
		vis[i] = 1;
		res = std::max(res, dfs(i));
		vis[i] = 0;
	}
	std::cout << res << std::endl;
	return 0;
}
