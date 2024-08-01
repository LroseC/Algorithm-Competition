#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using ldb = long double;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 1e6 + 10;

i32 n, m, idx = 1;
ldb p;
bool end[N];
i32 ch[N][2];
ldb f[N], w[N];
char str[N];

void insert(i32 u, char str[], i32 len)
{
	if (len == 0) {
		end[u] = 1;
		f[u] = 1;
		return;
	}
	i32 c = str[0] - '0';
	if (!ch[u][c]) {
		ch[u][c] = ++idx;
	}
	insert(ch[u][c], str + 1, len - 1);
}
void dp(i32 u)
{
	if (end[u]) {
		return;
	}
	dp(ch[u][0]);
	dp(ch[u][1]);
	if (f[ch[u][0]] > f[ch[u][1]]) {
		w[ch[u][0]] = p;
		w[ch[u][1]] = 1 - p;
		f[u] = p * f[ch[u][0]] + (1 - p) * f[ch[u][1]];
	} else {
		w[ch[u][1]] = p;
		w[ch[u][0]] = 1 - p;
		f[u] = p * f[ch[u][1]] + (1 - p) * f[ch[u][0]];
	}
}
ldb tot;
void get_tot(i32 u, ldb wx)
{
	printf("u = %d, wx = %Lf\n", u, wx);
	if (end[u]) {
		if (u != 0) tot += wx;
		return;
	}
	get_tot(ch[u][0], wx * w[ch[u][0]]);
	get_tot(ch[u][1], wx * w[ch[u][1]]);
}
void adjust(i32 u, ldb wx)
{
	if (end[u]) {
		f[u] *= (tot - wx);
		return;
	}
	adjust(ch[u][0], wx * w[ch[u][0]]);
	adjust(ch[u][1], wx * w[ch[u][1]]);
}

int main(void)
{
	std::ios::sync_with_stdio(false);

	end[0] = 1;

	read >> n >> m >> p;
	for (i32 i = 1; i <= n; ++i) {
		read >> str;
		insert(1, str, m);
	}
	for (i32 i = 1; i <= n; ++i) {
		dp(1);
		printf("f[1] = %.10Lf\n", f[1]);
		tot = 0;
		get_tot(1, 1);
		adjust(1, 1);
	}
	printf("%.10Lf\n", f[1]);
	return 0;
}
