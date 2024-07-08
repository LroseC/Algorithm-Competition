#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 2e5 + 10;

int n;
char s1[N], s2[N], res[N];

int main(void)
{
	//Think tiwce, code once.
	std::ios::sync_with_stdio(false);
	read >> n;
	read >> s1 >> s2;
	i32 cnt = 0;
	for (i32 i = 0; i < n; ++i) {
		if (s1[i] != s2[i]) ++cnt;
	}
	if (cnt & 1) {
		puts("-1");
		return 0;
	}
	i32 del = 0;
	for (i32 i = 0; i < n; ++i) {
		if (s1[i] != s2[i]) {
			if (std::abs(del) != cnt) {
				res[i] = '0';
				del += res[i] == s1[i] ? 1 : -1;
			}
			else {
				if (del < 0) res[i] = s1[i];
				else res[i] = s2[i];
			}
			cnt -= 1;
		}
		else res[i] = '0';
	}
	puts(res);
	return 0;
}
