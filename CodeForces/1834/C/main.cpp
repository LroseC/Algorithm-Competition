#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e5;

i32 n;
char s1[N + 10], s2[N + 10];

i32 calc(void)
{
	i32 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		res += s1[i] != s2[i];
	}
	return res;
}

void work(void)
{
	read >> n;
	read >> s1 + 1 >> s2 + 1;
	i32 t1 = calc();
	if (t1 & 1) {
		t1 = t1 * 2 - 1;
	}
	else {
		t1 = t1 * 2;
	}
	std::reverse(s2 + 1, s2 + 1 + n);
	i32 t2 = calc();
	if (t2 == 0) {
		t2 = 2;
	}
	else if (t2 & 1) {
		t2 = t2 * 2;
	}
	else {
		t2 = t2 * 2 - 1;
	}
	printf("%d\n", std::min(t1, t2));
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
