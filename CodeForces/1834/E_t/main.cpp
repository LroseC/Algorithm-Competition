#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pli = std::pair<i64, i32>;

#define read std::cin

i64 gcd(i64 a, i64 b)
{
	while (a) {
		b %= a;
		std::swap(a, b);
	}
	return b;
}
i64 lcm(i64 a, i64 b)
{ return a / gcd(a, b) * b; }

void work(void)
{
	i32 n; read >> n;
	std::vector<i32> arr(n);
	std::priority_queue<pli, std::vector<pli>, std::greater<pli>> heap;
	for (i32 i = 0; i < n; ++i) {
		read >> arr[i];
		heap.emplace(arr[i], i + 1);
	}
	i32 res = 1;
	while (heap.size()) {
		auto pr = heap.top(); heap.pop();
		if (pr.first > res) {
			std::cout << res << std::endl;
			return;
		}
		if (pr.first == res) res += 1;
		if (pr.second != n) {
			i64 sec = pr.second;
			i64 fir = lcm(pr.first, arr[sec]);
			heap.emplace(fir, sec + 1);
		}
	}
	std::cout << res << std::endl;
}

int main(void)
{
	//Think tiwce, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
