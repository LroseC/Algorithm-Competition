#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 3010;

i32 n, m;
i32 f[N][2], p[N], w[N][N];
// 0 表示还没有放入, 1 表示已经放入

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	read >> n >> m;
	i32 sum = 0;
	for (i32 i = 0; i <= m; ++i) {
		f[i][0] = f[i][1] = INT_MIN;
	}
	f[0][0] = 0;
	for (i32 i = 1; i <= n; ++i) {
		read >> p[i];
		sum += p[i];
		for (i32 j = 1; j <= p[i]; ++j) read >> w[i][j];
		for (i32 j = m; j >= 0; --j) {
			if (j - p[i] >= 0) {
				f[j][0] = std::max(f[j][0], f[j - p[i]][0] + w[i][p[i]]);
				f[j][1] = std::max(f[j][1], f[j - p[i]][1] + w[i][p[i]]);
			}
			for (i32 k = 1; k <= p[i]; ++k)
				if (j - k >= 0)
					f[j][1] = std::max(f[j][1], f[j - k][0] + w[i][k]);
		}
	}
	if (sum < m) {
		printf("%d\n", f[sum][0]);
	}
	else {
		printf("%d\n", std::max(f[m][0], f[m][1]));
	}
	return 0;
}
