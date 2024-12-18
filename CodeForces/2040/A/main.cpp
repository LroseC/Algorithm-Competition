#include <vector>
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
	i32 n, K;
	read >> n >> K;
	std::vector<i32> a(n);
	for (i32 i = 0; i < n; ++i) {
		read >> a[i];
	}
	for (i32 i = 0; i < n; ++i) {
		bool sec = 1;
		for (i32 j = 0; j < n; ++j) {
			if (i == j) continue;
			if (a[i] % K == a[j] % K)
				sec = 0;
		}
		if (sec) {
			puts("YES");
			printf("%d\n", i + 1);
			return;
		}
	}
	puts("NO");
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
