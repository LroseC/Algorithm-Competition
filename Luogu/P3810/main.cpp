#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

const int N = 2e5 + 10;

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

struct Query
{
	i32 a, b, c, t;

	Query(void) {}
	Query(i32 _a, i32 _b, i32 _c, i32 _t) { a = _a, b = _b, c = _c, t = _t; }
	bool operator<(const Query &other) const
	{ return a == other.a ? t < other.t : a < other.a; }
};

i32 n, m;
i32 bit[N], stk[N], ans[N], f[N], top;
std::vector<Query> q, tmp;

inline i32 lowbit(i32 x) { return x & -x; }
void add(i32 pos, i32 x)
{
	for (int i = pos; i < N; i += lowbit(i)) {
		bit[i] += x;
	}
}
i32 query(i32 pos)
{
	i32 res = 0;
	for (int i = pos; i; i -= lowbit(i)) {
		res += bit[i];
	}
	return res;
}
void clear(void)
{
	while (top) {
		add(stk[top], -1);
		top -= 1;
	}
}

void solve(i32 l, i32 r)
{
	if (l == r) return;
	i32 mid = l + r >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	i32 i = l, j = mid + 1;
	i32 k = l;
	while (i <= mid && j <= r) {
		if (q[i].b <= q[j].b) {
			if (q[i].t == 0) {
				stk[++top] = q[i].c;
				add(q[i].c, 1);
			}
			tmp[k++] = q[i++];
		}
		else {
			if (q[j].t != 0) ans[q[j].t] += query(q[j].c);
			tmp[k++] = q[j++];
		}
	}
	while (i <= mid) {
		tmp[k] = q[i];
		i += 1, k += 1;
	}
	while (j <= r) {
		tmp[k] = q[j];
		if (q[j].t) ans[q[j].t] += query(q[j].c);
		j += 1, k += 1;
	}
	for (int i = l; i <= r; ++i) q[i] = tmp[i];
	clear();
}

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m;
	for (int i = 1; i <= n; ++i) {
		i32 a, b, c;
		read >> a >> b >> c;
		q.emplace_back(a, b, c, 0);
		q.emplace_back(a, b, c, i);
	}
	std::sort(q.begin(), q.end());
	tmp.resize(q.size());
	solve(0, q.size() - 1);
	for (int i = 1; i <= n; ++i) {
		f[ans[i] - 1] += 1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", f[i]);
	}
	return 0;
}
