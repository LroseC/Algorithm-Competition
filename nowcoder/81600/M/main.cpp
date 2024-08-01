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

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

struct frac
{
	i64 son, mom;
	frac(void) { son = 0, mom = 1; }
	frac(i64 a, i64 b)
	{
		i64 d = gcd(a, b);
		son = a / d;
		mom = b / d;
	}
	friend frac operator+(const frac &a, const frac &b)
	{
		frac res;
		i64 d = gcd(a.mom, b.mom);
		res.mom = a.mom / d * b.mom;
		res.son = a.son * (b.mom / d) + b.son * (a.mom / d);
		return res;
	}
	friend bool operator<(const frac &a, const frac &b)
	{
		i32 d = gcd(a.mom, b.mom);
		return a.son * (b.mom / d) < b.son * (a.mom / d);
	}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 c, a, b;
		read >> c >> a >> b;
		if (a < b - a) a = b - a;
		frac p(a, b);
		frac res(c, 2);
		for (i32 i = 1; i < c; ++i) {
		}
	}
	return 0;
}
