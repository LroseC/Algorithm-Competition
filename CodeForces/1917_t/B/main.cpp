#include <vector>
#include <string>
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
	std::string s; read >> s;
	i32 cnt = 0;
	i64 res = 0;
	std::vector<i32> vis(26);
	for (i32 i = 0; i < n; ++i) {
		if (!vis[s[i] - 'a']) {
			cnt += 1;
			vis[s[i] - 'a'] = 1;
		}
		res += cnt;
	}
	printf("%lld\n", res);
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) work();
	return 0;
}
