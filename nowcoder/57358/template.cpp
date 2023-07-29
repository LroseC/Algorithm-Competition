#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int mod = 998244353;
inline int add(i32 a, i32 b)
{
	a += b;
	return a >= mod ? a - mod : a;
}
inline int dec(i32 a, i32 b)
{
	a -= b;
	return a < 0 ? a + mod : a;
}
struct ModInt
{
	i32 val;
	ModInt(void) { }
	ModInt(i32 x) { val = x; }

	ModInt operator+(const ModInt &oth) const
	{ return add(val, oth.val); }
	ModInt operator-(const ModInt &oth) const
	{ return dec(val, oth.val); }
	ModInt operator*(const ModInt &oth) const
	{ return ModInt(1ll * val * oth.val % mod); }
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	return 0;
}
