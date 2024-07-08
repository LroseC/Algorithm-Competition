#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int mod = 998244353;

struct ModInt
{
	i32 val;
	ModInt(void) { val = 0; }
	ModInt(i32 v) { val = v; }

	ModInt operator+(const ModInt &other) const
	{
		i32 x = val + other.val;
		return x >= mod ? x - mod : x;
	}
	ModInt operator-(const ModInt &other) const
	{
		i32 x = val - other.val;
		return x < 0 ? x + mod : x;
	}
	ModInt operator*(const ModInt &other) const
	{
		return 1ll * val * other.val % mod;
	}
};

ModInt qpow(ModInt base, i32 k)
{
	ModInt res(1);
	while (k) {
		if (k & 1) res = res * base;
		base = base * base;
		k >>= 1;
	}
	return res;
}

ModInt get_inv(ModInt x)
{
	return qpow(x, mod - 2);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 n, K; read >> n >> K;
	auto res = qpow(ModInt(1ll * (n - 2) * n % mod) * get_inv(1ll * n * n % mod), K);
	res = res + (ModInt(1) - res) * ModInt(n + 1) * get_inv(2);
	printf("%d\n", res.val);
	return 0;
}
