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

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n, K; read >> n >> K;
		std::cout << (n - 1) / (K - 1) + ((n - 1) % (K - 1) != 0) << std::endl;
	}
	return 0;
}
