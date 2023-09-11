#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

i32 lg2(i32 x)
{
	i32 res = 0;
	while (x) {
		res += 1;
		x >>= 1;
	}
	return res - 1;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> q;
	for (i32 i = 1; i <= n; ++i) {
		read >> key[i];
		i32 x = key[i], y = 0;
		i32 last = 30;
		while (x) {
			while ((x & 1) == 0) {
				y += 1;
				x >>= 1;
			}
			i32 t = lg2(x);
			if (last != 30)
				nex[last + 1] = y;
			for (i32 k = last; k >= t; --k) {
				sum[k][i] = y;
			}
			x >>= 1;
			last = t - 1;
		}
	}
	for (i32 k = 30; k >= 0; --k)
		for (i32 i = 1; i <= n; ++i)
			sum[k][i] += sum[k][i - 1];
	for (i32 k = 30; k >= 0; --k) {
		for (i32 i = 1; i <= n; ++i)
			root[k][i] = insert(root[k][i - 1], i);
	}
	while (q--) {
		i32 l, r, k;
		read >> l >> r >> K;
	}
	return 0;
}
