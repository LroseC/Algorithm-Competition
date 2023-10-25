#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 2e5 + 10;
const int mod = 998244353;

i32 n, m;
i32 fa[N], p[N];

i32 find(i32 x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
i32 qpow(i32 base, i32 k)
{
	i32 res = 1;
	while (k) {
		if (k & 1) res = 1ll * res * base % mod;
		k >>= 1;
		base = 1ll * base * base % mod;
	}
	return res;
}

int main(void)
{
	//Think tiwce, code once.
	std::ios::sync_with_stdio(false);
	read >> n >> m;
	//前面的对应相同, 后面的严格小于, 枚举过去, 然后计数.
	for (i32 i = 1; i <= n; ++i) {
		read >> p[i];
		fa[i] = i;
	}
	i32 tmp = 1ll * m * (m - 1) / 2 % mod;
	i32 cnt = n;
	i32 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		i32 a = find(i), b = find(p[i]);
		if (a != b) {
			res = (res + 1ll * tmp * qpow(m, cnt - 2)) % mod;
			cnt -= 1;
			fa[a] = b;
		}
	}
	printf("%d\n", res);
	return 0;
}
