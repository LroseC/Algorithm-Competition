#include <vector>
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
	i32 n, P, Q;
	read >> n >> P >> Q;
	i32 mn = 0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) {
		i32 x; read >> x;
		mn = std::min(mn, x);
	}
	printf("%d\n", std::min(mn + Q, P));
	return 0;
}
