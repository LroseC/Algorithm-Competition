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

const int N = 1e5 + 10;

i32 n, t;
char str[N];
i32 nex[N], cost[N];

void get_nex(char str[])
{
	for (int i = 2, j = 0; i <= n; ++i) {
		while (j && str[i] != str[j + 1]) {
			j = nex[j];
		}
		if (str[i] == str[j + 1]) {
			j += 1;
		}
		nex[i] = j;
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> t >> (str + 1);
	n = strlen(str + 1);
	printf("n = %d\n", n);
	get_nex(str);
	for (i32 i = 1; i <= n; ++i) {
		i32 j = i - 1;
		while (j && str[i] == str[j + 1]) {
			j = nex[j];
		}
		if (str[i] != str[j + 1]) {
			j += 1;
		}
		cost[i] = 1 + (i - 1 - j) + 1;
	}
	for (i32 i = 1; i <= n; ++i) {
		printf("cost[%d] = %d\n", i, cost[i]);
	}
	return 0;
}
