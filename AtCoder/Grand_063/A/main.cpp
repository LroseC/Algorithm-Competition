#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 2e5 + 10;

i32 n;
char str[N];

bool check(i32 p, i32 l, char ch)
{
	if (l == 0) return str[p] == ch;
	if (str[p + l] != ch) return 0;
	if (str[p + l + 1] == ch) return 1;
	return 0;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	read >> str;
	i32 pos1 = 0, pos2 = 0, pos = 0;
	for (int i = 1; i <= n; ++i) {
		if (i & 1) {
			while (str[pos1] != 'B' && pos1 + 1 <= n) ++pos1;
			if (str[pos1] == 'B') ++pos1;
		}
		else {
			while (str[pos2] != 'A' && pos2 + 1 <= n) ++pos2;
			if (str[pos2] == 'A') ++pos2;
		}
		while ((str[pos] == 'B' && pos < pos1) || (str[pos] == 'A' && pos < pos2))
			pos += 1;
		puts(str[pos] == 'A' ? "Alice" : "Bob");
	}
	return 0;
}
