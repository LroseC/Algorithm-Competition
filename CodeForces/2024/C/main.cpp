#include <vector>
#include <cstdio>
#include <cctype>
#include <cstdint>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

void work(void)
{
	i32 n;
	read >> n;
	std::vector<pii> arr(n);
	for (i32 i = 0; i < n; ++i) {
		read >> arr[i].first >> arr[i].second;
	}
	std::sort(arr.begin(), arr.end(), [](pii a, pii b) {
			if (std::min(a.first, a.second) == std::min(b.first, b.second)) {
				return  std::max(a.first, a.second) < std::max(b.first, b.second);
			}
			return std::min(a.first, a.second) < std::min(b.first, b.second);
		});
	for (i32 i = 0; i < n; ++i) {
		printf("%d %d ", arr[i].first, arr[i].second);
	}
	puts("");
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt;
	read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
