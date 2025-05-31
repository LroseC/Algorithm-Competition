#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const int N = 3e3 + 10;

i32 n, m;
i32 a[N << 1];
i32 vis[N][N];

void clear(void)
{
	for (i32 i = 1; i <= n * 2; ++i)
		for (i32 j = 1; j <= n * 2 - 1; ++j)
			vis[i][j] = 0;
}

i32 node(i32 lr, i32 ud, i32 id)
{
	if (lr == 0) {
		if (ud == 0)
			return id;
		else
			return 2 * n - id + 1;
	} else {
		if (ud == 0)
			return id;
		else
			return 2 * n - id;
	}
}
void add_edge(i32 u, i32 v, i32 x)
{
	vis[u][v] = x;
}
void work(void)
{
	read >> n >> m;
	if (n * 2 <= m) {
		puts("NO");
		return;
	}
	puts("YES");
	for (i32 i = 1; i <= n; ++i) {
		a[i] = i;
		a[i + n] = i;
	}
	for (i32 i = 1; i <= n; ++i) {
		i32 mid = a[i + n - 1];
		for (i32 j = 1; j <= n; ++j) {
			i32 rid = j;
			for (i32 t = -1; t <= 0; ++t) {
				if (j == n && t == 0) continue;
				i32 uid = a[i + j + t];
				if (vis[node(0, 0, uid)][node(1, 0, rid)]) {
					add_edge(node(0, 0, uid), node(1, 1, rid), i);
					add_edge(node(0, 1, uid), node(1, 0, rid), i);
				} else {
					add_edge(node(0, 0, uid), node(1, 0, rid), i);
					add_edge(node(0, 1, uid), node(1, 1, rid), i);
				}
			}
		}
	}
	for (i32 i = 1; i <= 2 * n; ++i) {
		for (i32 j = 1; j <= m; ++j) {
			printf("%d ", vis[i][j]);
		}
		puts("");
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
