#include <set>
#include <string>
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

int main(void)
{
	//Think twice, code once? I'm back.
	std::ios::sync_with_stdio(false);
	i32 tt; std::cin >> tt;
	std::set<std::string> mp;
	i32 cnt = 0;
	while (tt--) {
		std::string s;
		std::cin >> s;
		bool flg = 0;
		if (mp.find(s) == mp.end()) {
			++cnt;
			mp.insert(s);
			std::reverse(s.begin(), s.end());
			mp.insert(s);
		}
	}
	printf("%ld\n", cnt);
	return 0;
}
