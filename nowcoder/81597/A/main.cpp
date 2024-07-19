#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 810;

char res[N][N];

void clear(void)
{
}
void work(void)
{
	i32 n, m, K; read >> n >> m >> K;
	i32 X, Y; char type; read >> X >> Y >> type;
	X -= 1, Y -= 1;
	if (K < n + m) {
		puts("No");
		return;
	}
	if ((n & 1) || (m & 1)) {
		bool not_n = !(m & 1);
		if (not_n) {
			std::swap(n, m);
			std::swap(X, Y);
		}
		i32 cnt;
		for (int t = 0; t <= 1; ++t) {
			for (i32 i = 0; i < n; ++i) {
				for (i32 j = 0; j < m; ++j)
					res[i][j] = t + 'A';
			}
			cnt = K - n - m;
			for (i32 i = 0; cnt && i < n; ++i) {
				for (i32 j = t ^ (i & 1) ^ 1; cnt && j < m; j += 2) {
					res[i][j] = 'A' + (t ^ 1);
					if (t == 0) {
						cnt -= i != 0 && j != m - 1;
					} else {
						cnt -= i != 0 && j != 0;
					}
				}
			}
			if (cnt == 0 && res[X][Y] == type) {
				break;
			}
			for (i32 i = 0; i < n; ++i) {
				for (i32 j = 0; j < m; ++j)
					res[i][j] = t + 'A';
			}
			cnt = K - n - m;
			for (i32 i = 0; cnt && i < n; ++i) {
				for (i32 j = t ^ (i & 1); cnt && j < m; j += 2) {
					res[i][j] = 'A' + (t ^ 1);
					if (t == 0) {
						cnt -= i != 0 && j != m - 1;
					} else {
						cnt -= i != 0 && j != 0;
					}
				}
			}
			if (cnt == 0 && res[X][Y] == type) {
				break;
			}
		}
		if (cnt != 0 || res[X][Y] != type) {
			puts("No");
			return;
		}
		puts("Yes");
		if (not_n) {
			for (i32 i = 0; i < m; ++i, putchar('\n'))
				for (i32 j = 0; j < n; ++j)
					putchar(res[j][i]);
		} else {
			for (i32 i = 0; i < n; ++i, putchar('\n'))
				for (i32 j = 0; j < m; ++j)
					putchar(res[i][j]);
		}
	} else {
		for (i32 i = 0; i < n; ++i) {
			for (i32 j = 0; j < m; ++j)
				res[i][j] = 'A';
		}
		res[X][Y] = type;
		i32 cnt = K - n - m;
		for (i32 i = 0; cnt && i < n; ++i) {
			for (i32 j = (i & 1) ^ 1; cnt && j < m; j += 2) {
				if (i == X && j == Y && type == 'A') continue;
				res[i][j] = 'B';
				if (i != 0 && j != m - 1) {
					if (i == X && j + 1 == Y && type == 'B') continue;
					cnt -= 1;
				}
			}
		}
		if (!cnt) {
			puts("Yes");
			for (i32 i = 0; i < n; ++i, putchar('\n'))
				for (i32 j = 0; j < m; ++j) {
					putchar(res[i][j]);
				}
		} else {
			puts("No");
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		clear();
		work();
	}
	return 0;
}
