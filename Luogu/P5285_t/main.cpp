#include <string>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;

#define read std::cin

namespace task1
{
	const int mod = 998244353;
	i32 pw[100][10];

	void init(void)
	{
		pw[0][1] = 19;
		for (i32 i = 0; i <= 50; ++i) {
			pw[i][0] = 1;
			for (i32 j = 1; j < 10; ++j)
				pw[i][j] = 1ll * pw[i][j - 1] * pw[i][1] % mod;
			pw[i + 1][1] = 1ll * pw[i][9] * pw[i][1] % mod;
		}
	}
	i32 main(void)
	{
		init();
		i32 tt; read >> tt;
		while (tt--) {
			i32 res = 1;
			std::string num;
			std::cin >> num;
			std::reverse(num.begin(), num.end());
			for (i32 i = 0; i < num.size(); ++i) {
				res = 1ll * res * pw[i][num[i] - '0'] % mod;
			}
			std::cout << res << '\n';
		}
		return 0;
	}
}

i32 getType(void)
{
	std::string s;
	read >> s;
	if (s == "1_998244353") return 1;
	if (s == "1wa_998244353") return 2;
	return -1;
}

int main(void)
{
	//Think twice, code once? I'm back.
	std::ios::sync_with_stdio(false);
	i32 _TYPE = getType();
	if (_TYPE == 1) task1::main(_TYPE);
	return 0;
}
