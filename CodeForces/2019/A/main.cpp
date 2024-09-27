#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
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
		std::vector<i32> a(n);
		for (i32 i = 0; i < n; ++i) {
			read >> a[i];
		}
		i32 res1 = 0, res2 = 0;
		i32 tmp1 = 0, tmp2 = 0;
		for (i32 i = 0; i < n; i += 2) {
			res1 = std::max(res1, a[i]);
			tmp1 += 1;
		}
		for (i32 i = 1; i < n; i += 2) {
			res2 = std::max(res2, a[i]);
			tmp2 += 1;
		}
		res1 += tmp1;
		res2 += tmp2;
		std::cout << (std::max(res1, res2)) << std::endl;
	}
	return 0;
}
