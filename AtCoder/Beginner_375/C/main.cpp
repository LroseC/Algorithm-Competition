#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 3010;

char G[N][N], res[N][N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> G[i] + 1;
	}
	for (i32 i = 1; i * 2 <= n; ++i) {
		for (i32 j = 0; j < i * 2 - 1; ++j) {
		}
	}
	return 0;
}
