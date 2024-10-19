#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 100;

i32 n;
std::vector<i32> G[N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i < n; ++i) {
		i32 u, v;
		read >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	i32 cnt = 0;
	for (i32 i = 1; i <= n; ++i) {
		cnt += G[i].size() != 1;
	}
	if (cnt == 0) {
		puts("Bob");
		return 0;
	}
	puts(cnt % 2 ? "Bob" : "Alice");
	return 0;
}
