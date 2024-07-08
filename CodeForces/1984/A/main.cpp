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
	//I love MoRanSky FOREVER!
	std::ios::sync_with_stdio(false);
	i32 tt;
	read >> tt;
	while (tt--) {
		i32 n; read >> n;
		std::vector<i32> a(n);
		for (i32 i = 0; i < n; ++i) {
			read >> a[i];
		}
		if (a[0] == a[n - 1]) {
			puts("NO");
		} else {
			puts("YES");
			for (i32 i = 0; i < n - 2; ++i)
				putchar('R');
			putchar('B');
			puts("R");
		}
	}
	return 0;
}
