#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

void work(void)
{
	i32 n;
	read >> n;
	n *= 2;
	std::vector<i32> cnt(n + 1);
	for (i32 i = 1; i <= n; ++i) {
		i32 x; read >> x;
		cnt[x] += 1;
	}
	i32 cnt1 = 0;
	std::priority_queue<i32, std::vector<i32>, std::greater<i32>> heap;
	for (i32 i = 1; i <= n; ++i) {
		if (cnt[i]) {
			if (cnt[i] == 1) {
				cnt1 += 1;
			} else {
				heap.emplace(cnt[i]);
			}
		}
	}
	while (cnt1 || heap.size()) {
		if (!cnt1) {
			puts("Qingyu");
			return;
		}
		if (!heap.size()) {
			puts("Kevin");
			return;
		}
		i32 u = heap.top();
		heap.pop();
		u -= 1;
		if (u == 1) {
			cnt1 += 1;
		} else {
			heap.emplace(u);
		}
		cnt1 -= 1;
	}
	puts("Kevin");
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
