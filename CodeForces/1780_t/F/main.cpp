#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 3e5;

i32 n;
i32 bucket[N + 10], sign[N + 10];
i64 Sum[N + 10], Cnt[N + 10];
std::vector<i32> a;

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	read >> n;
	a.resize(n + 1);
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
	}
	std::sort(a.begin() + 1, a.end());
	for (i32 i = 1; i <= 3e5; ++i) {
		sign[i] = 1;
		i32 t = i;
		for (i32 j = 2; j * j <= t; ++j) {
			if (t % j == 0) {
				t /= j;
				sign[i] *= -1;
				while (t % j == 0) {
					t /= j;
					sign[i] *= 0;
				}
			}
		}
		if (t != 1) sign[i] *= -1;
	}
	i64 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		i64 cnt = 0, sum = 0;
		for (i32 j = 1; j * j <= a[i]; ++j) {
			auto calc = [&](i32 j)->void {
				cnt += Cnt[j] * sign[j];
				sum += Sum[j] * sign[j];
				Cnt[j] += 1;
				Sum[j] += i;
			};
			if (a[i] % j == 0) {
				calc(j);
				if (j * j != a[i]) {
					calc(a[i] / j);
				}
			}
		}
		res += 1ll * cnt * (i - 1) - sum;
	}
	printf("%lld\n", res);
	return 0;
}
