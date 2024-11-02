#include <cmath>
#include <ctime>
#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const int N = 110;

double TIME_LIM;
i32 T;
i32 n, res;
i64 a[N];
bool vis[N];

void clear(void)
{
	res = 0;
	for (i32 i = 1; i <= n; ++i) {
		vis[i] = 0;
	}
}

double rate_rand(void)
{
	return 1.0 * rand() / RAND_MAX;
}
double calc_tim(void)
{
	return 1.0 * clock() / CLOCKS_PER_SEC;
}


i32 calc(void)
{
	i32 ret = 0;
	i64 tot = 0;
	for (i32 i = 1; i <= n; ++i) {
		if (vis[i]) {
			tot |= a[i];
			ret += 1;
		}
	}
	ret -= __builtin_popcountl(tot);
	res = std::max(res, ret);
	return ret;
}
void sa(void)
{
	double t = 100;
	while (t > 1e-5) {
		i32 pos = rand() % n + 1;
		i32 now_res = calc();
		vis[pos] ^= 1;
		i32 del = calc() - now_res;
		if (exp(del / t) >= rate_rand()) {
		} else {
			vis[pos] ^= 1;
		}
		t *= 0.99;
		break;
	}
}

void work(void)
{
	auto beg = clock();
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
	}
	while (calc_tim() < (T - 1) * TIME_LIM + TIME_LIM * 0.90) {
		sa();
	}
	printf("%d\n", res);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	TIME_LIM = 2.0 / tt;
	for (T = 1; T <= tt; ++T) {
		work();
		clear();
	}
	return 0;
}
