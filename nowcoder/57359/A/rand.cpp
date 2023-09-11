#include <random>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

std::random_device srd;

i32 n = 5e5, m = 5e5;

int main(void)
{
	srand(srd());
	std::ios::sync_with_stdio(false);
	printf("%d %d\n", n, m);
	for (i32 i = 1; i <= n; ++i) {
		printf("%d ", rand() % n + 1);
	}
	puts("");
	for (i32 i = 1; i <= n; ++i) {
		i32 l = rand() % n + 1, r = rand() % n + 1;
		if (l > r) std::swap(l, r);
		printf("%d %d\n", l, r);
	}
	return 0;
}
