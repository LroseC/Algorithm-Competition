#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
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

const int N = 5e3 + 10;

i64 f[N];

int main(void)
{
	i32 n; read >> n;
	std::memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i <= n; ++i) {
		i32 v = i + 1;
		i32 w = i * (i + 1) / 2; 
		for (int j = n; j >= v; --j) {
			f[j] = std::min(f[j], f[j - v] + w);
		}
//		for (int j = 0; j <= n; ++j) {
//			printf("%lld ", f[j]);
//		}
//		puts("");
	}
	printf("%lld\n", f[n]);
	return 0;
}
