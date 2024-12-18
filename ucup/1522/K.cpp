#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int M = 5e5 + 10;

i32 m;
i64 a[M], b[M];

void clear(void)
{
	for (i32 i = 0; i < m; ++i) {
		a[i] = b[i] = 0;
	}
}
void work(void)
{
	read >> m;
	i32 mxa = 0, mxb = 0, mna = m;
	i64 suma = 0, sumb = 0;
	for (i32 i = 0; i < m; ++i) {
		read >> a[i];
		suma += a[i];
		if (a[i]) mxa = i;
	}
	for (i32 i = 0; i < m; ++i) {
		read >> b[i];
		sumb += b[i];
		if (b[i]) mxb = i;
	}
	if (suma < sumb) {
		a[0] += sumb - suma;
	} else {
		b[0] += suma - sumb;
	}
//	for (i32 i = 0; i < m; ++i) {
//		printf("%lld ", a[i]);
//	}
//	puts("");
//	for (i32 i = 0; i < m; ++i) {
//		printf("%lld ", b[i]);
//	}
//	puts("");
	i64 res = 0;
	bool flag = 0;
	for (i32 i = 0, j = m - 1; i < m; ++i) {
		while (a[i]) {
			while (!b[j] && j - 1 >= 0) {
				j -= 1;
			}
			if (i + j < m - 1 || b[j] == 0) break;
			if (i + j >= m) {
				flag = 1;
			}
			i32 tmp = std::min(a[i], b[j]);
			if (tmp && mna == m) {
				mna = i;
			}
			res += tmp;
			a[i] -= tmp;
			b[j] -= tmp;
		}
	}
	for (i32 i = mna + 1; i < m; ++i) {
		if (a[i]) {
			flag = 1;
		}
	}
//	printf("res = %lld\n", res);
	if (flag) {
		printf("%lld\n", res);
	} else {
		if (mxa + mxb >= m) {
			printf("%lld\n", res - 1);
		} else {
			printf("%lld\n", 0ll);
		}
	}
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
