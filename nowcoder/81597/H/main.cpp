#include <map>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int64_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 2e5 + 10;

i32 mp(char ch)
{
	if (ch == 'W') {
		return 0;
	} else if (ch == 'S') {
		return 1;
	} else if (ch == 'A') {
		return 2;
	}
	return 3;
}

i32 goy[] = {+1, -1, 0, 0};
i32 gox[] = {0, 0, -1, +1};
std::map<pii, i32> count;

char str[N];
i64 sumx[N], sumy[N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 n, endx, endy;
	read >> n >> endx >> endy;
	read >> str + 1;
	if (endx == 0 && endy == 0) {
		std::cout << 1ll * n * (n + 1) / 2 << std::endl;
		return 0;
	}
	i64 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		sumx[i] = sumx[i - 1] + gox[mp(str[i])];
		sumy[i] = sumy[i - 1] + goy[mp(str[i])];
	}
	count[std::make_pair(sumx[n], sumy[n])] = n;
	for (i32 i = n - 1; i >= 0; --i) {
		i32 u = count[std::make_pair(sumx[i] + endx, sumy[i] + endy)];
		if (u != 0) {
			res += (n - u + 1);
		}
		count[std::make_pair(sumx[i], sumy[i])] = i;
	}
	std::cout << res << std::endl;
	return 0;
}
