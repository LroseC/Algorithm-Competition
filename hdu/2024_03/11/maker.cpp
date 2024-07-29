#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

i32 myrand(i32 l, i32 r)
{
	return l + rand() % (r - l + 1);
}
char n2c(i32 x)
{
	if (x == 0) {
		return 'E';
	} else if (x == 1) {
		return 'W';
	} else if (x == 2) {
		return 'S';
	}
	return 'N';
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	srand(time(NULL));
	i32 n = 10;
	std::cout << n << std::endl;
	for (i32 i = 1; i <= n; ++i) {
		std::cout << myrand(-100, 100) << ' ' << myrand(-100, 100) << ' ' << n2c(rand() % 4) << std::endl;
	}
	return 0;
}
