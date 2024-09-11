#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

void work(void)
{
	i32 n, m;
	read >> n >> m;
	printf("%d\n", std::min(n, m - 1) + (m != 1));
	for (i32 i = 0; i < n; ++i) {
		if (i + 1 < m) {
			for (i32 j = 0; j <= i; ++j)
				printf("%d ", m - i + j - 1);
			for (i32 j = i + 1; j < m; ++j)
				printf("%d ", j - i - 1);
		}
		else {
			for (i32 j = 1; j < m; ++j)
				printf("%d ", j);
			printf("0 ");
		}
		puts("");
	}
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
