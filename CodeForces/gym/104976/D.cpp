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
	printf("%d %d ", 2 * (n - 2) + 1, 2);
	for (i32 i = 2; i < n; ++i) {
		printf("%d %d ", -1, 2);
	}
	printf("%d %d\n", -1, 1);
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
