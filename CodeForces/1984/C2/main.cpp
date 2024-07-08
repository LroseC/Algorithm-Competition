#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int mod = 998244353;

struct ModInt
{
	i32 val;

	ModInt() { val = 0; }
	ModInt(i32 x) { val = x; }
	void operator+=(const ModInt &other) {
		val = (val + other.val) % mod;
	}
};
ModInt operator*(const ModInt &a, const ModInt &b) {
	return ModInt(1ll * a.val * b.val % mod);
}

int main(void)
{
	//I love MoRanSky FOREVER!
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n; read >> n;
		std::vector<i32> arr(n + 1);
		std::vector<i64> min(n + 1), max(n + 1);
		std::vector<ModInt> fmin(n + 1), fmax(n + 1);
		for (i32 i = 1; i <= n; ++i) {
			read >> arr[i];
		}
		fmin[0] = fmax[0] = ModInt(1);
		min[0] = max[0] = arr[0];
		for (i32 i = 1; i <= n; ++i) {
			min[i] = min[i - 1] + arr[i];
			fmin[i] = fmin[i - 1];
			if (std::abs(min[i - 1] + arr[i]) == min[i]) {
				fmin[i] = fmin[i] * ModInt(2);
			}
			max[i] = std::abs(max[i - 1] + arr[i]);
			max[i] = std::max(std::abs(min[i - 1] + arr[i]), max[i]);
			if (max[i] == std::abs(min[i - 1] + arr[i])) {
				fmax[i] += fmin[i - 1];
			}
			if (max[i] == max[i - 1] + arr[i]) {
				fmax[i] += fmax[i - 1];
			}
			if (max[i] == std::abs(max[i - 1] + arr[i]) && min[i - 1] != max[i - 1]) {
				fmax[i] += fmax[i - 1];
			}
		}
		printf("%d\n", fmax[n].val);
	}
	return 0;
}
