#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cassert>
#include <iostream>
#include <algorithm>

#define int long long
using i32 = long long;
using i64 = long long;
using u64 = long long;
#define read std::cin

i64 P, m;
int test = 0;
i64 search_l(i64 L)
{
	return L <= 1 ? 0 : (L - 2) / P + 1;
	i64 l = 0, r = 2e18 / P;
	while (l <= r) {
		i64 mid = l + r >> 1;
		if (mid * P + 1 >= L) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	assert(l == (L <= 1 ? 0 : (L - 2) / P + 1));
//	if (l != (L - 2) / P + 1) {
//		printf("L = %lld\n", L);
//		printf("l = %lld, ll = %lld\n", l, (L - 2) / P + 1);
//	}
	return l;
}
i64 search_r(i64 R)
{
	return (R <= 0 ? -1 : (R - 1) / P);
	i64 l = 0, r = 2e18 / P;
	while (l <= r) {
		i64 mid = l + r >> 1;
		if (mid * P + 1 <= R) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
//	if (r != (R <= 1 ? 0 : (R - 1) / P)) {
//		printf("test = %d\n", test);
//		printf("R = %lld, P = %lld, r = %lld, rr = %lld\n", R, P, r, (R - 1) / P);
//		fflush(stdout);
//	}
	assert(r == (R <= 1 ? 0 : (R - 1) / P));
	return r;
}

signed main(void)
{
	std::ios::sync_with_stdio(false);
	int tt; read >> tt;
	while (tt--) {
		test += 1;
		read >> P >> m;
//		std::cout << P << ' ' << m << std::endl;
		i64 L = 0, R;
		i64 res = 0;
		for (int k = 62; k >= 0; --k) {
			if (m >> k & 1) {
				i32 Lp = L ^ ((((P - 1) >> k) & 1) << k);
				R = Lp + ((1ll << k) - 1);
				i32 l = search_l(Lp);
				i32 r = search_r(R);
				if (l <= r) {
					res += (r - l + 1);
				}

//				printf("3L = %lld\n", L);
//				printf("k = %d\n", k);
				L ^= (((long long)!(((P - 1) >> k) & 1)) << k);
//				printf("4L = %lld\n", L);
			} else {
//				printf("1L = %lld\n", L);
				L ^= ((P - 1 >> k & 1) << k);
//				printf("2L = %lld\n", L);
			}
//			printf("L = %lld\n", L);
		}
		i32 l = search_l(L);
		if (l * P + 1 == L) {
			res += 1;
		}
		printf("%lld\n", res);
	}
	return 0;
}

