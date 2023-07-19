#include <bits/stdc++.h>

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
} rd;

int main(void)
{
	int n; rd >> n;
	std::vector<int> val;
	for (int i = 1; i <= n; ++i) {
		i32 x; rd >> x;
		if (x % 2 == 0) val.emplace_back(x);
	}
	std::sort(val.begin(), val.end(), std::greater<i32>());
	int oddcnt = 0;
	int m; rd >> m;
	for (int i = 1; i <= m; ++i) {
		int x; rd >> x;
		if (x & 1) ++oddcnt;
	}
	i64 ans = 0;
	for (int v : val) {
		if (oddcnt) {
			oddcnt -= 1;
		}
		else {
			ans += v;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
