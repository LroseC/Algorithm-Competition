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

const int N = 2e5 + 10;

i32 n, m;
i64 tot, sum;
i32 lst[N];
i32 a[N];
pii charge[N];
i32 tr[N << 2], cov[N << 2];

void update(i32 u)
{
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
void cov_node(i32 u)
{
	cov[u] = 1;
	tr[u] = 0;
}
void pushdown(i32 u)
{
	if (cov[u]) {
		cov[u] = 0;
		cov_node(u << 1);
		cov_node(u << 1 | 1);
	}
}
void build(i32 u = 1, i32 l = 1, i32 r = m)
{
	cov[u] = 0;
	if (l == r) {
		tr[u] = charge[l].first - charge[l - 1].first;
		return;
	}
	i32 mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	update(u);
}
i32 query(i32 L, i32 R, i32 u = 1, i32 l = 1, i32 r = m)
{
	if (L > R) {
		return 0;
	}
	if (L <= l && r <= R) {
		return tr[u];
	}
	i32 mid = l + r >> 1;
	pushdown(u);
	i32 ret = 0;
	if (L <= mid) {
		ret += query(L, R, u << 1, l, mid);
	}
	if (R > mid) {
		ret += query(L, R, u << 1 | 1, mid + 1, r);
	}
	return ret;
}
i32 cover(i32 L, i32 R, i32 u = 1, i32 l = 1, i32 r = m)
{
	if (L > R) {
		return 0;
	}
	if (L <= l && r <= R) {
		i32 ret = tr[u];
		cov_node(u);
		return ret;
	}
	i32 mid = l + r >> 1;
	pushdown(u);
	i32 ret = 0;
	if (L <= mid) {
		ret += cover(L, R, u << 1, l, mid);
	}
	if (R > mid) {
		ret += cover(L, R, u << 1 | 1, mid + 1, r);
	}
	update(u);
	return ret;
}
void dec(i32 pos, i32 val, i32 u = 1, i32 l = 1, i32 r = m)
{
	if (l == r) {
		tr[u] -= val;
		return;
	}
	pushdown(u);
	i32 mid = l + r >> 1;
	if (pos <= mid) {
		dec(pos, val, u << 1, l, mid);
	} else {
		dec(pos, val, u << 1 | 1, mid + 1, r);
	}
	update(u);
}

void work(void)
{
	read >> n >> m;
	tot = 0;
	for (i32 i = 1; i <= n; ++i) {
		read >> a[i];
		tot += a[i];
		lst[i] = 0;
	}
	sum = tot;
	for (i32 i = 1; i <= m; ++i) {
		read >> charge[i].first >> charge[i].second;
	}
	build();
	for (i32 i = 1; i <= m; ++i) {
		i32 pos = i, type = charge[i].second;
		if (query(1, pos) > tot) {
			printf("%lld\n", charge[i - 1].first + tot - query(1, pos - 1));
			return;
		}
		i32 last = lst[type];
		lst[type] = pos;
		i32 l = last + 1, r = pos;
		while (l <= r) {
			i32 mid = l + r >> 1;
			if (query(last + 1, mid) < a[type]) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		i32 len = a[type] - cover(last + 1, r);
		if (l <= pos) {
			dec(l, len);
		}
	}
	printf("%lld\n", charge[m].first + tot - query(1, m));
}
void clear(void) {}

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
