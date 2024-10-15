#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using ldb = long double;
#define read std::cin

const int N = 20;

i32 n;
i32 G[N][N];
ldb w[N];

ldb myrand(void)
{
	return (ldb)rand() / RAND_MAX;
}

ldb calc(void)
{
	ldb ret = 0;
	for (i32 i = 0; i < n; ++i)
		for (i32 j = i + 1; j < n; ++j) {
			ret += G[i][j] * w[i] * w[j];
		}
	return ret;
}

ldb simulateA(void)
{
	for (i32 i = 0; i < n; ++i) {
		w[i] = 1.0 / n;
	}
	i32 cnt = 0;
	ldb t = 100000, rate = 1;
	while (t > 1e-9) {
		cnt += 1;
		i32 u = rand() % n;
		i32 v = rand() % n;
		if (u == v) continue;
		ldb wx = w[u] * myrand() * rate;
		ldb res_now = calc();
		w[u] -= wx;
		w[v] += wx;
		ldb res_new = calc();
		ldb delta = res_new - res_now;
		if (exp(delta / t) < myrand()) {
			w[u] += wx;
			w[v] -= wx;
		}
		t *= 0.998;
		rate *= 0.99999999;
	}
//	printf("cnt = %d\n", cnt);
	return calc();
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	srand(time(NULL));
	read >> n;
	for (i32 i = 0; i < n; ++i)
		for (i32 j = 0; j < n; ++j) {
			read >> G[i][j];
		}
	ldb res = -1e9;
	while (true) {
		res = std::max(res, simulateA());
		if (1.0 * clock() / CLOCKS_PER_SEC > 0.95)
			break;
	}
	printf("%.8Lf\n", res);
	return 0;
}
