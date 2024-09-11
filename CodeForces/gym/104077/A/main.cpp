#include <map>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin
#define mkp std::make_pair

const int N = 6e5 + 10;

i32 n, m, Q;
bool vis[N];
i32 fa[N], sz[N], res[N], ans[N];
i32 top;
pii backup[(int)2e7];
std::vector<pii> id2pos;
std::map<pii, i32> pos2id;
std::vector<pii> edge[N];
std::vector<pii> qnode[N];

void addEdge(i32 L, i32 R, pii e, i32 u = 1, i32 l = 0, i32 r = Q - 1)
{
	if (L > R) return;
	if (L <= l && r <= R) {
		edge[u].emplace_back(e);
		return;
	}
	i32 mid = l + r >> 1;
	if (L <= mid)
		addEdge(L, R, e, u << 1, l, mid);
	if (R >= mid + 1)
		addEdge(L, R, e, u << 1 | 1, mid + 1, r);
}
void addQuery(i32 pos, i32 id, i32 q, i32 u = 1, i32 l = 0, i32 r = Q - 1)
{
	if (l == r) {
		qnode[u].emplace_back(mkp(q, id));
		return;
	}
	i32 mid = l + r >> 1;
	if (pos <= mid)
		addQuery(pos, id, q, u << 1, l, mid);
	else
		addQuery(pos, id, q, u << 1 | 1, mid + 1, r);
}
i32 find(i32 x)
{
	while (x != fa[x])
		x = fa[x];
	return x;
}
void merge(i32 u, i32 v)
{
	u = find(u), v = find(v);
	if (sz[u] > sz[v])
		std::swap(u, v);
	// sz[u] <= sz[v];
	backup[++top] = mkp(u, -1);
	fa[u] = v;
	backup[++top] = mkp(v, res[v]);
	res[v] += res[u];
}
void resume(void)
{
	pii t = backup[top--];
	if (t.second == -1) fa[t.first] = t.first;
	else res[t.first] = t.second;
}
void dfs(i32 u = 1, i32 l = 0, i32 r = Q - 1)
{
	i32 ttop = top;
	for (auto e : edge[u]) {
		merge(e.first, e.second);
	}
	if (l == r) {
		for (auto q : qnode[u]) {
			i32 t = q.first, id = q.second;
			ans[id] = res[find(pos2id[mkp(t, 1)])];
		}
	}
	else {
		i32 mid = l + r >> 1;
		dfs(u << 1, l, mid);
		dfs(u << 1 | 1, mid + 1, r);
	}
	while (top != ttop) resume();
}
void initMerge(void)
{
	for (i32 i = 0; i < id2pos.size(); ++i) {
		fa[i] = i;
		sz[i] = 1;
		pii pos = id2pos[i];
		if (pos.second == m + 1)
			res[i] = pos.first;
	}
}

int main(void)
{
	//Think twice, code once.
	std::ios::sync_with_stdio(false);
	read >> n >> m >> Q;
	std::vector<pii> query;
	for (i32 i = 0; i < Q; ++i) {
		i32 op, a, b = -1;
		read >> op >> a;
		if (op == 1) {
			read >> b;
			id2pos.emplace_back(a, b);
			id2pos.emplace_back(a + 1, b);
		}
		query.emplace_back(a, b);
	}
	for (i32 i = 1; i <= n; ++i) {
		id2pos.emplace_back(i, 1);
		id2pos.emplace_back(i, m + 1);
	}
	std::sort(id2pos.begin(), id2pos.end());
	id2pos.erase(std::unique(id2pos.begin(), id2pos.end()), id2pos.end());
	for (i32 i = 0; i < id2pos.size(); ++i) {
		pos2id[id2pos[i]] = i;
	}
	i32 qcnt = 0;
	for (i32 i = 0; i < Q; ++i) {
		if (query[i].second != -1) {
			i32 id1 = pos2id[mkp(query[i].first, query[i].second)];
			i32 id2 = pos2id[mkp(query[i].first + 1, query[i].second)];
			vis[id1] = 1;
			vis[id2] = 1;
			addEdge(0, i - 1, mkp(id1, id1 + 1));
			addEdge(i, Q - 1, mkp(id1, id2 + 1));
			addEdge(0, i - 1, mkp(id2, id2 + 1));
			addEdge(i, Q - 1, mkp(id2, id1 + 1));
		}
		else {
			addQuery(i, qcnt++, query[i].first);
		}
	}
	for (i32 i = 0; i < id2pos.size(); ++i)
		if (!vis[i] && id2pos[i].second != m + 1) {
			addEdge(0, Q - 1, mkp(i, i + 1));
		}
	initMerge();
	dfs();
	for (i32 i = 0; i < qcnt; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
