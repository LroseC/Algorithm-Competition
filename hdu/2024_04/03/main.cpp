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

const int N = 4e5 + 10;

struct node
{
	i64 sum, max, lmax, rmax;
	i32 lseg, rseg;
	pii seg;
	friend node operator+(const node &a, const node &b)
	{
		node res;
		res.sum = a.sum + b.sum;
		if (a.max > b.max) {
			res.max = a.max;
			res.seg = a.seg;
		} else {
			res.max = b.max;
			res.seg = b.seg;
		}
		if (a.lmax + b.rmax > res.max) {
			res.max = a.rmax + b.lmax;
			res.seg = std::make_pair(a.rseg, b.lseg);
		}
		if (a.lmax > a.sum + b.lmax) {
			res.lmax = a.lmax;
			res.lseg = a.lseg;
		} else {
			res.lmax = a.sum + b.lmax;
			res.lseg = b.lseg;
		}
		if (b.rmax > b.sum + a.rmax) {
			res.rmax = b.rmax;
			res.rseg = b.rseg;
		} else {
			res.rmax = b.sum + a.rmax;
			res.rseg = a.rseg;
		}
		return res;
	}
};

i32 n, K;
i32 a[N];
i32 prime[N], v[N], idx;
i64 sum[N];
node tr[N << 2];

void get_prime(void)
{
	for (i32 i = 2; i < N; ++i) {
		if (v[i] == 0) {
			v[i] = i;
			prime[++idx] = i;
		}
		for (i32 j = 1; j <= idx && 1ll * i * prime[j] < N; ++j) {
			v[i * prime[j]] = prime[j];
			if (v[i] == prime[j]) break;
		}
	}
}

void query(i32 L, i32 R, i32 x, node &res, i32 u = 1, i32 l = 1, i32 r = n)
{
//	printf("L = %d, R = %d\n", L, R);
//	printf("l = %d, r = %d\n", l, r);
//	printf("max = %d\n", res.max);
	if (L <= l && r <= R) {
		if (res.max >= x)
			return;
		if (l == r) {
			res = res + tr[u];
			return;
		}
		i32 mid = l + r >> 1;
		auto tmp = res + tr[u];
		if (tmp.max < x) {
			res = tmp;
			return;
		}
		tmp = res + tr[u << 1];
		if (tmp.max < x) {
			res = tmp;
			query(L, R, x, res, u << 1 | 1, mid + 1, r);
			return;
		} else {
			query(L, R, x, res, u << 1, l, mid);
			return;
		}
		return;
	}
	i32 mid = l + r >> 1;
	if (L <= mid && R > mid) {
		query(L, R, x, res, u << 1, l, mid);
		if (res.max < x)
			query(L, R, x, res, u << 1 | 1, mid + 1, r);
	} else if (L <= mid) {
		query(L, R, x, res, u << 1, l, mid);
	} else {
		query(L, R, x, res, u << 1 | 1, mid + 1, r);
	}
}

bool check(i32 X)
{
//	printf("X = %d\n", X);
	i32 pos = 1;
	i32 cnt = 0;

	while (pos <= n && cnt < K) {
//		printf("pos = %d\n", pos);
		node t;
		t.max = t.lmax = t.rmax = -1e17;
		t.sum = 0;
		query(pos, n, X, t);
		pii seg = t.seg;
//		printf("(%d, %d)\n", seg.first, seg.second);
//		printf("max = %d\n", t.max);
		if (t.max < X) return 0;
		i32 rbound = n + 1;
		i32 x = std::lower_bound(prime + 1, prime + 1 + idx, seg.second - seg.first + 1) - prime;
		for (i32 i = x; i <= idx && i <= x + 10; ++i) {
			i32 len = prime[i];
//			printf("len = %d\n", len);
			for (i32 j = std::max(pos, seg.first - len - 10); j <= seg.second + 10; ++j) {
				if (j + len - 1 > n) break;
				if (sum[j + len - 1] - sum[j - 1] >= X) {
//					printf("l = %d, r = %d\n", j, j + len - 1);
					rbound = std::min(rbound, j + len - 1);
					break;
				}
			}
		}
		pos = rbound + 1;
		if (pos <= n + 1)
			cnt += 1;
	}
	return cnt == K;
}
void build(i32 u = 1, i32 l = 1, i32 r = n)
{
	if (l == r) {
		tr[u].sum = tr[u].max = tr[u].lmax = tr[u].rmax = a[l];
		tr[u].lseg = tr[u].rseg = l;
		tr[u].seg = std::make_pair(l, r);
		return;
	}
	i32 mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	get_prime();
	i32 tt; read >> tt;
	while (tt--) {
		read >> n >> K;
		for (i32 i = 1; i <= n; ++i) {
			read >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		build();
		if (n / 2 < K) {
			puts("impossible");
		} else {
			i32 l = -1e9, r = 1e9;
			while (l < r) {
				i32 mid = l + r + 1 >> 1;
				if (check(mid)) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			printf("%d\n", l);
		}
	}
	return 0;
}
