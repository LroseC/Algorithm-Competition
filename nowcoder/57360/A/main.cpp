#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin
#define x first
#define y second

const int N = 3010;

i32 n, idx;
i32 fa[N << 1];
i64 f[N << 1][N];
std::vector<i32> G[N << 1];
i32 color[N], cost[N], val[N << 1], sz[N << 1];

i32 find(i32 x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void dp(i32 u)
{
	if (!G[u].size()) {
		sz[u] = 1;
		f[u][color[u]] = 0;
		f[u][color[u] ^ 1] = -cost[u];
		return;
	}
	i32 l = G[u][0];
	i32 r = G[u][1];
	dp(l);
	dp(r);
	sz[u] = sz[l] + sz[r];
	for (i32 i = 0; i <= sz[l]; ++i)
		for (i32 j = 0; j <= sz[r]; ++j) {
			i64 tmp = f[l][i] + f[r][j] + val[u] * ((i64)(sz[l] - i) * j + (i64)(sz[r] - j) * i);
			f[u][i + j] = std::max(f[u][i + j], tmp);
		}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	std::memset(f, 0xcf, sizeof f);
	for (i32 i = 1; i <= n; ++i) {
		read >> color[i];
	}
	for (i32 i = 1; i <= n; ++i) {
		read >> cost[i];
	}
	std::vector<std::pair<i32, std::pair<i32, i32>>> edge;
	for (i32 i = 1; i < n; ++i) {
		i32 u, v, w;
		read >> u >> v >> w;
		edge.emplace_back(w, std::make_pair(u, v));
	}
	std::sort(edge.begin(), edge.end());
	idx = n;
	for (i32 i = 1; i <= n * 2 - 1; ++i)
		fa[i] = i;
	for (auto e : edge) {
		i32 u = ++idx;
		val[u] = e.x;
		i32 l = find(e.y.x);
		i32 r = find(e.y.y);
		G[u].emplace_back(l);
		G[u].emplace_back(r);
		fa[l] = fa[r] = u;
	}
	dp(idx);
	i64 res = 0;
	for (i32 i = 0; i <= n; ++i) {
		res = std::max(res, f[idx][i]);
	}
	printf("%ld\n", res);
	return 0;
}
