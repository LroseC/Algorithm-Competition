#include <queue>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 6010, M = 1e7;

int idx = 1;
i32 head[N], nex[M], to[M], w[M];
i32 S, T;

void AddEdge(int u, int v, int wi)
{
	nex[++idx] = head[u];
	head[u] = idx;
	to[idx] = v; w[idx] = wi;
}
void addFlow(i32 u, i32 v, i32 w)
{
	AddEdge(u, v, w);
	AddEdge(v, u, 0);
}

namespace Dinic
{
	int dis[N], now[N];
	std::queue<int> q;
	bool BFS(void)
	{
		memset(dis, 0, sizeof dis);
		while (q.size()) q.pop();
		dis[S] = 1; now[S] = head[S]; q.emplace(S);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int e = head[u]; e; e = nex[e])
				if (!dis[to[e]] && w[e]) {
					q.emplace(to[e]);
					now[to[e]] = head[to[e]];
					dis[to[e]] = dis[u] + 1;
					if (to[e] == T) return 1;
				}
		}
		return 0;
	}
	int dfs(int u, int flow)
	{
		if (u == T) return flow;
		int rest = flow;
		for (int e = now[u]; e && rest; e = nex[e])
			if (w[e] && dis[u] + 1 == dis[to[e]]) {
				int tmp = dfs(to[e], std::min(rest, w[e]));
				if (!tmp) dis[to[e]] = 0;
				w[e] -= tmp;
				w[e ^ 1] += tmp;
				rest -= tmp;
			}
		return flow - rest;
	}
	i64 main(void)
	{
		i64 res = 0;
		while (BFS()) {
			res += dfs(S, INT_MAX);
		}
		return res;
	}
}

i32 n;

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i)
		for (i32 j = 1; j <= n; ++j) {
			i32 e; read >> e;
			if (e == 1) addFlow(i, j + n, 1);
		}
	S = 2 * n + 1, T = S + 1;
	for (i32 i = 1; i <= n; ++i) {
		addFlow(S, i, 1);
		addFlow(i + n, T, 1);
	}
	printf("%ld\n", Dinic::main());
	return 0;
}
