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
	i32 n;
	i64 K;
	read >> n >> K;
	if (n <= 60 && (1ll << n - 1) < K) {
		puts("-1");
		return;
	}
	std::vector<i32> a(n);
	i32 l = 0, r = n - 1;
	for (i32 i = 1, j = n - 1; i <= n; ++i, --j) {
		if (j - 1<= 60 && (1ll << j - 1) < K) {
			a[r] = i;
			r -= 1;
			K -= 1ll << j - 1;
		} else {
			a[l] = i;
			l += 1;
		}
	}
	for (i32 i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	puts("");
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
