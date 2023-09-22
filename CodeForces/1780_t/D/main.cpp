#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

void work(void)
{
	i32 res = 0;
	i32 totCnt; read >> totCnt;
	printf("- 1\n");
	fflush(stdout);
	i32 lastCnt; read >> lastCnt;
	assert(lastCnt >= 0);
	i32 lowZero;

	if (lastCnt == totCnt - 1) {
		lowZero = 0;
		res |= 1 << 0;
	}
	else {
		i32 delta = lastCnt - totCnt;
		lowZero = delta + 1;
		res |= 1 << lowZero;
	}
	totCnt -= 1;

	while (totCnt) {
		printf("- %d\n", 1 << lowZero);
		fflush(stdout);
		i32 tCnt; read >> tCnt;
		assert(tCnt >= 0);
		i32 delta = tCnt - lastCnt;
		lowZero += delta + 1;
		lastCnt = tCnt;
		res |= 1 << lowZero;
		totCnt -= 1;
	}
	printf("! %d\n", res);
	fflush(stdout);
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
