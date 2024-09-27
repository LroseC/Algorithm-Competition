#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
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
		i32 n;
		i64 m;
		read >> n >> m;
		std::vector<i64> a(n);
		i64 max = 0;
		i64 sum = 0;
		for (i32 i = 0; i < n; ++i) {
			read >> a[i];
			max = std::max(a[i], max);
			sum += a[i];
		}
		i32 res = 0;
		for (i32 i = 1; i <= n; ++i) {
			bool sec = 1;
			double l = 1.0 * sum / i;
			i64 r = (sum + m) / i;
			if (r >= l && r >= max) {
				sec = 1;
			} else {
				sec = 0;
			}
			if (sec) res = i;
		}
		printf("%d\n", res);
	}
	return 0;
}
