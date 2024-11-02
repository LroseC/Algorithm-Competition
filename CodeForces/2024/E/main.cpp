#include <queue>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstdint>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 2e5 + 10;

i32 n, K, mod, m1, m2;
bool vis[N], flg1[N], flg2[N];
i32 d1[N], d2[N];
std::vector<i32> G1[N], G2[N];

i32 mod_add(i32 x, i32 y)
{
	x += y;
	return x >= mod ? x - mod : x;
}

void clear(void)
{
	for (i32 i = 1; i <= n; ++i) {
		G1[i].clear();
		G2[i].clear();
	}
}

void add_edge1(i32 u, i32 v)
{
	G1[u].emplace_back(v);
}
void add_edge2(i32 u, i32 v)
{
	G2[u].emplace_back(v);
}
void bfs1(i32 S)
{
	std::queue<i32> q;
	q.emplace(S);
	d1[S] = 0;
	while (q.size()) {
		i32 u = q.front();
		q.pop();
		vis[u] = 1;
		for (i32 v: G1[u]) {
			if (vis[v]) continue;
			d1[v] = mod_add(d1[u], 1);
			q.emplace(v);
		}
	}
	for (i32 i = 1; i <= n; ++i) {
		vis[i] = 0;
	}
}
void bfs2(i32 S)
{
	std::queue<i32> q;
	q.emplace(S);
	d2[S] = 0;
	while (q.size()) {
		i32 u = q.front();
		q.pop();
		vis[u] = 1;
		for (i32 v: G2[u]) {
			if (vis[v]) continue;
			d2[v] = mod_add(d2[u], 1);
			q.emplace(v);
		}
	}
	for (i32 i = 1; i <= n; ++i) {
		vis[i] = 0;
	}
}

void work(void)
{
	read >> n >> K;
	mod = K;
	for (i32 i = 1; i <= n; ++i) {
		read >> flg1[i];
	}
	read >> m1;
	for (i32 i = 0; i < m1; ++i) {
		i32 u, v;
		read >> u >> v;
		add_edge1(u, v);
	}
	for (i32 i = 1; i <= n; ++i) {
		read >> flg2[i];
	}
	read >> m2;
	for (i32 i = 0; i < m2; ++i) {
		i32 u, v;
		read >> u >> v;
		add_edge2(u, v);
	}
	bfs1(1);
	bfs2(1);
	i32 cnt1 = 0, cnt2 = 0;
	for (i32 i = 1; i <= n; ++i) {
		cnt1 += flg1[i];
		cnt2 += flg2[i];
	}
	if (cnt1 + cnt2 != n) {
		puts("No");
		return;
	}
	if (!cnt1 || !cnt2) {
		puts("Yes");
		return;
	}
	if (__builtin_popcount(K) == 1) {
		puts("Yes");
	} else {
		puts("No");
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
