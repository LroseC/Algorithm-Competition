#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

void work(void)
{
	i64 l, r; read >> l >> r;
	auto getNex = [&](i32 i)->i32 {
		return (l - 1) / ((l - 1) / i);
	};
	i64 res = std::min(l - 1, r - l);
	for (i64 i = 1, j; i < l && i <= r - l; i = j + 1) {
		j = getNex(i);
		j = std::min(j, r - l);
		if ((l - 1) / i + 1 == r / j) {
			i64 k = std::max(i - 1, r / (r / j + 1));
			res -= j - k;
		}
	}
	if (r / 2 >= l) {
		res += (r / 2) - l + 1;
	}
	printf("%lld\n", res);
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
// 6 11
