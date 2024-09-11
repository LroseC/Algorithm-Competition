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

void shuffle(i32 l, i32 r, i32 a[])
{
	if (r == l + 1) {
		std::swap(a[l], a[r]);
		return;
	}
	shuffle(l, r - 1, a);
	shuffle(l + 1, r, a);
}

i32 a[10010];

int main(void)
{
	std::ios::sync_with_stdio(false);
	for (i32 n = 3; n <= 100; n += 2) {
		for (i32 i = 0; i < n; ++i) {
			a[i] = i + 1;
		}
		shuffle(0, n - 1, a);
		for (i32 i = 0; i < n; ++i) {
			printf("%2d ", a[i]);
		}
		puts("");
	}
	return 0;
}
