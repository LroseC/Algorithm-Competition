#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

int main(void)
{
	//I love MoRanSky FOREVER!
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n; read >> n;
		std::vector<i32> arr(n);
		std::vector<i64> presum(n);
		for (i32 i = 0; i < n; ++i) {
			read >> arr[i];
		}
		presum[0] = arr[0];
		for (i32 i = 1; i < n; ++i) {
			presum[i] = presum[i - 1] + arr[i];
		}
		presum[0] = std::abs(presum[0]);
		for (i32 i = 1; i < n; ++i) {
			presum[i] = std::abs(presum[i]);
			presum[i] = std::max(presum[i], presum[i - 1] + arr[i]);
		}
		printf("%lld\n", presum[n - 1]);
	}
	return 0;
}
