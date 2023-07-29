#include <vector>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

i32 n;
i32 gd[1010][1010];
std::pair<i32, i32> tmn[1010];
std::vector<std::pair<i32, std::pair<i32, i32>>> op;

i32 gcd(i32 a, i32 b)
{
	if (a == 0 || b == 0) return 0;
	if (a < b) return gcd(b, a);
	if (a == b) gd[a][b] = 1;
	if (gd[a][b] != -1) return gd[a][b];
	return gd[a][b] = gcd(a - b, b) + 1;
}

void draw(i32 x, i32 y, i32 len);
void gcdDraw(i32 x, i32 y, i32 r, i32 c)
{
	if (r == 0 || c == 0) return;
	if (r == c) {
		draw(x, y, r);
	}
	else if (r < c) {
		draw(x, y, r);
		gcdDraw(x, y + r, r, c - r);
	}
	else {
		draw(x, y, c);
		gcdDraw(x + c, y, r - c, c);
	}
}
void draw(i32 x, i32 y, i32 len)
{
	if (len == 1) return;
	auto p = tmn[len];
	draw(x, y, p.first);
	draw(x + p.first, y + p.first, p.second);
	assert(p.first + p.second == len);
	gcdDraw(x + p.first, y, p.second, p.first);
	gcdDraw(x, y + p.first, p.first, p.second);
	op.emplace_back(x, std::make_pair(y, len));
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::memset(gd, -1, sizeof gd);
	for (int i = 2; i <= 1000; ++i) {
		i32 mn = 1e9;
		for (int j = 1; j <= i - j; ++j) {
			if (gcd(i - j, j) < mn) {
				mn = gcd(i - j, j);
				tmn[i] = std::make_pair(i - j, j);
			}
		}
	}
	read >> n;
	draw(1, 1, n);
	printf("%ld\n", op.size());
	for (auto t : op) {
		printf("%d %d %d\n", t.first, t.second.first, t.second.second);
	}
	return 0;
}
