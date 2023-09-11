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
	read >> n;
	for (i32 i = 1; i <= n; ++i)
		read >> a[i];
	std::sort(a + 1, a + 1 + n);
	for (i32 k = 0; k < 31; ++k) {
		for (i32 i = 1; i <= n; ++i)
			val[i] = (a[i] >> k) & 1;
		for (i32 i = 1; i <= n; ++i)
			sum1[i] = 
	}
	return 0;
}
