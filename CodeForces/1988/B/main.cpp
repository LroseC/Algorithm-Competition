#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin
const int N = 2e5 + 10;

char str[N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 n; read >> n;
		read >> str;
		i32 zero_bound = 0;
		zero_bound += str[0] == '0';
		zero_bound += str[n - 1] == '0';
		i32 cnt = 0;
		i32 nearby = 0;
		for (i32 i = 0; i < n; ++i) {
			if (str[i] == '1') {
				cnt += 1;
				if (i != 0 && str[i - 1] == '1')
					nearby += 1;
			}
		}
		puts(nearby >= zero_bound ? "Yes" : "No");
	}
	return 0;
}
