#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

i32 sign(i32 x)
{
	if (x == 0) return 0;
	return x < 0 ? -1 : 1;
}

void work(void)
{
	i32 n; read >> n;
	std::vector<i32> a(n);
	i32 res = 1;
	for (i32 i = 0; i < n; ++i) {
		read >> a[i];
		res *= sign(a[i]);
	}
	if (res <= 0) {
		puts("0");
	}
	else {
		puts("1");
		puts("1 0");
	}
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) work();
	return 0;
}
