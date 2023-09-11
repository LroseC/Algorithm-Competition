#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin
const int N = 410, mod = 998244353;

i32 n, len;
i32 fa[N];
char s[N][N];

i32 find(i32 x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline i32 qpow(i32 base, i32 k)
{
	i32 res = 1;
	while (k) {
		if (k & 1) res = 1ll * res * base % mod;
		k >>= 1;
		base = 1ll * base * base % mod;
	}
	return res;
}
inline i32 add(i32 x, i32 y)
{
	x += y;
	return x >= mod ? x - mod : x;
}

bool match(i32 x, i32 y)
{
	for (i32 i = 1; i <= len; ++i) {
		if (s[x][i] != '?' and s[y][i] != '?' and s[x][i] != s[y][i])
			return 0;
		if ((bool)s[x][i] ^ (bool)s[y][i])
			return 0;
	}
	return 1;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i)
		fa[i] = i;
	for (i32 i = 1; i <= n; ++i) {
		std::cin >> s[i] + 1;
		len = std::max((i32)strlen(s[i] + 1), len);
		for (i32 j = 1; j < i; ++j) {
			i32 u = find(i), v = find(j);
			if (u == v) continue;
			if (match(u, v)) {
				for (i32 k = 1; k <= len; ++k)
					if (s[v][k] == '?') s[u][k] = '?';
				fa[v] = u;
			}
		}
	}
	i32 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		if (find(i) != i) continue;
		i32 cnt = 0;
		for (i32 j = 1; j <= len; ++j)
			if (s[i][j] == '?') ++cnt;
		res = add(res, qpow(2, cnt));
	}
	printf("%d\n", res);
	return 0;
}
