#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 5e5 + 10;

i32 n;
i32 stk[N], top;

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	i64 res = 0;
	for (int i = 1; i <= n; ++i) {
		i32 x; read >> x;
		if (x != 1) {
			while (top && x != stk[top] + 1)
				top -= 1;
			if (top) stk[top] += 1;
		}
		else {
			stk[++top] = x;
		}
		res += top;
	}
	printf("%ld\n", res);
	return 0;
}
