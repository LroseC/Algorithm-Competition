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

const int N = 1e6 + 10;

char str[N];

int main(void)
{
	//Think twice, code once? I'm back.
	i32 n;
	read >> n;
	scanf("%s", str + 1);
	i32 cnt0 = 0, cnt1 = 0;
	i64 ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (str[i] == '1') {
			ans += cnt0 + 1;
			std::swap(cnt0, cnt1);
			cnt1 += 1;
		}
		else {
			ans += cnt1 + cnt0;
			cnt1 += cnt0;
			cnt0 = 0;
			cnt0 += 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
