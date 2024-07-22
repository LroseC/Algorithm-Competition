#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 5e4 + 10, D = 110;

i32 n, m, d, K;
bool vis[N];
i32 fa[D][N], sz[N];

i32 find(i32 d, i32 u)
{
	return fa[d][u] == u ? u : fa[d][u] = find(d, fa[d][u]);
}
void merge(i32 d, i32 u, i32 v)
{
	u = find(d, u);
	v = find(d, v);
	if (u != v) {
		fa[d][v] = u;
		if (d == 0) {
			sz[u] += sz[v];
		}
	}
}
bool check(i32 u, i32 v)
{
	for (i32 i = 1; i <= d; ++i) {
		if (find(i, u) != find(i, v)) {
			return 0;
		}
	}
	return 1;
}

void work(void)
{
	read >> n >> m >> d >> K;
	d += 1;
	for (i32 i = 1; i <= n; ++i) {
		vis[i] = 0;
		fa[0][i] = i;
		sz[i] = 1;
	}
	for (i32 i = 1; i <= m; ++i) {
		i32 u, v; read >> u >> v;
		merge(0, u, v);
	}
	for (i32 i = 1; i <= d; ++i) {
		memcpy(fa[i], fa[0], sizeof fa[0]);
	}

	i64 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		i32 u = find(0, i);
		if (vis[u]) continue;
		vis[u] = 1;
		res += 1ll * sz[u] * (sz[u] - 1) / 2;
	}

	for (i32 i = 1; i <= K; ++i) {
		i32 u, v, w;
		read >> u >> v >> w;
		if (find(w, u) != find(w, v)) {
			merge(w, u, v);
			if (check(u, v)) {
				u = find(0, u), v = find(0, v);
				res -= 1ll * sz[u] * (sz[u] - 1) / 2;
				res -= 1ll * sz[v] * (sz[v] - 1) / 2;
				merge(0, u, v);
				u = find(0, u);
				res += 1ll * sz[u] * (sz[u] - 1) / 2;
			}
		}
		std::cout << res << '\n';
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
