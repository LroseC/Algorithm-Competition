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

const int N = 3e7 + 10;

i32 n;
char tstr[N], str[N];
i32 d[N];

int main(void)
{
	//Think twice, code once? I'm back.
	scanf("%s", tstr + 1);
	for (i32 i = 1; tstr[i]; ++i) {
		str[++n] = '#';
		str[++n] = tstr[i];
	}
	str[++n] = '#';
	i32 res = 0;
	for (i32 i = 1, r = 0, m = 0; i <= n; ++i) {
		if (r < i) {
			r = m = i;
		}
		else {
			d[i] = std::min(r - i + 1, d[2 * m - i]);
		}
		while (i - d[i] >= 1 && i + d[i] <= n && str[i - d[i]] == str[i + d[i]])
			++d[i];
		if (i + d[i] - 1 > r) {
			m = i;
			r = i + d[i] - 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		res = std::max(res, d[i] - 1);
	}
	printf("%d\n", res);
	return 0;
}
