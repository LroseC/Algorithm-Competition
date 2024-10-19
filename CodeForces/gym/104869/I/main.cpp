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

ModInt place_third(void)
{
	i32 hl = 0xcfcfcfcf, hr = 0x3f3f3f3f;
	i32 wl = 0xcfcfcfcf, wr = 0x3f3f3f3f;
	for (i32 i = 1; i <= 3; ++i) {
		if (i == pos || i == sec_pos)
			continue;
	}
}

void work(void)
{
	read >> H >> W;
	for (i32 i = 1; i <= 3; ++i) {
		read >> h[i] >> w[i];
	}
	ModInt res(0);
	for (i32 i = 1; i <= 3; ++i) {
		pos = i;
		res += calc();
	}
	for (i32 i = 1; i <= 3; ++i)
		for (i32 j = i + 1; j <= 3; ++j) {
			pos = i;
			sec_pos = j;
			res -= place_third();
		}
	printf("%d\n", res.val);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	return 0;
}
