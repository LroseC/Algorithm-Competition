#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e5 + 10;

double a[N];

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 n; read >> n;
	double sum = 0;
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
		sum += a[i];
	}
	double unit = sum / (n + 1);
	printf("%.8lf ", unit * 2);
	for (i32 i = 1; i < n; ++i) printf("%.8lf ", unit);
	puts("");
	return 0;
}
