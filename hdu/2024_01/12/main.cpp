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

const int mod = 998244353;
const int N = 2e3 + 10;

struct ModInt
{
	i32 val;
	ModInt(void) { val = 0; }
	ModInt(i32 x) { val = x; }
	ModInt operator+(const ModInt &other) const
	{
		i32 v = val + other.val;
		return ModInt(v >= mod ? v - mod : v);
	}
	ModInt operator-(const ModInt &other) const
	{
		i32 v = val - other.val + mod;
		return ModInt(v >= mod ? v - mod : v);
	}
	ModInt operator*(const ModInt &other) const
	{
		return ModInt(1ll * val * other.val % mod);
	}
	void operator+=(const ModInt &other)
	{
		val += other.val;
		val = val >= mod ? val - mod : val;
	}
	void operator-=(const ModInt &other)
	{
		val += mod - other.val;
		val = val >= mod ? val - mod : val;
	}
	void operator*=(const ModInt &other)
	{
		val = 1ll * val * other.val % mod;
	}
};

struct TreeNode
{
	i32 tag, min, max;
	TreeNode operator+(const TreeNode &y) const
	{
		TreeNode tmp;
		tmp.tag = 0;
		tmp.min = std::min(min, y.min);
		tmp.max = std::max(max, y.max);
		return tmp;
	}
};

i32 n;
ModInt C[N][N];
ModInt len[N], area[N];
TreeNode tr[N << 4];
i32 x[N][2], y[N][2];
std::vector<i32> vec_y;

ModInt qpow(ModInt base, i32 k)
{
	ModInt res(1);
	while (k) {
		if (k & 1) res *= base;
		k >>= 1;
		base *= base;
	}
	return res;
}
ModInt get_inv(ModInt x)
{
	return qpow(x, mod - 2);
}

void init_C(void)
{
	for (i32 i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (i32 j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}

ModInt get_pos(i32 x)
{
	return ModInt(vec_y[x]);
}
void add_node(i32 u, i32 val)
{
	tr[u].tag += val;
	tr[u].min += val;
	tr[u].max += val;
}
void spread(i32 u)
{
	add_node(u << 1, tr[u].tag);
	add_node(u << 1 | 1, tr[u].tag);
	tr[u].tag = 0;
}
void add(i32 L, i32 R, i32 v, i32 u = 1, i32 l = 0, i32 r = vec_y.size() - 2)
{
	if (L <= l && r <= R) {
		add_node(u, v);
		return;
	}
	spread(u);
	i32 mid = l + r >> 1;
	if (L <= mid) {
		add(L, R, v, u << 1, l, mid);
	}
	if (R > mid) {
		add(L, R, v, u << 1 | 1, mid + 1, r);
	}
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
void query(i32 u = 1, i32 l = 0, i32 r = vec_y.size() - 2)
{
	if (tr[u].min == tr[u].max) {
		len[tr[u].min] += get_pos(r + 1) - get_pos(l);
		return;
	}
	spread(u);
	i32 mid = l + r >> 1;
	query(u << 1, l, mid);
	query(u << 1 | 1, mid + 1, r);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	init_C();
	std::vector<std::pair<pii, pii>> op;
	for (i32 i = 0; i < n; ++i) {
		read >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
		vec_y.emplace_back(y[i][0]);
		vec_y.emplace_back(y[i][1]);
	}
	std::sort(vec_y.begin(), vec_y.end());
	vec_y.erase(std::unique(vec_y.begin(), vec_y.end()), vec_y.end());
	for (i32 i = 0; i < n; ++i) {
		y[i][0] = std::lower_bound(vec_y.begin(), vec_y.end(), y[i][0]) - vec_y.begin();
		y[i][1] = std::lower_bound(vec_y.begin(), vec_y.end(), y[i][1]) - vec_y.begin();
		op.emplace_back(std::make_pair(x[i][0], 1), std::make_pair(y[i][0], y[i][1]));
		op.emplace_back(std::make_pair(x[i][1], -1), std::make_pair(y[i][0], y[i][1]));
	}
	std::sort(op.begin(), op.end());
	i32 lastx = 0;
	for (auto t: op) {
		i32 x = t.first.first;
		if (x != lastx) {
			std::memset(len, 0, sizeof len);
			query();
			for (i32 i = 1; i <= n; ++i) {
				area[i] += len[i] * (x - lastx);
			}
		}
		i32 val = t.first.second;
		i32 l = t.second.first;
		i32 r = t.second.second;
		add(l, r - 1, val);
		lastx = x;
	}
	for (i32 i = 1; i <= n; ++i) {
		ModInt res = 0;
		for (i32 j = 1; j <= n; ++j) {
			res += area[j] * (C[n][i] - (n - j < i ? 0 : C[n - j][i]));
		}
		res *= get_inv(C[n][i]);
		std::cout << res.val << std::endl;
	}
	return 0;
}
