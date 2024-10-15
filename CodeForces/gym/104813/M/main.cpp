#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin
#define y1 yyy1

const int N = 2010;

i32 m;
std::string op[N];
i32 x1[N], y1[N], x2[N], y2[N], r[N];
char col[N];

i64 sq(i32 x)
{
	return 1ll * x * x;
}
void print(i32 x, i32 y, i32 n)
{
	for (i32 i = n - 1; i >= 1; --i) {
		if (op[i] == "Render") {
			continue;
		} else if (op[i] == "Circle") {
			if (sq(x - x1[i]) + sq(y - y1[i]) <= sq(r[i])) {
				putchar(col[i]);
				return;
			}
		} else {
			if (x1[i] <= x && x <= x2[i] && y1[i] <= y && y <= y2[i]) {
				putchar(col[i]);
				return;
			}
		}
	}
	putchar('.');
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> m;
	for (i32 i = 1; i <= m; ++i) {
		read >> op[i];
		if (op[i] == "Render") {
			read >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			for (i32 y = y2[i]; y >= y1[i]; --y) {
				for (i32 x = x1[i]; x <= x2[i]; ++x) {
					print(x, y, i);
				}
				puts("");
			}
		} else if (op[i] == "Circle") {
			read >> x1[i] >> y1[i] >> r[i] >> col[i];
		} else {
			read >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> col[i];
		}
	}
	return 0;
}
#undef y1
