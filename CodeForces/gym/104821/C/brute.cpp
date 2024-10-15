#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = long long;
using i64 = long long;
using u64 = long long;
#define read std::cin

i64 P, m;
i64 search_l(i64 L)
{
	i64 l = 0, r = 2e18 / P;
	while (l <= r) {
		i64 mid = l + r >> 1;
		if (mid * P + 1 >= L) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
i64 search_r(i64 R)
{
	i64 l = 0, r = 2e18 / P;
	while (l <= r) {
		i64 mid = l + r >> 1;
		if (mid * P + 1 <= R) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return r;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	int tt; read >> tt;
	while (tt--) {
		read >> P >> m;
		i64 L = 0, R;
		i64 res = 0;
		for (int k = 63; k >= 0; --k) {
			if (m >> k & 1) {
				i32 Lp = L ^ ((P - 1 >> k & 1) << k);
				R = Lp + (1ll << k) - 1;
				i32 l = search_l(Lp);
				i32 r = search_r(R);
				if (l <= r) {
					res += (r - l + 1);
				}

				L ^= ((1ll * (!(P - 1 >> k & 1))) << k);
			} else {
				L ^= ((P - 1 >> k & 1) << k);
			}
		}
		i32 l = search_l(L);
		i32 r = search_r(L);
		if (l * P + 1 == L) {
			res += 1;
		}
//		if (l <= r) {
//			res += r - l + 1;
//		}
		printf("%lld\n", res);
	}
	return 0;
}
