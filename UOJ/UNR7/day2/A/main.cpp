#include <queue>
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

const int N = 5e5 + 10;

i32 n, m, root[N];
i32 a[N], b[N], c[N], b2c[N];
i32 nex[N][20];

namespace presidentTree
{
	const int NN = 2e7;
	i32 idx;
	i32 ls[NN], rs[NN], cnt[NN];
	i64 sumC[NN];
	i32 insert(i32 i, i32 v, i32 l = 1, i32 r = n)
	{
		i32 u = ++idx;
		ls[u] = ls[v];
		rs[u] = rs[v];
		cnt[u] = cnt[v];
		sumC[u] = sumC[v];
		i32 pos = b[i];
		if (l == r) {
			cnt[u] += 1;
			sumC[u] += c[i];
			return u;
		}
		i32 mid = l + r >> 1;
		if (pos <= mid) ls[u] = insert(i, ls[u], l, mid);
		else rs[u] = insert(i, rs[u], mid + 1, r);
		cnt[u] = cnt[ls[u]] + cnt[rs[u]];
		sumC[u] = sumC[ls[u]] + sumC[rs[u]];
		return u;
	}
	std::pair<i32, i64> queryK(i32 v, i32 u, i32 k, i32 l = 1, i32 r = n)
	{
		if (l == r)
			return std::make_pair(l, sumC[u] - sumC[v]);
		i32 mid = l + r >> 1;
		i32 t = cnt[rs[u]] - cnt[rs[v]];
		if (t >= k) {
			return queryK(rs[v], rs[u], k, mid + 1, r);
		}
		std::pair<i32, i64> res = queryK(ls[v], ls[u], k - t, l, mid);
		res.second += sumC[rs[u]] - sumC[rs[v]];
		return res;
	}
}
using presidentTree::insert;
using presidentTree::queryK;
namespace segmentTree
{
	i32 mxA[N << 2], mxB[N << 2];

	void build(i32 u = 1, i32 l = 1, i32 r = n)
	{
		if (l == r) {
			mxA[u] = a[l];
			mxB[u] = b[l];
			return;
		}
		i32 mid = l + r >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		mxA[u] = std::max(mxA[u << 1], mxA[u << 1 | 1]);
		mxB[u] = std::max(mxB[u << 1], mxB[u << 1 | 1]);
	}
	i32 queryPos(i32 L, i32 R, i32 b, i32 u = 1, i32 l = 1, i32 r = n)
	{
		if (L <= l && r <= R) {
			if (mxB[u] < b) return -1;
			if (l == r) return l;
			i32 mid = l + r >> 1;
			if (mxB[u << 1 | 1] < b)
				return queryPos(L, R, b, u << 1, l, mid);
			else
				return queryPos(L, R, b, u << 1 | 1, mid + 1, r);
		}
		i32 mid = l + r >> 1;
		i32 res = -1;
		if (R > mid)
			res = queryPos(L, R, b, u << 1 | 1, mid + 1, r);
		if (res == -1 && L <= mid)
			res = queryPos(L, R, b, u << 1, l, mid);
		return res;
	}
	i32 getNex(i32 L, i32 R, i32 b, i32 u = 1, i32 l = 1, i32 r = n)
	{
		if (L > R) return -1;
		if (L <= l && r <= R) {
			if (mxA[u] < b) return -1;
			if (l == r) return l;
			i32 mid = l + r >> 1;
			if (mxA[u << 1] < b)
				return getNex(L, R, b, u << 1 | 1, mid + 1, r);
			else
				return getNex(L, R, b, u << 1, l, mid);
		}
		i32 mid = l + r >> 1;
		i32 res = -1;
		if (L <= mid)
			res = getNex(L, R, b, u << 1, l, mid);
		if (res == -1 && R > mid)
			res = getNex(L, R, b, u << 1 | 1, mid + 1, r);
		return res;
	}
}
using segmentTree::build;
using segmentTree::queryPos;
using segmentTree::getNex;

void initNex(void)
{
	using Pii = std::pair<i32, i32>;
	std::priority_queue<Pii, std::vector<Pii>, std::greater<Pii> > heap;
	for (i32 i = 1; i <= n; ++i) {
		while (heap.size() && heap.top().first <= a[i]) {
			nex[heap.top().second][0] = i;
			heap.pop();
		}
		heap.emplace(std::make_pair(b[i], i));
	}
	for (int i = 1; i < 20; ++i)
		for (int j = 1; j <= n; ++j)
			nex[j][i] = nex[nex[j][i - 1]][i - 1];
}

int main(void)
{
	read >> n >> m;
	for (i32 i = 1; i <= n; ++i) read >> a[i];
	for (i32 i = 1; i <= n; ++i) read >> b[i];
	for (i32 i = 1; i <= n; ++i) read >> c[i];
	for (i32 i = 1; i <= n; ++i) b2c[b[i]] = c[i];

	initNex();
	for (i32 i = 1; i <= n; ++i) {
		root[i] = insert(i, root[i - 1]);
	}
	build();

	for (i32 i = 1; i <= m; ++i) {
		i32 l, r, k;
		read >> l >> r >> k;
		std::pair<i32, i64> t = queryK(root[l - 1], root[r], k);
		i32 kthb = t.first;
		i64 res = t.second;
		i32 lbound = queryPos(l, r, kthb);
		i32 nx = getNex(lbound + 1, r, kthb);
		if (nx != -1) {
			for (i32 i = 19; i >= 0; --i)
				if (nex[nx][i] && nex[nx][i] <= r)
					nx = nex[nx][i];
			res -= b2c[kthb];
			res += c[nx];
		}
		printf("%ld\n", res);
	}
	return 0;
}
