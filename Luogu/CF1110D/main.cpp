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

const int N = 1e6 + 10;

i32 n, m;
i32 cnt[N];
i32 f[N][3][3];

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m;
	for (int i = 1; i <= n; ++i) {
		i32 val; read >> val;
		cnt[val] += 1;
	}
	for (int i = 1; i <= m; ++i)
		for (int a = 0; a < 3; ++a)
			for (int b = 0; b < 3; ++b)
				for (int k = 0; k < 3; ++k) {
					i32 num = cnt[i] - a - b - k;
					if (num < 0) continue;
					f[i + 1][b][k] = std::max(f[i + 1][b][k], f[i][a][b] + k + num / 3);
				}
	printf("%d\n", f[m + 1][0][0]);
	return 0;
}
