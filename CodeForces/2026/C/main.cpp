#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const int N = 4e5 + 10;

char s[N];

void work(void)
{
	i32 n;
	read >> n;
	read >> s + 1;
	i64 res = 0, max = n;
	i32 borrow = 0;
	for (i32 i = n; i >= 1; --i) {
		if (i == borrow) {
			borrow -= 1;
			res += i;
		}
		else if (s[i] == '1' && borrow + 1 <= i - 1) {
			borrow += 1;
		} else {
			res += i;
			borrow -= 1;
			borrow = std::max(0, borrow);
		}
	}
	printf("%lld\n", res);
}
void clear(void) {}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	return 0;
}
