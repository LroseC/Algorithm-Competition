#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const i32 N = 2010;

i32 n;
i32 p[N], pos[N];

bool query(i32 x, i32 y)
{
	if (x == y) return 0;
	std::cout << "? " << x << ' ' << y << std::endl;
	bool ret;
	read >> ret;
	return ret;
}
bool cmp(i32 p1, i32 p2)
{
	i32 inv_all = query(p1, p2);
	i32 invr = query(p1 + 1, p2);
	i32 invl = 0;
	for (i32 i = p1 + 1; i < p2; ++i)
		invl ^= p[p1] > p[i];
	return !(inv_all ^ invr ^ invl);
}

i32 get_ord(i32 i)
{
	i32 l = 1, r = i;
	while (l < r) {
		i32 mid = l + r >> 1;
		if (cmp(pos[mid], i)) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	p[1] = 1;
	pos[1] = 1;
	for (i32 i = 2; i <= n; ++i) {
		p[i] = get_ord(i);
		for (i32 j = 1; j < i; ++j) {
			if (p[j] >= p[i]) p[j] += 1;
		}
		for (i32 j = 1; j <= i; ++j) {
			pos[p[j]] = j;
		}
	}
	std::cout << "!";
	for (i32 i = 1; i <= n; ++i) std::cout << ' ' << p[i];
	std::cout << std::endl;
	return 0;
}
