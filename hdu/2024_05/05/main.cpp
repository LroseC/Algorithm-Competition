#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 1e6 + 10;

i32 n;
pii edge[N];
i32 dep[N], fa_ed[N];
std::vector<i32> G[N];
i32 res[N];


i32 get_to(i32 e, i32 u)
{
	pii ed = edge[e];
	if (ed.first == u) return ed.second;
	return ed.first;
}

namespace dsu
{
	i32 fa[N];
	void init(void)
	{
		for (i32 i = 1; i <= n; ++i) {
			fa[i] = i;
		}
	}
	i32 find(i32 u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
	void merge(i32 u, i32 v)
	{
		u = find(u), v = find(v);
		if (u != v) fa[u] = v;
	}
}

void dfs(i32 u, i32 fa)
{
	for (auto e: G[u]) {
		i32 v = get_to(e, u);
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		fa_ed[v] = e;
		dfs(v, u);
	}
}
void init_tree(void)
{
	dep[1] = 1;
	dfs(1, 1);
}
void merge(i32 u, i32 v, i32 w)
{
	u = dsu::find(u);
	v = dsu::find(v);
	while (u != v) {
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		res[fa_ed[u]] = std::max(res[fa_ed[u]], w);
		dsu::merge(u, get_to(fa_ed[u], u));
		u = dsu::find(u);
	}
}
void clear(void)
{
	for (i32 i = 1; i <= n; ++i) {
		G[i].clear();
	}
	std::memset(edge, 0, sizeof edge);
	std::memset(dep, 0, sizeof dep);
	std::memset(fa_ed, 0, sizeof fa_ed);
	std::memset(res, 0, sizeof res);
}
void work(void)
{
	read >> n;
	dsu::init();
	for (i32 i = 1; i < n; ++i) {
		i32 u, v; read >> u >> v;
		edge[i] = std::make_pair(u, v);
		G[u].emplace_back(i);
		G[v].emplace_back(i);
	}
	init_tree();
	for (i32 i = n; i >= 1; --i) {
		for (i32 j = i * 2; j <= n; j += i) {
			merge(i, j, i);
		}
	}
	for (i32 i = 1; i < n; ++i) {
		printf("%d ", res[i]);
	}
	puts("");
}

int main(void)
{
	int size(256<<20); //256M
	__asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	exit(0);
	return 0;
}
