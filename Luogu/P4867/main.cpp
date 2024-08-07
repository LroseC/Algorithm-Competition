#include <cmath>
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

const int N = 1e5 + 10, M = 1e6 + 10;


i32 B = 316, B2 = 100;


i32 n, m;
i32 res[M];
i32 id[N], L[N], R[N], cnt[N], sum[N], index[M];
i32 arr[N], l[M], r[M], a[M], b[M];

bool cmp(i32 a, i32 b)
{
	if (l[a] / B2 != l[b] / B2) {
		return l[a] / B2 < l[b] / B2;
	}
	return (l[a] / B2 & 1 ? r[a] < r[b] : r[a] > r[b]);
}
void build(void)
{
	for (i32 i = 1; i <= n; ++i) {
		id[i] = (i - 1) / B + 1;
		if (L[id[i]] == 0) {
			L[id[i]] = i;
		}
		R[id[i]] = std::max(R[id[i]], i);
	}
}

void add(i32 pos)
{
	i32 ps = arr[pos];
	if (cnt[ps] == 0) {
		sum[id[ps]] += 1;
	}
	cnt[ps] += 1;
}
void del(i32 pos)
{
	i32 ps = arr[pos];
	cnt[ps] -= 1;
	if (cnt[ps] == 0) {
		sum[id[ps]] -= 1;
	}
}
i32 query(i32 l, i32 r)
{
	if (id[l] == id[r]) {
		i32 res = 0;
		for (i32 i = l; i <= r; ++i) {
			res += cnt[i] > 0;
		}
		return res;
	}
	i32 res = 0;
	for (i32 i = l; id[i] == id[l]; ++i) {
		res += cnt[i] > 0;
	}
	for (i32 i = r; id[i] == id[r]; --i) {
		res += cnt[i] > 0;
	}
	for (i32 i = id[l] + 1; i <= id[r] - 1; ++i) {
		res += sum[i];
	}
	return res;
}

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m;
	B = sqrt(n);
	B2 = n / sqrt(m);
//	fprintf(stderr, "B = %d, B2 = %d\n", B, B2);
	for (i32 i = 1; i <= n; ++i) {
		read >> arr[i];
	}
	for (i32 i = 1; i <= m; ++i) {
		index[i] = i;
		read >> l[i] >> r[i] >> a[i] >> b[i];
	}
	build();
	std::sort(index + 1, index + 1 + m, cmp);
	i32 L = 1, R = 0;
	for (i32 i = 1; i <= m; ++i) {
		i32 id = index[i];
		while (L < l[id]) del(L++);
		while (L > l[id]) add(--L);
		while (R < r[id]) add(++R);
		while (R > r[id]) del(R--);
		res[id] = query(a[id], b[id]);
	}
	for (i32 i = 1; i <= m; ++i) {
		printf("%d\n", res[i]);
	}
	return 0;
}
