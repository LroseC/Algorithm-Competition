#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

void work(void)
{
	i32 n;
	read >> n;
	i64 sum = 0;
	for (i32 i = 0; i < n; ++i) {
		i32 x; read >> x;
		sum += x;
	}
	printf("%.18Lf\n", (long double)sum / n);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
