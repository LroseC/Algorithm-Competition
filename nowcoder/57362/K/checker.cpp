#include <cctype>
#include <cstdio>
#include <cstdint>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

int main(void)
{
	system("g++ rand.cpp -o rand -O2");
	system("g++ main.cpp -o main -O2");
	system("g++ brute.cpp -o brute -O2");
	i32 T = 0;
	while (++T) {
		fprintf(stderr, "Task #%d:\n", T);
		system("./rand > test.in");
		system("./main < test.in > test.out");
		system("./brute < test.in > test.ans");
		if (system("diff test.out test.ans")) {
			fprintf(stderr, "WA\n");
			exit(0);
		}
		else fprintf(stderr, "Accepted.\n");
	}
	return 0;
}
