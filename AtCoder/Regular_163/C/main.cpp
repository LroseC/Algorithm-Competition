#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

i64 gcd(i64 a, i64 b)
{
	while (a) {
		std::swap(a, b);
		a %= b;
	}
	return b;
}

struct frac
{
	i64 a, b;
	frac operator+(const frac &other) const
	{
		i64 d = gcd(other.b, b);
		frac res;
		res.b = b / d * other.b;
		res.a = a * (other.b / d) + other.a * (b / d);
		i64 dp = gcd(res.a, res.b);
		res.a /= dp;
		res.b /= dp;
		return res;
	}
	frac operator-(const frac &other) const
	{
		i64 d = gcd(other.b, b);
		frac res;
		res.b = b / d * other.b;
		res.a = -a * (other.b / d) + other.a * (b / d);
		i64 dp = gcd(res.a, res.b);
		res.a /= dp;
		res.b /= dp;
		return res;
	}
};

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n; read >> n;
		if (n == 2) {
			puts("No");
			continue;
		}
		puts("Yes");
		n -= 3;
		printf("2 3 ");
		i32 now = 6;
		while (n--) {
			printf("%d ", now + 1);
			now *= now + 1;
		}
		printf("%d\n", now);
	}
	return 0;
}
