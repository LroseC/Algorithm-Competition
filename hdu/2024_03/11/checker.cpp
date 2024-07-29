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

int main(void)
{
	std::ios::sync_with_stdio(false);
	system("g++ maker.cpp -o maker -O2");
	system("g++ main.cpp -o main -O2");
	system("g++ brute.cpp -o brute -O2");
	i32 T = 0;
	while (++T <= 1000) {
		fprintf(stderr, "Test #%d\n", T);
		system("./maker > test.in");
		system("./main < test.in > test.out");
		system("./brute < test.in > test.ans");
		if (system("diff test.out test.ans")) {
			fprintf(stderr, "Wrong Answer.\n");
			break;
		} else {
			fprintf(stderr, "Accepted.\n");
		}
	}
	return 0;
}
