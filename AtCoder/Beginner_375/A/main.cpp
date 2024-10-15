#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 2e5 + 10;

char str[N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	read >> n;
	read >> str;
	i32 res = 0;
	for (i32 i = 1; i < n - 1; ++i) {
		if (str[i] == '.' && str[i - 1] == '#' && str[i + 1] == '#') {
			res += 1;
		}
	}
	printf("%d\n", res);
	return 0;
}
