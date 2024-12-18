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

void work(void)
{
	read >> n >> m;
	std::vector<Lim> lim(m);
	for (i32 i = 0; i < m; ++i) {
		read >> lim[i].l >> lim[i].r >> lim[i].v;
		lim[i].l += 1;
		lim[i].r += 1;
	}
	n += 1;
	std::sort(lim.begin(), lim.end());
	for (i32 i = 1, j = 0; i <= n; ++i) {
		while (j < m && lim[j].r <= i) {
			j += 1;
		}
		for (i32 last = i - 1; last >= 0; --last) {
		}
	}
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
