#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e5 + 10;

char str[N], ans[N];

void work(void)
{
	i32 n; read >> n;
	read >> str + 1;
	i32 cnt[2] = {0, 0};
	for (i32 i = 1, j = n; i < j; ++i, --j) {
		cnt[str[i] != str[j]] += 1;
	}
	for (i32 i = 0; i < cnt[1]; ++i)
		ans[i] = '0';
	i32 i = cnt[1];
	while (cnt[0] >= 0) {
		if (n & 1) ans[i] = '1', ans[i + 1] = '1';
		else ans[i] = '1', ans[i + 1] = '0';
		i += 2;
		--cnt[0];
	}
	while (i <= n) {
		ans[i] = '0';
		i += 1;
	}
	ans[n + 1] = 0;
	std::cout << ans << std::endl;
}

int main(void)
{
	//Think tiwce, code once? I'm back.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
