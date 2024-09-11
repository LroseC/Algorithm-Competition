#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

i32 n, m;

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	read >> n >> m;
	std::vector<i32> a(n);
	for (i32 i = 0; i < n; ++i) read >> a[i];
	std::sort(a.begin() + 2, a.begin() + n);
	i64 res = 1e10;
	for (i32 i = 2, j = i + m - 1; j < n; ++i, ++j) {
		i64 tres = 0;
		tres += std::max(0, a[0] - a[i]);
		tres += std::max(0, a[j] - a[1]);
		res = std::min(res, tres);
	}
	printf("%lld\n", res);
	return 0;
}
