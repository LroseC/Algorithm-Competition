#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int mod = 998244353;

i32 mod_add(i32 x, i32 y)
{
	x += y;
	return x >= mod ? x - mod : x;
}
struct ModInt
{
	i32 val;
	ModInt(void) { val = 0; }
	ModInt(i32 x) { val = x; }

	friend ModInt operator+(const ModInt &a, const ModInt &b)
	{
		return mod_add(a.val, b.val);
	}
	friend ModInt operator-(const ModInt &a, const ModInt &b)
	{
		return mod_add(a.val, mod - b.val);
	}
	friend ModInt operator*(const ModInt &a, const ModInt &b)
	{
		return ModInt(1ll * a.val * b.val % mod);
	}
	void operator+=(const ModInt &other)
	{
		val = mod_add(val, other.val);
	}
	void operator-=(const ModInt &other)
	{
		val = mod_add(val, mod - other.val);
	}
	void operator*=(const ModInt &other)
	{
		val = 1ll * val * other.val % mod;
	}
};

void work(void)
{
	read >> n;
	std::vector<pii> seg(n);
	std::vector<pii> point(n << 1);
	for (i32 i = 0; i < n; ++i) {
		read >> seg[i].first >> seg[i].second;
		point[i << 1] = mp(seg[i].first, i);
		point[i << 1 | 1] = mp(seg[i].second, i);
	}
	std::sort(point.begin(), point.end());
	for (i32 i = 0; i < n * 2; ++i) {
		auto pr = point[i];
		i32 id = pr.second;
		if (id == seg[id].first) {
			seg[id].first = i;
		} else {
			seg[id].second = i;
		}
	}
	std::vector<i32> sum(n * 2);
	for (i32 i = 0; i < n; ++i) {
		sum[seg[i].first] += 1;
		if (seg[i].second + 1 <= n * 2) {
			sum[seg[i].second] -= 1;
		}
	}
	for (i32 i = 0; i < n * 2; ++i) {
		if (i != 0) {
			sum[i] += sum[i - 1];
		}
		for (i32 j = 0; j <= sum[i] ++j) {
			res += ModInt(j / 2) * C[sum[i]][j] * pw2[n - sum[i]];
		}
	}
	std::vector<i32> w(n);
	for (i32 i = 0; i < n * 2; ++i) {
		for (i32 w = -1; w <= 1; ++i) {
			cnt[w] = 0;
			tmp[w] = 0;
		}
		i32 *cnt = cnt_buf + 1;
		for (i32 j = 0; j < n; ++j) {
			w[j] = 0;
			if (seg[j].second <= i)
				w[j] = -1;
			else if (seg[j].first >= i + 1)
				w[j] = 1;
			cnt[w[j]] += 1;
		}
		for (i32 w = -1; w <= 1; ++w) {
			cnt[w] -= 1;
			tmp[w] = calc();
			cnt[w] += 1;
		}
		for (i32 j = 0; j < n; ++j) {
			if (w[j] == -1) {
				res += tmp[w[j]] * get_dis(seg[j].second, i);
			} else if (w[j] == 1) {
				res += tmp[w[j]] * get_dis(i + 1, seg[j].first);
			}
		}
	}

	ModInt res(0);
}

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
