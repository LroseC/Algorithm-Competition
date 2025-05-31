#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const i32 N = 3e5 + 10;

i32 n, m;
i32 rat[N], diff[N], easy[N];

void clear(void)
{
}

i32 get_num(i32 r)
{
	return rat + 1 + n - std::lower_bound(rat + 2, rat + 1 + n, r);
}

void work(void)
{
	read >> n >> m;
	for (i32 i = 1; i <= n; ++i) {
		read >> rat[i];
	}
	for (i32 i = 1; i <= m; ++i) {
		read >> diff[i];
	}
	std::sort(rat + 2, rat + 1 + n);
	std::sort(diff + 1, diff + 1 + m);
	i32 beg = 1;
	while (beg <= m && diff[beg] <= rat[1]) {
		beg += 1;
	}
	for (i32 k = 1; k <= m; ++k) {
		i32 rest = m - (m / k) * k;
		beg += rest;
		i32 cnt = m / k;
		i32 j = cnt;
		for (i32 i = beg; i <= m; i += k) {
			easy[j] = diff[i];
			j -= 1;
		}
		while (j) {
			easy[j] = -1;
			j -= 1;
		}
		
		i64 res = 0;
		for (i32 i = 1; i <= cnt; ++i) {
//			printf("i = %d, rat[1] = %d, easy[i] = %d\n", i, rat[i], easy[i]);
			i32 tmp;
			res += (tmp = (easy[i] == -1 ? 1 : get_num(easy[i]) + 1));
//			printf("tmp = %d\n", tmp);
		}
		printf("%lld ", res);
		beg -= rest;
	}
	puts("");
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
