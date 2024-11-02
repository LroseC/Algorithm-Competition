#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 3e5 + 10;

i32 n, m;
i32 a[N], b[N];
i64 sum[N], tsum[N], t[N];

pii calc_pos(i64 x)
{
	i32 l = 1, r = n;
	while (l <= r) {
		i32 mid = l + r >> 1;
		if (t[mid] < x) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
//	printf("x = %lld, (%d, %d)\n", x, l, i32(x - t[r] + l - 1));
	return std::make_pair(l, x - t[r] + l - 1);
}


int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		t[i] = n - i + 1;
		t[i] += t[i - 1];
	}
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
		b[i] = b[i - 1] + a[i];
		sum[i] = sum[i - 1] + b[i];
	}
	for (i32 i = 1; i <= n; ++i) {
		tsum[i] = sum[n] - sum[i - 1] - 1ll * (n - i + 1) * b[i - 1];
		tsum[i] += tsum[i - 1];
	}
	read >> m;
	while (m--) {
		i64 l, r;
		read >> l >> r;
		pii lpr = calc_pos(l);
		pii rpr = calc_pos(r);
		if (lpr.first == rpr.first) {
			printf("%lld\n", sum[rpr.second] - sum[lpr.second - 1] -
					1ll * (rpr.second - lpr.second + 1) * b[lpr.first - 1]);
		} else {
			i64 res = 0;
			res += sum[n] - sum[lpr.second - 1] - 
				1ll * (n - lpr.second + 1) * b[lpr.first - 1];
//			printf("%lld?\n", res);
			res += sum[rpr.second] - sum[rpr.first - 1] - 
				1ll * (rpr.second - rpr.first + 1) * b[rpr.first - 1];
//			printf("%lld??\n", res);
			res += tsum[rpr.first - 1] - tsum[lpr.first];
			printf("%lld\n", res);
		}
	}
	return 0;
}
