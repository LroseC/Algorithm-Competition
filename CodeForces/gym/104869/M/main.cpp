#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <cstring>
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


const int N = 1e6 + 10;

i32 K;
i32 l1, l2;
ModInt inv3;
char s[N], t[N];

i32 go[] = {0, 1, 3, 2};

ModInt qpow(ModInt base, i32 k)
{
	ModInt res = 1;
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

ModInt calc(i32 dig)
{
	if (dig == -1) return 0;
	return (ModInt(16) * qpow(4, dig) - ModInt(4)) * inv3;
}
ModInt calc_dif(i32 dif)
{
	if (dif == -1) {
		return 0;
	}
	for (i32 i = 0; i < 4; ++i) {
		i32 u = s[dif * 2] + s[dif * 2 + 1] * 2;
		i32 v = t[dif * 2] + t[dif * 2 + 1] * 2;
		if (go[i] == (u ^ v)) {
			return calc(dif - 1) * i + i;
		}
	}
}

void init(void)
{
	inv3 = get_inv(3);
}

void work(void)
{
	read >> s >> t >> K;
	l1 = strlen(s);
	l2 = strlen(t);
	std::reverse(s, s + strlen(s));
	std::reverse(t, t + strlen(t));
	i32 len = std::max(strlen(s), strlen(t));
	for (i32 i = 0; s[i]; i += 1) {
		s[i] -= '0';
	}
	for (i32 i = 0; t[i]; i += 1) {
		t[i] -= '0';
	}
	ModInt res(0);
	for (i32 i = 0; i * 2 <= len; ++i) {
		if (s[i * 2] != t[i * 2] || s[i * 2 + 1] != t[i * 2 + 1]) {
			res += calc_dif(i);
		}
	}
	i32 dif = -1;
	for (i32 i = 0; i * 2 <= len; ++i) {
		if (s[i * 2] != t[i * 2] || s[i * 2 + 1] != t[i * 2 + 1]) {
			dif = i;
			break;
		}
	}
	if (dif != -1 && dif + 1 < K) {
		puts("-1");
		return;
	}
	K -= 2;
	printf("%d\n", (res + calc(K)).val);
}
void clear(void)
{
	for (i32 i = 0; i <= l1 + 5; ++i) {
		s[i] = 0;
	}
	for (i32 i = 0; i <= l2 + 5; ++i) {
		t[i] = 0;
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	init();
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	return 0;
}
