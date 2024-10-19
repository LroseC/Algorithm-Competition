#include <bits/stdc++.h>
using namespace std;

using i32 = int;

void print(i32 x)
{
	static char buf[100];
	i32 top = 0;
	while (x) {
		buf[top] = x % 2 + '0';
		x /= 2;
		top += 1;
	}
	buf[top] = 0;
	std::reverse(buf, buf + top);
	if (top == 0) {
		putchar('0');
	}
	printf("%s", buf);
}

int main(void)
{
	srand(time(NULL));
	int t = 10;
	printf("%d\n", t);
	while (t--) {
		int u = rand() % 10, v = rand() % 10;
		int k = rand() % 3 + 1;
		print(u);
		putchar(' ');
		print(v);
		putchar(' ');
		printf("%d\n", k);
	}
	return 0;
}
