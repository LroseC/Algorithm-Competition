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
	i32 n, K;
	read >> n >> K;
	std::vector<i32> a(n), vis(n);
	for (i32 i = 0; i < n; ++i)
		read >> a[i];
	bool fail = 0;
	for (i32 i = 0; i < n; ++i)
		if (!vis[i]) {
			std::vector<i32> val;
			for (i32 j = i; !vis[j]; j = (j + K) % n) {
				vis[j] = 1;
				val.emplace_back(a[j]);
			}
			i32 mn = 0;
			for (i32 i = 0; i < val.size(); ++i)
				if (val[i] < val[mn]) mn = i;
			for (i32 i = 0, pos = mn; i < val.size(); ++i, pos = (pos + 1) % val.size()) {
				i32 t = std::min(val[pos], val[(pos + 1) % val.size()]);
				val[pos] -= t;
				val[(pos + 1) % val.size()] -= t;
			}
			for (i32 i = 0; i < val.size(); ++i)
				if (val[i]) fail = 1;
		}
	puts(fail ? "NO" : "YES");
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
