#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

i32 pw10[10];

void work(void)
{
	i32 A, B, C;
	i64 K;
	read >> A >> B >> C >> K;
	for (i32 i = pw10[A - 1]; i < pw10[A]; ++i) {
		auto calc = [&](i32 x) {
			i32 l = std::max(pw10[C - 1] - x, pw10[B - 1]);
			i32 r = std::min(pw10[C] - x, pw10[B]);
			return std::make_pair(l, r);
		};
		std::pair<i32, i32> tmp = calc(i);
		if (tmp.first >= tmp.second) continue;
		if (tmp.second - tmp.first < K) K -= tmp.second - tmp.first;
		else {
			printf("%lld + %lld = %lld\n", (i64)i, (i64)tmp.first + K - 1, (i64)i + tmp.first + K - 1);
			return;
		}
	}
	puts("-1");
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	pw10[0] = 1;
	for (i32 i = 1; i <= 9; ++i)
		pw10[i] = pw10[i - 1] * 10;
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
