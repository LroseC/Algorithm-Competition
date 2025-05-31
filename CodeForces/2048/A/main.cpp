#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 x; read >> x;
		puts(x % 33 ? "NO" : "YES");
	}
	return 0;
}
