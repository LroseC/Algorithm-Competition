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

const int N = 1e3 + 10;

i32 p[N];

int main(void)
{
	//Think twice, code once. I'm back.
	i32 tt; read >> tt;
	while (tt--) {
		i32 n, res = 0;
		read >> n;
		for (int i = 1; i <= n; ++i) {
			read >> p[i];
		}
		for (int i = 1; i <= n; ++i) {
			i32 t = 1;
			for (int j = i + 1; j <= n; ++j) {
				if (p[j] < p[i]) t = 0;
			}
			res += t;
		}
		printf("%d\n", res);
	}
	return 0;
}
