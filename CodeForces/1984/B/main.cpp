#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 200;
char str[N];

bool check(char s[], i32 n)
{
	if (s[0] != '1') {
		return false;
	}
	if (n == 2) {
		return s[1] != '9';
	}
	if (s[1] == '0') return false;
	s[1] = '1';
	return check(s + 1, n - 1);
}

int main(void)
{
	//I love MoRanSky FOREVER!
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		read >> str;
		i32 n = std::strlen(str);
		puts(check(str, n) ? "YES" : "NO");
	}
	return 0;
}
