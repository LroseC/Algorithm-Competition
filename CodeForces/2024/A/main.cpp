#include <vector>
#include <cstdio>
#include <cctype>
#include <cstdint>
#include <cstring>
#include <climits>
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
		i32 a, b;
		read >> a >> b;
		if (a >= b) {
			printf("%d\n", a);
		} else {
			printf("%d\n", std::max(a * 2 - b, 0));
		}
	}
	return 0;
}
