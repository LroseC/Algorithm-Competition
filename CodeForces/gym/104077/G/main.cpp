#include <set>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define read std::cin

const int N = 1e5 + 10;

i32 n;
u64 tHash[N], pw[N];

void initHash(void)
{
	pw[0] = 1;
	for (i32 i = 1; i < N; ++i)
		pw[i] = pw[i - 1] * 1331;
}
u64 getHash(std::string &str)
{
	tHash[0] = str[0];
	for (i32 i = 1; i < str.size(); ++i) {
		tHash[i] = tHash[i - 1] * 1331 + str[i];
	}
	return tHash[str.size() - 1];
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	read >> n;
	initHash();
	std::vector<std::string> str(n);
	std::vector<std::set<u64>> hsh(n);
	for (i32 i = 0; i < n; ++i) read >> str[i];
	auto cmp = [](std::string &a, std::string &b) { return a.size() < b.size(); };
	std::sort(str.begin(), str.end(), cmp);
	i32 res = 0;
	hsh[0].emplace(0);
	for (i32 i = 0; i < n; ++i) {
		i32 len = str[i].size();
		u64 sh = getHash(str[i]);
		if (hsh[len - 1].count(tHash[len - 2]) && hsh[len - 1].count(sh - str[i][0] * pw[len - 1])) {
			hsh[len].emplace(sh);
			res = std::max(res, len);
		}
	}
	printf("%d\n", res);
	return 0;
}
