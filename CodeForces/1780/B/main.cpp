#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

i64 gcd(i64 a, i64 b)
{
	if (a > b) std::swap(a, b);
	return a ? gcd(b % a, a) : b;
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n; read >> n;
		std::vector<i32> arr(n + 1);
		std::vector<i64> preSum(n + 1);
		for (i32 i = 1; i <= n; ++i) {
			read >> arr[i];
		}
		for (i32 i = 1; i <= n; ++i) {
			preSum[i] = preSum[i - 1] + arr[i];
		}
		i64 res = 0;
		for (i32 i = 1; i < n; ++i) {
			res = std::max(res, gcd(preSum[i], preSum[n] - preSum[i]));
		}
		printf("%lld\n", res);
	}
	return 0;
}
