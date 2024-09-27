#include <map>
#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
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
		i32 n, m;
		read >> n >> m;
		std::vector<i32> a(n);
		std::map<i64, i64> res;
		for (i32 i = 0; i < n; ++i) {
			read >> a[i];
			res[1ll * (i + 1) * (n - i) - 1] += 1;
		}
		for (i32 i = 1; i < n; ++i) {
			res[1ll * i * (n - i)] += a[i] - a[i - 1] - 1;
		}
		while (m--) {
			i64 k; read >> k;
			std::cout << res[k] << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
