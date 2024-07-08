#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 n;
	read >> n;
	std::vector<i32> pos(n);
	std::vector<i32> w(n);
	std::vector<std::vector<i32>> arr(n);
	for (i32 i = 0; i < n; ++i) {
		read >> pos[i];
		arr[pos[i] - 1].emplace_back(i);
	}
	for (i32 i = 0; i < n; ++i) {
		read >> w[i];
	}
	i64 res = 0;
	for (i32 i = 0; i < n; ++i) {
		i32 max = 0;
		i64 sum = 0;
		if (arr[i].size() > 1) {
			for (auto j : arr[i]) {
				sum += w[j];
				max = std::max(max, w[j]);
			}
		}
		res += sum - max;
	}
	std::cout << res << std::endl;
	return 0;
}
