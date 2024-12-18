#include <queue>
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
using pli = std::pair<i64, i32>;
#define read std::cin

const int N = 1e5 + 10;

i32 n, m, K, D;
bool vis[N];
i64 dis[N], disK[N], cost[N], f[N];
std::vector<i32> G[N];

i64 get_sum(i32 x)
{
	return 1ll * (D + (D - x + 1)) * x / 2;
}
void bfs(i32 S, i64 *d)
{
	std::queue<i32> q;
	q.emplace(S);
	d[S] = 0;
	vis[S] = 1;
	while (q.size()) {
		i32 u = q.front(); q.pop();
		for (auto v: G[u]) {
			if (vis[v]) continue;
			d[v] = d[u] + 1;
			vis[v] = 1;
			q.emplace(v);
		}
	}
	std::fill(vis + 1, vis + 1 + n, 0);
}
void dij(i32 S)
{
	std::memset(f, 0x3f, sizeof f);
	std::priority_queue<pli, std::vector<pli>, std::greater<pli>> heap;
	for (auto v: G[S]) {
		f[v] = D - disK[v];
		if (f[v] <= 0) {
			f[v] = 0;
		}
		else {
			heap.emplace(f[v], v);
		}
	}
	while (heap.size()) {
		auto pr = heap.top(); heap.pop();
		i32 u = pr.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v: G[u]) {
			if (vis[v]) continue;
			if (disK[v] > D) continue;
			if (disK[v] == D) {
				f[v] = std::min(f[v], f[u]);
			}
			else if (f[u] + D - disK[v] < f[v]) {
				f[v] = f[u] + D - disK[v];
				heap.emplace(f[v], v);
			}
		}
	}
	for (i32 i = 1; i <= n; ++i)
		vis[i] = 0;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> m >> K >> D;
	for (i32 i = 1; i <= m; ++i) {
		i32 u, v;
		read >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	bfs(n, dis);
	for (i32 i = 1; i <= n; ++i) {
		cost[i] = (dis[i] / D) * get_sum(D) + get_sum(dis[i] % D + 1);
	}
	bfs(K, disK);
	dij(1);
	i64 res = f[n] + (disK[n] >= D ? D : 0);
	for (i32 i = 1; i <= n; ++i) {
		if (disK[i] >= D)
			res = std::min(res, cost[i] + f[i]);
	}
	printf("%lld\n", res);
	return 0;
}
