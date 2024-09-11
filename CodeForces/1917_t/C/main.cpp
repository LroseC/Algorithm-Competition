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
	i32 n, K, d;
	read >> n >> K >> d;
	std::vector<i32> a(n + 1), v(K);
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
		a[i] -= i;
	}
	for (i32 i = 0; i < K; ++i)
		read >> v[i];
	i32 res = 0;
	i32 cnt = 0;
	for (i32 i = 1; i <= n; ++i)
		cnt += a[i] == 0;
	for (i32 i = 0; i <= std::min(n * 2, d - 1); ++i) {
		res = std::max(res, cnt + (d - i - 1) / 2);
		i32 pos = i % K;
		for (i32 j = 1; j <= v[pos]; ++j) {
			if (a[j] == 0) cnt -= 1;
			a[j] += 1;
			if (a[j] == 0) cnt += 1;
		}
	}
	printf("%d\n", res);
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
