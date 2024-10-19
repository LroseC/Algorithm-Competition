#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int mod = 1e9 + 7;
i32 mod_add(i32 x, i32 y)
{
	x += y;
	return x >= mod ? x - mod : x;
}

struct ModInt
{
	i32 val;
	ModInt(void) { val = 0; }
	ModInt(i32 x) { val = x; }

	friend ModInt operator+(ModInt x, ModInt y)
	{
		return ModInt(mod_add(x.val, y.val));
	}
	friend ModInt operator-(ModInt x, ModInt y)
	{
		return ModInt(mod_add(x.val, mod - y.val));
	}
	friend ModInt operator*(ModInt x, ModInt y)
	{
		return ModInt(1ll * x.val * y.val % mod);
	}
	void operator+=(const ModInt &other)
	{
		val = mod_add(val, other.val);
	}
	void operator-=(const ModInt &other)
	{
		val = mod_add(val, mod - other.val);
	}
	void operator*=(const ModInt &other)
	{
		val = 1ll * val * other.val % mod;
	}
};

const int N = 100010, LG = 20;

i32 step;
i32 u, v, K;
i32 w[N][LG];
char s[N], t[N];

void dfs(i32 x)
{
	if (step > 100) {
		return;
	}
	step += 1;
	if (x == v) {
		K -= 1;
	}
	if (K == 0) return;
	for (i32 i = 0; i < LG; ++i) {
		if (!w[x][i]) {
			int y = x ^ (1 << i);
			w[x][i] = 1;
			w[y][i] = 1;
			dfs(y);
			break;
		}
	}
}

void work(void)
{
	step = 0;
	std::memset(w, 0, sizeof w);
	read >> s >> t >> K;
	std::reverse(s, s + strlen(s));
	std::reverse(t, t + strlen(t));
	u = 0, v = 0;
	for (i32 i = 0; s[i]; ++i) {
		u += (s[i] - '0') << i;
	}
	for (i32 i = 0; t[i]; ++i) {
		v += (t[i] - '0') << i;
	}
	dfs(u);
	printf("%d\n", step == 101 ? -1 :step - 1);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
