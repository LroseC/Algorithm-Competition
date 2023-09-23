#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

void work(void)
{
	i32 n; read >> n;
	std::vector<i32> odd, even;
	for (i32 i = 0; i < n; ++i) {
		i32 x; read >> x;
		if (x & 1) odd.emplace_back(i + 1);
		else even.emplace_back(i + 1);
	}
	if (odd.size() >= 3) {
		puts("YES");
		printf("%d %d %d\n", odd[0], odd[1], odd[2]);
	}
	else if (odd.size() && even.size() >= 2) {
		puts("YES");
		printf("%d %d %d\n", odd[0], even[0], even[1]);
	}
	else {
		puts("NO");
	}
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
