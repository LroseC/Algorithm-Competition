#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const i32 mod = 998244353;

struct ModInt
{
	i32 val;
	ModInt(void) { val = 0; }
	ModInt(i32 x) { val = x; }

	ModInt operator+(const ModInt &other) const
	{
		i32 t = val + other.val;
		return ModInt(t >= mod ? t - mod : t);
	}
	ModInt operator-(const ModInt &other) const
	{
		i32 t = val + mod - other.val;
		return ModInt(t >= mod ? t - mod : t);
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
		val = val + mod - other.val;
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
{ return qpow(x, mod - 2); }

struct poly
{
	i32 n;
	ModInt a[40];
	poly(void)
	{
		n = 0;
		std::memset(a, 0, sizeof a);
	}
	poly(i32 x)
	{
		n = x;
		std::memset(a, 0, sizeof a);
	}
	poly operator+(const poly &other) const
	{
		poly res;
		res.n = std::max(n, other.n);
		for (i32 i = 0; i <= res.n; ++i) {
			res.a[i] = a[i] + other.a[i];
		}
		return res;
	}
	void operator+=(const poly &other)
	{
		n = std::max(n, other.n);
		for (i32 i = 0; i <= n; ++i) {
			a[i] += other.a[i];
		}
	}
	void operator-=(const poly &other)
	{
		n = std::max(n, other.n);
		for (i32 i = 0; i <= n; ++i) {
			a[i] -= other.a[i];
		}
	}
	friend poly operator*(ModInt x, poly pl)
	{
		poly res(pl.n);
		for (i32 i = 0; i <= res.n; ++i) {
			res.a[i] = x * pl.a[i];
		}
		return res;
	}
	void operator*=(const ModInt &x)
	{
		for (i32 i = 0; i <= n; ++i)
			a[i] *= x;
	}
	ModInt operator()(const ModInt x) const
	{
		ModInt res(0), base(1);
		for (i32 i = 0; i <= n; ++i) {
			res += base * a[i];
			base *= x;
		}
		return res;
	}
};

const int N = 1e5 + 10;

i32 n, K;
char str[N];
ModInt C[40][40];

void init_C(void)
{
	for (i32 i = 0; i <= K; ++i) {
		C[i][0] = 1;
		for (i32 j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}
poly get_poly(i32 r)
{
	ModInt base(r + 1);
	ModInt ax(1);
	poly res(K);
	for (i32 i = 0; i <= K; ++i) {
		res.a[K - i] = ax * C[K][i];
		if ((K - i) & 1) res.a[K - i] *= ModInt(mod - 1);
		ax *= base;
	}
	return res;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> K;
	read >> (str + 1);

	init_C();

	ModInt res(0);
	i32 l = 1, r = 1;
	while (l <= n) {
		while (str[l] == '0')
			l += 1;
		if (l > n) break;
		r = l;
		while (r + 1 <= n && str[r + 1] != '0')
			r += 1;
//		printf("l = %d, r = %d\n", l, r);
		ModInt base_p = get_inv(2);
		ModInt p(1);
		poly tot(K);
		for (i32 i = l; i <= r; ++i) {
			if (str[i] == '?') {
				p *= base_p;
			}
			tot += p * get_poly(i);
//			printf("%d\n", get_poly(i)(i).val);
		}
		for (i32 i = l; i <= r; ++i) {
			res += tot(i);
			if (str[i] == '?') {
				tot *= 2;
			}
			tot -= get_poly(i);
		}
		l = r + 1;
	}
	std::cout << res.val << std::endl;
	return 0;
}
