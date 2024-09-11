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

i32 pop_count(i64 x)
{
	i32 res = 0;
	for (i32 i = 0; i < 64; ++i)
		if (x >> i & 1) res += 1;
	return res;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i64 n; read >> n;
		i32 res = pop_count(n) + 1;
		if (res == 2) {
			printf("1\n%lld\n", n);
		} else {
			printf("%d\n", res = pop_count(n) + 1);
			for (int i = 63; i >= 0; --i) {
				if (n >> i & 1) {
					printf("%lld ", n ^ (1ll << i));
				}
			}
			printf("%lld\n", n);
		}
	}
	return 0;
}
