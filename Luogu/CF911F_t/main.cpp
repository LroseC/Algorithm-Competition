#include <cctype>
#include <cstdio>
#include <cstdint>
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

int main(void)
{
	//Think twice, code once? I'm back.
	i32 n; read >> n;
	for (i32 i = 1; i < n; ++i) {
		i32 u, v;
		read >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	return 0;
}
