#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 2510, M = 1e4 + 10;

bool vis[N];
i32 now[N], fa[N];
i32 d[N];
std::map<i32, i32> edge_id[N];

void clear(void)
{
	for (i32 i = 0; i < N; ++i) {
		vis[i] = 0;
		fa[i] = 0;
		d[i] = 0;
		now[i] = 1;
		edge_id[i].clear();
	}
}
i32 go(i32 x)
{
	std::cout << "> " << x << std::endl;
	i32 u;
	read >> u >> d[u];
	return u;
}
i32 get_id(i32 u, i32 v)
{
	return edge_id[u][v];
}

void work(void)
{
	std::vector<pii> edge;
	i32 u;
	read >> u >> d[u];
	vis[u] = 1;
	while (true) {
		for (i32 &i = now[u]; i <= d[u];) {
//			printf("u = %d, i = %d\n", u, i);
			i32 v = go(i);
//			printf("v = %d\n", v);
			i32 a = u, b = v;
			if (a > b) std::swap(a, b);
			edge.emplace_back(a, b);
			edge_id[u][v] = i;
			i += 1;
			if (!vis[v]) {
				vis[v] = 1;
				fa[v] = u;
				u = v;
				break;
			} else if (v == fa[u]) {
				go(get_id(v, u));
			} else {
				u = v;
				break;
			}
		}
		if (now[u] > d[u]) {
			if (fa[u]) {
				u = go(get_id(u, fa[u]));
			} else {
				break;
			}
		}
	}
	std::sort(edge.begin(), edge.end());
	edge.erase(std::unique(edge.begin(), edge.end()), edge.end());
	std::cout << "! ";
	for (auto t: edge) {
		std::cout << t.first << ' ' << t.second << ' ';
	}
	std::cout << std::endl;
	std::string x;
	read >> x;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		clear();
		work();
	}
	return 0;
}
