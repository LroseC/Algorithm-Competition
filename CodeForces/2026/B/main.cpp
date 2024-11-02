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

void clear(void) {}
void work(void)
{
	i32 n;
	read >> n;
	std::vector<i64> a(n);
	for (i32 i = 0; i < n; ++i) {
		read >> a[i];
	}
	if (n % 2) {
		i64 tot_k = LLONG_MAX;
		for (i32 i = 0; i < n; ++i) {
			i64 k = 1;
			for (i32 j = 0, nex = 0; j < n; j = nex + 1) {
				if (j == i) j += 1;
				if (j == n) break;
				nex = j + 1;
				if (nex == i) nex += 1;
				k = std::max(k, a[nex] - a[j]);
			}
			tot_k = std::min(tot_k, k);
		}
		printf("%lld\n", tot_k);
	} else {
		i64 k = 1;
		for (i32 i = 0; i < n; i += 2) {
			k = std::max(k, a[i + 1] - a[i]);
		}
		printf("%lld\n", k);
	}
}

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
