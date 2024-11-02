#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

void work(void)
{
	i32 x, y, K;
	read >> x >> y >> K;
	i32 m = std::min(x, y);
	printf("%d %d %d %d\n", 0, 0, m, m);
	printf("%d %d %d %d\n", 0, m, m, 0);
}
void clear(void) {}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	return 0;
}
