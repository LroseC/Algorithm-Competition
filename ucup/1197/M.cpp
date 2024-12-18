#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const int N = 1e5 + 10;

i32 n, a;
i32 b[N], w[N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> a;
	a = n - a;
	for (i32 i = 1; i <= n; ++i) {
		read >> b[i];
	}
	b[0] = b[n];
	b[n + 1] = b[1];
	std::vector<i32> wv;
	for (i32 i = 1; i <= n; ++i) {
		w[i] = !b[i - 1] + !b[i] + !b[i + 1];
		wv.emplace_back(w[i]);
	}
	std::sort(wv.begin(), wv.end(), std::greater<i32>());
	i32 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		if (b[i]) res += 3;
	}
	for (i32 i = 0; a && i < wv.size(); ++i, --a) {
		res += wv[i];
	}
	printf("%d\n", res);
	return 0;
}
