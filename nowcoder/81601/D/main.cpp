#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 1e5 + 10;


i32 n, m;
i32 fa[N], dep[N];
std::vector<i32> Cir[N];
std::vector<pii> res, Temp;


i32 find(i32 u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
void merge(i32 u, i32 v)
{
	u = find(u);
	v = find(v);
	if (u != v) {
		fa[u] = v;
	}
}
i32 tarjan(i32 u, i32 fa)
{
	i32 m_dep = dep[u];
	for (auto v: Cir[u]) {
		if (v == fa) continue;
		if (dep[v]) {
			m_dep = std::min(m_dep, dep[v]);
			res.emplace_back(std::min(u, v), std::max(u, v));
			continue;
		}
		dep[v] = dep[u] + 1;
		m_dep = std::min(m_dep, tarjan(v, u));
	}
	if (m_dep < dep[u]) {
		merge(fa, u);
		res.emplace_back(std::min(fa, u), std::max(fa, u));
	}
	return m_dep;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> m;
	for (i32 i = 1; i <= n; ++i) {
		fa[i] = i;
	}

	for (i32 i = 1; i <= m; ++i) {
		i32 u, v; std::string str;
		read >> u >> v >> str;
		if (str == "Lun") {
			Cir[u].emplace_back(v);
			Cir[v].emplace_back(u);
		} else {
			Temp.emplace_back(u, v);
		}
	}
	for (i32 i = 1; i <= n; ++i)
		if (!dep[i]) {
			dep[i] = 1;
			tarjan(i, i);
		}
	for (auto pr: Temp) {
		i32 u = pr.first, v = pr.second;
		i32 uu = find(u), vv = find(v);
		if (uu != vv) {
			res.emplace_back(std::min(u, v), std::max(u, v));
			fa[uu] = vv;
		}
	}
	i32 root = find(1);
	bool fail = 0;
	for (i32 i = 1; i <= n; ++i)
		if (find(i) != root) fail = 1;
	if (fail) {
		puts("NO");
	} else {
		puts("YES");
		std::sort(res.begin(), res.end());
		res.erase(std::unique(res.begin(), res.end()), res.end());
		printf("%ld\n", res.size());
		for (auto pr: res) {
			printf("%d %d\n", pr.first, pr.second);
		}
	}
	return 0;
}
