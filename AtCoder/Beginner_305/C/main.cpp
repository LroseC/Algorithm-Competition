#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdint>

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

const i32 N = 510;

char G[N][N];

int main(void)
{
	//Think twice, code once? I'm back.
	i32 n, m;
	read >> n >> m;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", G[i] + 1);
	}
	i32 l = m, r = 1, u = n, d = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (G[i][j] == '#') {
				u = std::min(u, i);
				d = std::max(d, i);
				l = std::min(l, j);
				r = std::max(r, j);
			}
	for (int i = u; i <= d; ++i)
		for (int j = l; j <= r; ++j)
			if (G[i][j] == '.') {
				printf("%d %d\n", i, j);
				return 0;
			}
	return 0;
}
