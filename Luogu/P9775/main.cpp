#include <cstdio>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e7 +10, mod = 998244353;

i32 n, a[N], b[N];
i32 sz[N], ls[N], rs[N], son[N], top[N], val[N], id[N], fa[N], idx;
i32 sum[N <<2], ml[N << 2];

void dfs(i32 u)
{
	if (!u) return;
	dfs(ls[u]);
	dfs(rs[u]);
	sz[u] = 1 + sz[ls[u]] + sz[rs[u]];
	son[u] = sz[ls[u]] > sz[rs[u]] ? ls[u] : rs[u];
}
void initTree(i32 u, i32 tp)
{
	id[u] = ++idx;
	top[u] = tp;
	if (id[top[u]] > id[u]) exit(0);
	if (son[u]) initTree(son[u], tp);
	if (ls[u] && ls[u] != son[u]) initTree(ls[u], ls[u]);
	if (rs[u] && rs[u] != son[u]) initTree(rs[u], rs[u]);
	if (ls[u]) val[id[u]] = 1ll * val[id[ls[u]]] * val[id[rs[u]]] % mod; 
	else val[id[u]] = a[u + 1 - n];
}
void build(i32 u = 1, i32 l = 1, i32 r = 2 * n - 1)
{
	ml[u] = 1;
	if (l == r) {
		sum[u] = val[l];
		return;
	}
	i32 mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	sum[u] = (sum[u << 1] +sum[u << 1 | 1]) % mod;
}
void mulNd(i32 u, i32 x)
{
	ml[u] = 1ll * ml[u] * x % mod;
	sum[u] = 1ll * sum[u] * x % mod;
}
void spread(i32 u)
{
	if (ml[u] != 1) {
		mulNd(u <<1, ml[u]);
		mulNd(u <<1 |1, ml[u]);
		ml[u] = 1;
	}
}
void mul(i32 L, i32 R, i32 x, i32 u = 1, i32 l = 1, i32 r = 2 * n - 1)
{
	if (L <= l && r <= R) {
		mulNd(u, x);
		return;
	}
	spread(u);
	i32 mid = l + r >>1;
	if (L <= mid) mul(L, R, x, u <<1, l, mid);
	if (R >mid) mul(L, R, x, u <<1 |1, mid +1, r); 
	sum[u] = (sum[u <<1] +sum[u <<1 |1]) %mod;
}
void mulE(i32 u, i32 x)
{
	while (u) {
		mul(id[top[u]], id[u], x);
		u = fa[top[u]];
	}
}

int main(void)
{
	//Think twice, code once!
	std::ios::sync_with_stdio(false); 
	read >>n;
	for (int i = 1; i <= n; ++i) {
		read >>a[i];
	}
	for (int i = 1; i <= n; ++i){
		read >>b[i];
	}
	for (int i = 1; i < n; ++i) {
		read >> ls[i] >> rs[i];
		fa[ls[i]] = fa[rs[i]] = i;
	}
	
	dfs(1);
	initTree(1, 1);
	build();
	for (int i = 1; i <= n; ++i) {
		mulE(i + n - 1, b[i]);
		printf("%d ", sum[1]);
	}
	puts("");
	return 0;
}
/*
4
1 2 3 4
2 3 2 3
2 7
3 6
4 5
*/
