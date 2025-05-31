#include <vector>
#include <cctype>
#include <cstdio>
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
		i32 n;
		read >> n;
		std::vector<i32> a(n);
		i32 cnt[2] = {0, 0};
		i32 max = 0;
		i64 sum = 0;
		for (i32 i = 0; i < n; ++i) {
			read >> a[i];
			max = std::max(max, a[i]);
			sum += a[i];
			cnt[a[i] & 1] += 1;
		}
		if (cnt[0] && cnt[1]) {
			printf("%lld\n", sum - cnt[1] + 1);
		} else {
			printf("%d\n", max);
		}
	}
	return 0;
}
