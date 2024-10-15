#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

i64 sq(i32 x)
{
	return 1ll * x * x;
}

double get_dis(pii u, pii v)
{
	return sqrt(sq(u.first - v.first) + sq(u.second - v.second));
}

int main(void)
{
	std::ios::sync_with_stdio(false);

	i32 n;
	read >> n;

	pii origin = {0, 0};
	double res = 0;
	for (i32 i = 1; i <= n; ++i) {
		pii pos;
		read >> pos.first >> pos.second;
		res += get_dis(pos, origin);
		origin = pos;
	}
	res += get_dis(std::make_pair(0, 0), origin);
	printf("%.7lf\n", res);
	return 0;
}
