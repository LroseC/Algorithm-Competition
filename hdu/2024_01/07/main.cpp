#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> x[i];
	}
	for (i32 i = 1; i <= n; ++i) {
		read >> y[i];
	}
	i64 res = 0;
	for (i32 k = 2; k < n; ++k) {
	}
	return 0;
}
