#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

i32 gd[1010][1010];

i32 gcd(i32 a, i32 b)
{
	if (a == 0 || b == 0) return 0;
	if (a < b) return gcd(b, a);
	if (a == b) gd[a][b] = 1;
	if (gd[a][b] != -1) return gd[a][b];
	return gd[a][b] = gcd(a - b, b) + 1;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::memset(gd, -1, sizeof gd);
	i32 allmn = 0;
	for (int i = 2; i <= 1000; ++i) {
		i32 mn = 1e9;
		for (int j = 1; j <= i - j; ++j) {
			mn = std::min(mn, gcd(i - j, j));
		}
		printf("mn[%d] = %d\n", i, mn);
		allmn = std::max(allmn, mn);
	}
	printf("%d\n", allmn);
	return 0;
}
