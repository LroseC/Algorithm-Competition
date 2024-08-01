#include <set>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int64_t;
using i64 = int64_t;
#define read std::cin
const int N = 5010;

i32 n;
i32 arr[N], gap[N][N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> arr[i];
	}
	for (i32 i = 1; i <= n; ++i) {
		i32 max = arr[i], min = arr[i];
		for (i32 j = i; j <= n; ++j) {
			max = std::max(max, arr[j]);
			min = std::min(min, arr[j]);
			gap[i][j] = max - min;
		}
	}
	i32 res = gap[1][n];
	std::set<i32> bound;
	bound.insert(1);
	bound.insert(n + 1);
	for (i32 i = 1; i <= n; ++i) {
		printf("%d\n", res);
		i32 tmpres = res + 1, tmp;
		for (auto it = bound.begin(); it != bound.end(); ++it) {
			auto jt = std::next(it);
			if (jt == bound.end()) break;
			i32 l = *it, r = *jt;
			for (i32 i = l + 1; i < r; ++i) {
				int uu = res - gap[l][r - 1] + gap[l][i - 1] + gap[i][r - 1];
				if (uu < tmpres) {
					tmpres = uu;
					tmp = i;
				}
			}
		}
		res = tmpres;
		bound.insert(tmp);
	}
	return 0;
}
