#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int mod = 998244353;

i32 mod_add(i32 x, i32 y)
{
	x += y;
	return x >= mod ? x - mod : x;
}
struct ModInt
{
	i32 val;
	ModInt(void) { val = 0; }
	ModInt(i32 x) { val = x; }

	friend ModInt operator+(const ModInt &a, const ModInt &b)
	{
		return mod_add(a.val, b.val);
	}
	friend ModInt operator-(const ModInt &a, const ModInt &b)
	{
		return mod_add(a.val, mod - b.val);
	}
	friend ModInt operator*(const ModInt &a, const ModInt &b)
	{
		return ModInt(1ll * a.val * b.val % mod);
	}
	void operator+=(const ModInt &other)
	{
		val = mod_add(val, other.val);
	}
	void operator-=(const ModInt &other)
	{
		val = mod_add(val, mod - other.val);
	}
	void operator*=(const ModInt &other)
	{
		val = 1ll * val * other.val % mod;
	}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	return 0;
}
