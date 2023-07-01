#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

struct FSI
{
	template<typename T>
	FSI& operator>>(T &res)
	{
		res = 0; T f = 1; char ch = getchar();
		while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
		while (isdigit(ch)) { res = res * 10 + (ch - '0') * f; ch = getchar(); }
		return *this;
	}
} read;

const int N = 110;

i32 n, m;
bool vis[N];

void dfs(i32 u, i32 fa)
{
	vis[u] = 1;
	if (u == n) exit(0);
	i32 k;
	read >> k;
	std::vector<i32> to;
	for (i32 i = 1; i <= k; ++i) {
		i32 v; read >> v; to.emplace_back(v);
	}
	for (i32 v : to)
		if (!vis[v]) {
			std::cout << v << std::endl;
			dfs(v, u);
			read >> k;
			for (int i = 1; i <= k; ++i) { i32 t; read >> t; }
		}
	std::cout << fa << std::endl;
	return;
}

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m;
	dfs(1, 1);
	return 0;
}
