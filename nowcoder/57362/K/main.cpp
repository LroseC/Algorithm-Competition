#include <vector>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

i32 n, m;

std::pair<i32, i32> check(std::vector<std::vector<i32>> &val)
{
	std::vector<std::pair<i32, i32>> t(m);
	for (i32 i = 0; i < m; ++i) {
		t[i].first = val[0][i];
		t[i].second = i;
	}
	std::vector<std::vector<i32>> vp(n);
	for (i32 i = 0; i < n; ++i) vp[i].resize(m);
	std::sort(t.begin(), t.end());

	i32 cntFox = 0, cntCat = 0;
	for (i32 i = 0; i < m; ++i)
		for (i32 j = 0; j < i; ++j)
			if (val[0][j] > val[0][i]) ++cntCat;
	for (i32 i = 0; i < n; ++i)
		for (i32 j = 0; j < i; ++j)
			if (val[j][0] > val[i][0]) ++cntFox;

	for (i32 j = 0; j < m; ++j) {
		for (i32 i = 0; i < n; ++i)
			vp[i][j] = val[i][t[j].second];
	}
	for (i32 i = 0; i < n; ++i) {
		if (!std::is_sorted(vp[i].begin(), vp[i].end())) return std::make_pair(-1, -1);
		if ((vp[i].front() - 1) % m || (vp[i].back()) % m) return std::make_pair(-1, -1);
	}
	return std::make_pair(cntFox, cntCat);
}
bool checkOnce(std::vector<std::vector<i32>> &val)
{
	i32 cnt = 0;
	for (i32 i = 0; i < n; ++i) {
		if (!std::is_sorted(val[i].begin(), val[i].end())) return 0;
		if ((val[i][0] - 1) / m != i) ++cnt;
	}
	return cnt == 2;
}
inline bool checkSorted(std::vector<std::vector<i32>> &val)
{ return val[0][0] == 1 && val[0][1] == 2 && val[1][0] == 3 && val[1][1] == 4; }

void work(void)
{
	read >> n >> m;
	std::vector<std::vector<i32>> val(n);
	for (i32 i = 0; i < n; ++i) {
		val[i].resize(m);
		for (i32 j = 0; j < m; ++j)
			read >> val[i][j];
	}
	std::pair<i32, i32> cnt = check(val);
//	fprintf(stderr, "%d %d\n", cnt.first, cnt.second);
	if (cnt.first == -1) puts("NSFW");
	else if (n > 2 && m > 2) {
		if (checkOnce(val)) puts("FOX");
		else puts("NSFW");
	}
	else if (n == 2 && m == 2) {
		bool fail = 1;
		for (i32 i = 1; i <= 100; ++i) {
			if (i & 1) {
				std::swap(val[0], val[1]);
				if (checkSorted(val)) {
					puts("FOX");
					fail = 0;
					break;
				}
			}
			else {
				std::swap(val[0][0], val[0][1]);
				std::swap(val[1][0], val[1][1]);
				if (checkSorted(val)) {
					puts("CAT");
					fail = 0;
					break;
				}
			}
		}
		assert(fail == 0);
	}
	else if (n == 2) {
		if (checkOnce(val)) puts("FOX");
		else {
			if (cnt.first % 2 == cnt.second % 2)
				puts("CAT");
			else
				puts("NSFW");
		}
	}
	else {
		if (cnt.first % 2 != cnt.second % 2)
			puts("FOX");
		else
			puts("NSFW");
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) work();
	return 0;
}
