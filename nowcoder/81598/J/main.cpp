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

const int N = 2e5 + 10, LG = 20;

struct node
{
	i32 to, win[2];
	node(void) { to = win[0] = win[1] = 0; }
	node(i32 v, i32 x, i32 y)
	{
		to = v;
		win[0] = x, win[1] = y;
	}
	friend node operator+(const node &a, const node &b)
	{
		node res(b.to, 0, 0);
		res.win[0] = a.win[0] + b.win[0];
		res.win[1] = a.win[1] + b.win[1];
		return res;
	}
};

i32 n, a, b;
char str[N];
i32 sum[2][N];
node st[LG][N];
i32 LG2[N];

void init_get(void)
{
	for (i32 i = 2; i < N; ++i) {
		LG2[i] = LG2[i / 2] + 1;
	}
	for (i32 i = n; i < n * 2; ++i) {
		str[i] = str[i - n];
	}
	sum[0][0] = str[0] == '0';
	sum[1][0] = str[0] == '1';
	for (i32 i = 1; i < n * 2; ++i) {
		sum[0][i] = sum[0][i - 1] + (str[i] == '0');
		sum[1][i] = sum[1][i - 1] + (str[i] == '1');
	}
}
node get_next(i32 x)
{
	i32 tot_sum[2];
	tot_sum[0] = sum[0][n - 1];
	tot_sum[1] = sum[1][n - 1];
	i32 rest[2];
	rest[0] = rest[1] = a;
	if (tot_sum[0] < a && tot_sum[1] < a) {
		i32 tmp = (a - 1) / std::max(tot_sum[0], tot_sum[1]);
		rest[0] -= tmp * tot_sum[0];
		rest[1] -= tmp * tot_sum[1];
	}
	i32 v0 = std::lower_bound(sum[0] + x, sum[0] + x + n, (x == 0 ? 0 : sum[0][x - 1]) + rest[0]) - sum[0];
	i32 v1 = std::lower_bound(sum[1] + x, sum[1] + x + n, (x == 0 ? 0 : sum[1][x - 1]) + rest[1]) - sum[1];

	i32 to = std::min(v0, v1);
	node res((to + 1) % n, v0 == to, v1 == to);
//	printf("next[%d] = %d, [%d, %d]\n", x, (to + 1) % n, v0 == to, v1 == to);
	return res;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> a >> b;
	read >> str;
	init_get();
	for (i32 i = 0; i < n; ++i) {
		st[0][i] = get_next(i);
	}
	for (i32 lg = 1; lg <= LG2[2 * b + 1]; ++lg) {
		for (i32 i = 0; i < n; ++i) {
			i32 v = st[lg - 1][i].to;
			st[lg][i] = st[lg - 1][i] + st[lg - 1][v];
		}
	}
	for (i32 i = 0; i < n; ++i) {
		node res(i, 0, 0);
		for (i32 lg = LG2[2 * b + 1]; lg >= 0; --lg) {
			node tmp = res + st[lg][res.to];
			if (tmp.win[0] < b && tmp.win[1] < b)
				res = tmp;
		}
		res = res + st[0][res.to];
		std::cout << (res.win[0] == b ? '0' : '1');
	}
	std::cout << std::endl;
	return 0;
}
