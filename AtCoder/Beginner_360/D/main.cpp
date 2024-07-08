#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int64_t;
using i64 = int64_t;

#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 n, T;
	read >> n >> T;
	std::string str;
	read >> str;
	std::vector<i32> pos(n);
	for (i32 i = 0; i < n; ++i) {
		read >> pos[i];
	}
	i64 res = 0;
	for (i32 i = 0, j = 0, cnt = 0; i < n; ++i) {
		if (str[i] == '0') {
			cnt -= 1;
			continue;
		}
		while (j < n && pos[j] - pos[i] <= T * 2) {
			if (str[j] == '0') {
				cnt += 1;
			}
			j += 1;
		}
		std::cout << j << ' ' << cnt << std::endl;
		res += cnt;
	}
	std::cout << res << std::endl;
	return 0;
}
