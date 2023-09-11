#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int mod = 998244353, N = 2e5 + 10;;
i32 add(i32 a, i32 b)
{ return a + b >= mod ? a + b - mod : a + b; }
i32 sub(i32 a, i32 b)
{ return a - b < 0 ? a - b + mod : a - b; }

i32 n;
i32 a[N], val[N], pre[N], nex[N];

void calcPre(void)
{
	for (int k = 0; k < 30; ++k) {
		for (i32 i = 1; i <= n; ++i) {
			val[i] = (a[i] >> k) & 1;
		}
		i32 cnt[2];
		cnt[0] = cnt[1] = 0;
		++cnt[0];
		i32 t = 0;
		for (i32 i = 1; i <= n; ++i) {
			t ^= val[i];
			pre[i] = add(pre[i], ((i64)cnt[t ^ 1] << k) % mod);
			cnt[t] += 1;
		}
	}
	for (i32 i = 1; i <= n; ++i) {
		pre[i] = add(pre[i], pre[i - 1]);
	}
}
void calcNex(void)
{
	for (int k = 0; k < 30; ++k) {
		for (i32 i = 1; i <= n; ++i) {
			val[i] = (a[i] >> k) & 1;
		}
		i32 cnt[2];
		cnt[0] = cnt[1] = 0;
		++cnt[0];
		i32 t = 0;
		for (i32 i = n; i >= 1; --i) {
			t ^= val[i];
			nex[i] = add(nex[i], ((i64)cnt[t ^ 1] << k) % mod);
			cnt[t] += 1;
		}
	}
	for (i32 i = n; i >= 1; --i) {
		nex[i] = add(nex[i], nex[i + 1]);
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
	}
	calcPre();
	calcNex();
	i32 res = 0;
	for (i32 k = 0; k < 30; ++k) {
		for (i32 i = 1; i <= n; ++i) 
			val[i] = (a[i] >> k) & 1;
		i32 t = 0;
		i32 sum[2];
		sum[0] = sum[1] = 0;
		for (i32 i = 1; i < n; ++i) {
			t ^= val[i];
			sum[t] = add(sum[t], nex[i + 1]);
		}
		t = 0;
		for (i32 i = 1; i < n; ++i) {
			t ^= val[i];
			res = (res + (1ll * pre[i] * sum[t ^ 1] % mod << k)) % mod;
			sum[t] = sub(sum[t], nex[i + 1]);
		}
	}
	printf("%d\n", res);
	return 0;
}
