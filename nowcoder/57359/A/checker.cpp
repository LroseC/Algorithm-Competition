#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

int main(void)
{
	std::ios::sync_with_stdio(false);
	system("g++ rand.cpp -o rand");
	system("g++ tmp.cpp -o main -O2 -fsanitize=undefined");
	i32 T = 1;
	while (T) {
		fprintf(stderr, "task #%d\n", T);
		system("./rand > test.in");
		system("time ./main < test.in > test.out");
		T += 1;
	}
	return 0;
}
