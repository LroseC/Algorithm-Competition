#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	system("g++ rand.cpp -o rand -O2");
	system("g++ main.cpp -o main -O2");
	system("g++ brute.cpp -o brute -O2");
	int T = 1;
	while (T) {
		printf("#%d\n", T);
		system("./rand > test.in");
		system("./main < test.in > test.out");
		system("./brute < test.in > test.ans");
		if (system("diff test.out test.ans")) {
			puts("WA");
			return 0;
		}
		puts("AC");
	}
	return 0;
}
