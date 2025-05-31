#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 5010;


i32 n;
char s[N], res[N], tmp[N];

bool cmp(char a[], char b[])
{
	for (i32 i = n - 1; i >= 0; --i) {
		if (a[i] < b[i]) return 1;
		if (a[i] > b[i]) return 0;
	}
	return 0;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		read >> s + 1;
		n = strlen(s + 1);
		pii respr = {0, 0};
		std::fill(res, res + n, '0');
		for (i32 i = n; i >= 1; --i) {
			strcpy(tmp, s + 1);
			std::reverse(tmp, tmp + n);
			i32 j;
			for (j = 1; j <= i; ++j) {
				i32 dig = i - j;
				if (tmp[dig] == '0' && s[j] == '1') {
					for (i32 jj = j; jj <= i; ++jj) {
						dig = i - jj;
						tmp[dig] = ((tmp[dig] - '0') ^ (s[jj] - '0')) + '0';
					}
					break;
				}
			}
			j = std::min(j, i);
			if (cmp(res, tmp)) {
				respr = std::make_pair(j, i);
				strcpy(res, tmp);
			}
		}
		std::reverse(res, res + n);
		printf("%d %d %d %d\n", 1, n, respr.first, respr.second);
	}
	return 0;
}
