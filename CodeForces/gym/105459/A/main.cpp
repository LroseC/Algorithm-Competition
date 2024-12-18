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

const int N = 1010, LG = 21;

i32 idx, S, T, L, R;
i32 tot[N];
i32 ch[N][2];
std::vector<pii> G[N];

void add_edge(i32 u, i32 v, i32 val)
{
	if (u == v) return;
	G[u].emplace_back(v, val);
}
i32 get_tot(i32 dig)
{
	if (dig == -1) {
		return T;
	}
	if (tot[dig]) {
		return tot[dig];
	}
	tot[dig] = ++idx;
	add_edge(tot[dig], get_tot(dig - 1), 0);
	add_edge(tot[dig], get_tot(dig - 1), 1);
	return tot[dig];
}
i32 build(i32 u, i32 dig, i32 val, i32 high, i32 low)
{
	if (!high && !low) {
		return get_tot(dig);
	}
	if (dig == -1) {
		return T;
	}
	if (!u) {
		u = ++idx;
	}
	if (!high || (R >> dig & 1)) {
		i32 v = build(ch[u][1], dig - 1, val | (1 << dig), high, low && (L >> dig & 1));
		add_edge(u, v, 1);
	}
	if (!low || !(L >> dig & 1)) {
		i32 v = build(ch[u][0], dig - 1, val, high && !(R >> dig & 1), low);
		add_edge(u, v, 0);
	}
	return u;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> L >> R;
	S = ++idx;
	ch[S][0] = S;
	T = ++idx;
	build(S, LG - 1, 0, 1, 1);
	printf("%d\n", idx);
	for (i32 i = 1; i <= idx; ++i) {
		printf("%ld ", G[i].size());
		for (auto pr: G[i]) {
			printf("%d %d ", pr.first, pr.second);
		}
		puts("");
	}
	return 0;
}
