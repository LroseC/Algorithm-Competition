#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 1e5 + 10;

i32 f[N];

void init(void)
{
	f[1] = 1, f[2] = 2, f[3] = 2, f[4] = 2;
	for (i32 i = 5; i < N; ++i) {
		i32 half = (i - 1) / 2;
		f[i] = 2 + 1 + f[half] - 2;
	}
}

void work(void)
{
	i32 n;
	read >> n;
	printf("%d\n", f[n]);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	init();
	while (tt--) {
		work();
	}
	return 0;
}
