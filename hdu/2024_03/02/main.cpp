#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

void work(void)
{
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> c[i];
	}
	for (i32 i = 1; i <= n; ++i) {
		read >> w[i];
	}
	for (i32 i = 1; i < n; ++i) {
		i32 u, v; read >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		clear();
		work();
	}
	return 0;
}
