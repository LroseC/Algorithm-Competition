#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const i32 N = 2e5 + 10;

i32 Q, t[N], v[N];
i32 sum[N], cnt[N], res[N];
i32 sum_tree[N * 20], ch[N * 20][2], idx;

void insert(i32 u, i32 index, i32 val, i32 dig)
{
	if (dig < 0) {
		sum_tree[u] += val;
		return;
	}
	i32 tmp = index >> dig & 1;
	if (!ch[u][tmp]) {
		ch[u][tmp] = ++idx;
	}
	insert(ch[u][tmp], index, val, dig - 1);
	sum_tree[u] = sum_tree[ch[u][0]] + sum_tree[ch[u][1]];
}
i32 query(i32 u, i32 index, i32 dig)
{
	if (u == 0) return 0;
	if (dig < 0) {
		return 0;
	}
	i32 tmp = index >> dig & 1;
	i32 res = tmp == 0 ? sum_tree[ch[u][1]] : 0;
	return res + query(ch[u][tmp], index, dig - 1);
}
void clear(void)
{
	idx = 1;
	std::memset(ch, 0, sizeof ch);
	std::memset(sum_tree, 0, sizeof sum_tree);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> Q;
	for (i32 i = 0; i < Q; ++i) {
		read >> t[i] >> v[i];
	}
	for (i32 k = 0; k <= 20; ++k) {
		i32 n = 0;
		clear();
		for (i32 i = 0; i < Q; ++i) {
			for (i32 j = n; j > n - t[i]; --j) {
				insert(1, sum[j], -1, k - 1);
			}
			n -= t[i];
			n += 1;
			sum[n] = sum[n - 1] + v[i];
			cnt[n] = cnt[n - 1] + (sum[n] >> k & 1);
			i32 tmp = 0;
			if ((sum[n] >> k & 1) && ((n - cnt[n - 1]) & 1)) {
				tmp = 1;
			}
			if (!(sum[n] >> k & 1) && (cnt[n - 1] & 1)) {
				tmp = 1;
			}
			tmp ^= query(1, sum[n], k - 1) & 1;
			insert(1, sum[n], +1, k - 1);
			res[i] ^= tmp << k;
		}
	}
	for (i32 i = 0; i < Q; ++i)
		printf("%d\n", res[i]);
	return 0;
}
