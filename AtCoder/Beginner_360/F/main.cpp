#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using Pii = std::pair<i32, i32>;

#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	std::vector<Pii> line(n);
	std::vector<i32> l(n), r(n);
	for (i32 i = 0; i < n; ++i) {
		read >> line[i].first >> line[i].second;
	}
	std::sort(line.begin(), line.end());
	for (i32 i = 0; i < n; ++i) {
		l[i] = line[i].first;
		r[i] = line[i].second;
	}

	i32 res = 0;
	std::pair<i32, i32> res_pair(0, 0);
	std::priority_queue<i32, std::vector<i32>, std::greater<i32>> heap;
	for (i32 i = 0; i < n; ++i) {
		if (r[i] == 1e9) continue;
		heap.emplace_back(r[i]);
		max_r = std::max(max_r, r[i]);
		while (l[i] + 1 >= heap.top()) heap.pop();
		if (heap.size() > res) {
			res = heap.size();
			res_pair = std::make_pair(l[i] + 1, max_r + 1);
		}
	}
	std::cout << res_pair.first << res_pair.second;
	return 0;
}
