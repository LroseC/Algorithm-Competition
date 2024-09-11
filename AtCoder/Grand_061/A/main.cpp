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

i32 C[10][10];

i32 get_C(i64 n, i64 m)
{
	if (n < 2 && m < 2) {
		return C[n][m];
	}
	return C[n % 2][m % 2] * get_C(n / 2, m / 2);
}

void work(void)
{
	i64 n, K; read >> n >> K;
	K -= 1;
	if ((n & 1) == 0) {
		i32 type = get_C(n / 2 - 1, K / 2);
		printf("%lld\n", (K ^ type) + 1);
	} else {
		if (K == 0) {
			printf("2\n");
		} else {
			i32 type = get_C(n / 2 - 1, (K - 1) / 2);
			K = ((K - 1) ^ type) + 1;
			printf("%lld\n", (K ^ get_C(n / 2 - 1, K / 2)) + 1);
		}
	}
}

int main(void)
{
	for (i32 i = 0; i < 2; ++i) {
		C[i][0] = 1;
		for (i32 j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] ^ C[i - 1][j];
		}
	}
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
/*
3658665565656 32323
 */
