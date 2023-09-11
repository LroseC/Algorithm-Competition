#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

void work(void)
{
	i32 n, q;
	read >> n >> q;
	std::vector<i32> a(n + 1), sum(n + 1);
	std::vector<i32> sumo(n + 1), sume(n + 1);
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
		sum[i] = (sum[i - 1] + a[i]) & 1;
		sumo[i] = sumo[i - 1] + (sum[i] & 1);
		sume[i] = sume[i - 1] + !(sum[i] & 1);
	}
	while (q--) {
		i32 l, r, k;
		read >> l >> r >> k;
		if (sum[l - 1] & 1) {
			i32 sm = sumo[r] - sumo[l - 1];
			puts(sm >= k && (sum[r] & 1) ? "YES" : "NO");
		}
		else {
			i32 sm = sume[r] - sume[l - 1];
			puts(sm >= k && !(sum[r] & 1) ? "YES" : "NO");
		}
	}
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
