#include <vector>
#include <cstdio>
#include <cctype>
#include <cstdint>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

void work(void)
{
	i32 n, K;
	read >> n >> K;
	std::vector<i32> arr(n);
	for (i32 i = 0; i < n; ++i) {
		read >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	for (i32 i = n - 1; i > 0; --i) {
		arr[i] -= arr[i - 1];
	}
	i32 res = 0, cnt = n;
	for (i32 i = 0; i < n; ++i) {
		if (K <= 1ll * cnt * arr[i]) {
			printf("%d\n", res + K);
			return;
		} else {
			K -= 1ll * cnt * arr[i];
			res += 1ll * cnt * arr[i] + 1;
			cnt -= 1;
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
