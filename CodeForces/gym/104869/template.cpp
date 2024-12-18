#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int mod = 1e9 + 7;
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

	friend ModInt operator+(ModInt x, ModInt y)
	{
		return ModInt(mod_add(x.val, y.val));
	}
	friend ModInt operator-(ModInt x, ModInt y)
	{
		return ModInt(mod_add(x.val, mod - y.val));
	}
	friend ModInt operator*(ModInt x, ModInt y)
	{
		return ModInt(1ll * x.val * y.val % mod);
	}
	void operator+=(const ModInt &other)
	{
		val = mod_add(val, other.val);
		return *this;
	}
	void operator-=(const ModInt &other)
	{
		val = mod_add(val, mod - other.val);
		return *this;
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
