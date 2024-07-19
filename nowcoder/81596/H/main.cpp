#include <set>
#include <string>
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

using Psp = std::pair<std::string, std::pair<i32, i32>>;

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 n, m;
	read >> n;
	Psp x1, x2;
	std::vector<Psp> arr1(n);
	std::set<std::string> S1, S;
	for (i32 i = 0; i < n; ++i) {
		read >> arr1[i].first >> arr1[i].second.first >> arr1[i].second.second;
		S1.insert(arr1[i].first);
		arr1[i].second.second = - arr1[i].second.second;
		if (arr1[i].first == "lzr010506")
			x1 = arr1[i];
	}
	read >> m;
	std::vector<Psp> arr2(n);
	for (i32 i = 0; i < m; ++i) {
		std::string s; i32 a, b;
		read >> s >> a >> b;
		if (S1.find(s) != S1.end()) {
			S.insert(s);
		}
		arr2[i] = std::make_pair(s, std::make_pair(a, -b));
		if (arr2[i].first == "lzr010506")
			x2 = arr2[i];
	}
	i32 res = 0;
	i32 rk = 0;
	for (i32 i = 0; i < n; ++i) {
		if (S.find(arr1[i].first) != S.end()) continue;
		if (arr1[i].second > x1.second) {
			res += 1;
		}
	}
	for (i32 i = 0; i < m; ++i) {
		if (S.find(arr2[i].first) != S.end()) continue;
		if (arr2[i].second > x2.second) {
			rk += 1;
		}
	}
	printf("%d\n", std::min(res, rk) + 1);
	return 0;
}
