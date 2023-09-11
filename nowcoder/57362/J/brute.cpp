#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e5 + 10;

i32 n;
bool vis[N];
i32 ans[N];
i32 prime[N], v[N], idx;

void init(void)
{
	i32 n = 1e5;
	for (i32 i = 2; i <= n; ++i) {
		if (!v[i]) {
			v[i] = i;
			prime[++idx] = i;
		}
		for (i32 j = 1; j <= idx; ++j) {
			if (prime[j] * i > n) break;
			v[prime[j] * i] = prime[j];
			if (prime[j] == v[i]) break;
		}
	}
}
bool dfs(i32 pos)
{
	if (pos == n) return true;
	vis[ans[pos]] = 1;
	for (i32 i = 2; i <= 10; ++i) {
		if (ans[pos] + prime[i] <= n && !vis[ans[pos] + prime[i]]) {
			ans[pos + 1] = ans[pos] + prime[i];
			if (dfs(pos + 1)) return true;
		}
		if (ans[pos] - prime[i] >= 1 && !vis[ans[pos] - prime[i]]) {
			ans[pos + 1] = ans[pos] - prime[i];
			if (dfs(pos + 1)) return true;
		}
	}
	vis[ans[pos]] = 0;
	return 0;
}

void work(void)
{
	read >> n;
	if (n == 2) {
		puts("1 2");
		return;
	}
	if (n == 3) {
		puts("1 2 3");
		return;
	}
	if (n == 4) {
		puts("1 2 3 4");
		return;
	}
	if (n == 5) {
		puts("1 4 3 2 5");
		return;
	}
	if (n == 6) {
		puts("1 2 5 6 3 4");
		return;
	}
	if (n == 7) {
		puts("1 2 3 4 7 6 5");
		return;
	}
	
	for (i32 i = 1; i <= n; ++i)
		vis[i] = ans[i] = 0;
	bool fail = 1;
	for (i32 i = 1; i <= n; i += 2) {
		ans[1] = i;
		if (dfs(1)) {
			fail = 0;
			break;
		}
	}
	if (fail) puts("-1");
	else {
		for (i32 i = 1; i <= n; ++i)
			printf("%d ", ans[i]);
		puts("");
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	init();
	while (tt--) work();
	return 0;
}
