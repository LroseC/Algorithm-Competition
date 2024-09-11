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
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n; read >> n;
		bool fail = 0;
		bool flag = 0;
		for (i32 i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				flag = 1;
				while (n % i == 0)
					n /= i;
				if (n == 1)
					fail = 1;
				break;
			}
		}
		if (!flag) fail = 1;
		puts(fail ? "No" : "Yes");
	}
	return 0;
}
