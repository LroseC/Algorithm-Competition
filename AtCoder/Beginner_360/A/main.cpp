#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	char str[10];
	scanf("%s", str);
	i32 p1, p2;
	for (int i = 0; i < 3; ++i) {
		if (str[i] == 'R') p1 = i;
		if (str[i] == 'M') p2 = i;
	}
	puts(p1 < p2 ? "Yes" : "No");
	return 0;
}
