#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

void work(void)
{
	i32 n, m;
	read >> n >> m;
	std::vector<i32> a(n), b(m);
	for (i32 i = 0; i < n; ++i) {
		read >> a[i];
	}
	bool sec = 1;
	for (i32 i = 0, j = 0; j < m; ++j) {
		read >> b[j];
		while (i < n && a[i] != b[j]) {
			i += 1;
		}
		if (i >= n || a[i] != b[j]) sec = 0;
		i += 1;
	}
	puts(sec ? "Yes" : "No");
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
