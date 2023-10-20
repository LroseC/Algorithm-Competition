#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 110;

i32 n;
i32 match[N << 1];
i32 f[N][N], g[N];


bool check(i32 l, i32 r)
{
	if (match[l] == r && match[r] == l) return 1;
	if (match[l] != 0 && match[r] != 0) return 0;
	if (match[l] != 0) {
		return match[l] == -1 && match[r] == 0;
	}
	if (match[r] != 0) {
		return match[r] == -1 && match[l] == 0;
	}
	return 0;
}

int main(void)
{
	//Think tiwce, code once. I'm back.
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		i32 a, b;
		read >> a >> b;
		if (a != -1 && b != -1 && a > b) {
			puts("No");
			return 0;
		}
		if (a != -1) {
			if (match[a]) {
				puts("No");
				return 0;
			}
			match[a] = b;
		}
		if (b != -1) {
			if (match[b]) {
				puts("No");
				return 0;
			}
			match[b] = a;
		}
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = i; j <= n; ++j) {
			f[i][j] = 1;
			i32 bg = i * 2 - 1, ed = j * 2;
			i32 halfL = (ed - bg + 1) / 2;
			for (i32 k = 0; k < halfL; ++k) {
				if (!check(bg + k, bg + k + halfL)) {
					f[i][j] = 0;
				}
			}
		}
	}
	g[0] = 1;
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 0; j < i; ++j) {
			g[i] |= g[j] && f[j + 1][i];
		}
	}
	puts(g[n] ? "Yes" : "No");
	return 0;
}
