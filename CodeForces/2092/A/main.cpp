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
		int n;
		read >> n;
		std::vector<i32> a(n);
		for (i32 i = 0; i < n; ++i) {
			read >> a[i];
		}
		i32 res = 0;
		for (i32 i = 0; i < n; ++i) {
			for (i32 j = 0; j < n; ++j) {
				res = std::max(res, std::abs(a[i] - a[j]));
			}
		}
		std::cout << res << std::endl;
	}
	return 0;
}
