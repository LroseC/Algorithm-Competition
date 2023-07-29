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
	std::ios::sync_with_stdio(false);
	i32 n;
	read >> n;
	std::vector<std::pair<i32, i32>> v(n);
	for (int i = 0; i < n; ++i) {
		read >> v[i].first;
		v[i].second = i + 1;
	}
	std::sort(v.begin(), v.end());
	i32 l = 0, r = n - 1;
	while (l < r) {
		i32 mid = (v[l].first + v[r].first) >> 1;
		auto t = std::lower_bound(v.begin(), v.end(), std::make_pair(mid, n + 1));
		i32 x = t - v.begin() - l;
		i32 y = r - l + 1 - x;
		if (x >= y) {
			r -= 1;
		}
		else {
			l += 1;
		}
	}
	printf("%d\n", v[l].second);
	return 0;
}
