#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

struct FSI
{
	template<typename T>
	FSI& operator>>(T &res)
	{
		res = 0; T f = 1; char ch = getchar();
		while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
		while (isdigit(ch)) { res = res * 10 + (ch - '0') * f; ch = getchar(); }
		return *this;
	}
} read;

const int N = 2e5 + 10;

using PII = std::pair<i32, i32>;

i32 n, m, K;
i32 dis[N];
bool flag[N];
std::vector<i32> G[N];
std::priority_queue<PII> Q;

void add(i32 u, i32 v)
{
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}
void getAns(void)
{
	while (Q.size()) {
		PII t = Q.top();
		Q.pop();
		i32 u = t.second;
		if (flag[u]) continue;
		flag[u] = 1;
		for (int v : G[u])
			if (dis[u] - 1 > dis[v]) {
				dis[v] = dis[u] - 1;
				Q.emplace(dis[v], v);
			}
	}
}

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m >> K;
	for (int i = 1; i <= m; ++i) {
		i32 u, v;
		read >> u >> v;
		add(u, v);
	}
	for (int i = 1; i <= K; ++i) {
		i32 u, d;
		read >> u >> d;
		d += 1;
		dis[u] = d;
		Q.emplace(d, u);
	}
	getAns();
	std::vector<i32> ans;
	for (int i = 1; i <= n; ++i)
		if (flag[i]) ans.emplace_back(i);
	printf("%ld\n", ans.size());
	for (int v : ans) printf("%d ", v);
	puts("");
	return 0;
}
