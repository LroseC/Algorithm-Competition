#include <cctype>
#include <cstdio>
#include <cstdint>

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

const int N = 4 * 32 * 1e5 + 10;

i32 idx, root;
struct node
{
	i32 l, r;
	i32 tag, sum;
} tr[N];

i32 newNode(void)
{
	idx += 1;
	i32 u = idx;
	tr[u].l = tr[u].r = tr[u].tag = tr[u].sum = 0;
	return u;
}
i32 addNode(i32 c, i32 u, i32 l, i32 r)
{
	if (!u) u = newNode();
	i32 t = (r - l + 1) * c;
	tr[u].tag += c;
	tr[u].sum += t;
	return u;
}
void spread(i32 u, i32 l, i32 r)
{
	i32 tag = tr[u].tag;
	tr[u].tag = 0;
	i32 mid = (l + r) >> 1;
	tr[u].l = addNode(tag, tr[u].l, l, mid);
	tr[u].r = addNode(tag, tr[u].r, mid + 1, r);
}
i32 add(i32 L, i32 R, i32 u, i32 l = 0, i32 r = 1e9)
{
	if (L <= l && r <= R) {
		u = addNode(1, u, l, r);
		return u;
	}
	if (!u) u = newNode();
	i32 mid = (l + r) >> 1;
	if (L <= mid) {
		tr[u].l = add(L, R, tr[u].l, l, mid);
	}
	if (R > mid) {
		tr[u].r = add(L, R, tr[u].r, mid + 1, r);
	}
	tr[u].sum = tr[tr[u].l].sum + tr[tr[u].r].sum;
	return u;
}
i32 query(i32 L, i32 R, i32 u, i32 l = 0, i32 r = 1e9)
{
//	fprintf(stderr, "%d %d %d -> %d\n", u, l, r, tr[u].sum);
	if (!u) return 0;
	if (L <= l && r <= R) {
		return tr[u].sum;
	}
	spread(u, l, r);
	i32 res = 0;
	i32 mid = (l + r) >> 1;
	if (L <= mid) {
		res += query(L, R, tr[u].l, l, mid);
	}
	if (R > mid) {
		res += query(L, R, tr[u].r, mid + 1, r);
	}
	return res;
}

int main(void)
{
	//Think twice, code once? I'm back.
	i32 n;
	read >> n;
	i32 t;
	read >> t;
	for (int i = 1; i < n; i += 2) {
		i32 l, r;
		read >> l >> r;
		root = add(l, r - 1, root);
	}
	i32 m;
	read >> m;
	for (int i = 1; i <= m; ++i) {
		i32 l, r;
		read >> l >> r;
		printf("%d\n", query(l, r - 1, root));
	}
	return 0;
}
