#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 10;

char str[N][N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	for (i32 i = 0; i < 9; ++i)
		read >> str[i];
	bool flg = 0;
	for (i32 i = 0; i < 9; ++i) {
		for (i32 j = 0; j < 9; ++j) {
			if (!flg && i != 0 && i != 8 && j != 0 && j != 8 && str[i][j] == '8') {
				putchar('8');
				flg = 1;
			} else {
				putchar('*');
			}
		}
		putchar('\n');
	}
	return 0;
}
