#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
using pii = std::pair<i32, i32>;
#define read std::cin

const int mod = 998244353;
const int N = 256;

struct ModInt
{
	i32 val;
	ModInt(void) { val = 0; }
	ModInt(i32 x) { val = x; }
	ModInt operator+(const ModInt &other) const
	{
		i32 v = val + other.val;
		return ModInt(v >= mod ? v - mod : v);
	}
	ModInt operator-(const ModInt &other) const
	{
		i32 v = val - other.val + mod;
		return ModInt(v >= mod ? v - mod : v);
	}
	ModInt operator*(const ModInt &other) const
	{
		return ModInt(1ll * val * other.val % mod);
	}
	void operator+=(const ModInt &other)
	{
		val += other.val;
		val = val >= mod ? val - mod : val;
	}
	void operator-=(const ModInt &other)
	{
		val += mod - other.val;
		val = val >= mod ? val - mod : val;
	}
	void operator*=(const ModInt &other)
	{
		val = 1ll * val * other.val % mod;
	}
};


ModInt qpow(ModInt base, i32 k)
{
	ModInt res(1);
	while (k) {
		if (k & 1) res *= base;
		k >>= 1;
		base *= base;
	}
	return res;
}
ModInt get_inv(ModInt x)
{
	return qpow(x, mod - 2);
}

ModInt sq(ModInt x) { return x * x; }

i32 n, arr[N];
ModInt f[N][N][N], sum[N][N][N];

ModInt calc(void)
{
	f[0][0][0] = 1;
	for (i32 i = 0; i <= n; ++i)
		for (i32 j = 0; j <= n; ++j) {
			sum[0][i][j] = sum[i][0][j] = sum[i][j][0] = 1;
		}
	for (i32 i = 1; i <= n; ++i)
		for (i32 j = 1; j <= n; ++j)
			for (i32 k = 1; k <= n; ++k) {
				sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1];
				sum[i][j][k] -= sum[i - 1][j - 1][k] + sum[i - 1][j][k - 1] + sum[i][j - 1][k - 1];
				sum[i][j][k] += sum[i - 1][j - 1][k - 1];
				if (arr[i] == arr[j] && arr[j] == arr[k])
					f[i][j][k] = sum[i - 1][j - 1][k - 1];
				sum[i][j][k] += f[i][j][k];
			}
//	for (i32 i = 0; i <= n; ++i)
//		for (i32 j = 0; j <= n; ++j)
//			for (i32 k = 0; k <= n; ++k) {
//				printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k].val);
//				printf("sum[%d][%d][%d] = %d\n", i, j, k, sum[i][j][k].val);
//			}
	return sum[n][n][n] - 1;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> arr[i];
	}
	std::cout << calc().val << std::endl;
	return 0;
}
