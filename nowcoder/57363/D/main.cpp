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
	i32 n;
	read >> n;
	std::vector<i32> p(n + 1);
	std::vector<std::vector<i32>> flg(n + 1);
	for (i32 i = 1; i <= n; ++i) flg[i].resize(n + 1);
	for (i32 i = 1; i <= n; ++i) read >> p[i];
	for (i32 md = 1; md <= n; ++md) {
		for (i32 l = md, r = md, lb = md; l >= 1; --l) {
			if (p[l] >= p[md]) {
				while (r <= n && p[r] > p[md]) ++r;
				lb = r;
				if (r != n + 1) r += 1;
				while (r <= n && p[r] > p[md]) ++r;
			}
			if (lb <= n) flg[l][lb] += 1;
			if (r <= n) flg[l][r] -= 1;
		}
	}
	i32 res = 0;
	for (i32 l = 1; l <= n; ++l) {
		for (i32 r = l; r <= n; ++r) {
			flg[l][r] += flg[l][r - 1];
			if (!flg[l][r]) {
				++res;
			}
		}
	}
	printf("%d\n", res);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) work();
	return 0;
}
