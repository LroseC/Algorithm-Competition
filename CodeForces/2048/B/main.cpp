#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n, K;
		read >> n >> K;
		std::vector<i32> res(n + 1);
		i32 j = 1;
		for (i32 i = K; i <= n; i += K, j += 1) {
			res[i] = j;
		}
		for (i32 i = 1; i <= n; ++i) {
			if (res[i] == 0) {
				res[i] = j;
				j += 1;
			}
		}
		for (i32 i = 1; i <= n; ++i) {
			printf("%d ", res[i]);
		}
		puts("");
	}
	return 0;
}
