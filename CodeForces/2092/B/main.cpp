#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const int N = 2e5 + 10;

char a[N], b[N];

void work(void)
{
	int n;
	read >> n;
	read >> a >> b;
	i32 cnt[2] = {0, 0};
	i32 cnt1[2] = {0, 0};
	for (i32 i = 0; i < n; ++i) {
		cnt1[i & 1] += a[i] - '0';
		cnt1[(i ^ 1) & 1] += b[i] - '0';
		cnt[(i ^ 1) & 1] += 1;
	}
	if (cnt[0] >= cnt1[0] && cnt[1] >= cnt1[1]) {
		puts("YES");
	} else {
		puts("NO");
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
