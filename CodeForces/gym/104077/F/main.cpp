#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 n, sg, db;
	read >> n >> sg >> db;
	sg = std::min(sg, db);
	db = std::min(sg * 2, db);
	i64 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		char str[10]; read >> str;
		bool same = (str[0] == str[1] || str[0] == str[2] || str[1] == str[2]);
		if (same) res += db + sg;
		else res += sg * 3;
	}
	std::cout << res << std::endl;
	return 0;
}
