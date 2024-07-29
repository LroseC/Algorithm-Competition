#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n, L, D; read >> n >> L >> D;
		std::vector<i32> arr(n);
		for (i32 i = 0; i < n; ++i) {
			read >> arr[i];
		}
		std::sort(arr.begin() + 1, arr.end());
		if (arr[0] >= L) {
			if (arr[0] - arr[1] > D && arr[3] < L) {
				puts("Yes");
			} else {
				puts("No");
			}
		} else {
			if ((arr[n - 1] - std::min(arr[0], arr[1]) > D) && arr[2] < L) {
				puts("Yes");
			} else {
				puts("No");
			}
		}
	}
	return 0;
}
