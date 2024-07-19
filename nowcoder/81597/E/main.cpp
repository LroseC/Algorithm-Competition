#include <vector>
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
		i64 x; read >> x;
		if (x == 1) {
			std::cout << -1 << std::endl;
		} else {
			i64 lbit = x & -x;
			if (lbit == x) {
				std::cout << 1 << std::endl;
			} else {
				std::cout << (x ^ lbit) << std::endl;
			}
		}
	}
	return 0;
}
