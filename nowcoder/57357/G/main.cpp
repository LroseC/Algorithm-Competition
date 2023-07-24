#include <cctype>
#include <cstdio>
#include <cassert>
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

const int N = 2010;
#define x first
#define y second

i32 n, m;
char str[N][N];

namespace Hash1
{
	const int mod1 = 999999937, mod2 = 1e9 + 7;
	std::pair<i32, i32> hsh[N][N];
	std::pair<i32, i32> pw1[N], pw2[N];
	void initHash(void)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				hsh[i][j].x = ((i64)hsh[i][j - 1].x * 131 + str[i][j]) % mod1;
				hsh[i][j].y = ((i64)hsh[i][j - 1].y * 131 + str[i][j]) % mod2;
			}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				hsh[i][j].x = ((i64)hsh[i - 1][j].x * 1331 + hsh[i][j].x) % mod1;
				hsh[i][j].y = ((i64)hsh[i - 1][j].y * 1331 + hsh[i][j].y) % mod2;
			}
		pw1[0].x = pw1[0].y = pw2[0].x = pw2[0].y = 1;
		for (int i = 1; i <= std::max(n, m); ++i) {
			pw1[i].x = (i64)131 * pw1[i - 1].x % mod1;
			pw1[i].y = (i64)131 * pw1[i - 1].y % mod2;
			pw2[i].x = (i64)1331 * pw2[i - 1].x % mod1;
			pw2[i].y = (i64)1331 * pw2[i - 1].y % mod2;
		}
	}
	std::pair<i32, i32> get(i32 l, i32 r, i32 u, i32 d)
	{
		assert(l <= r);
		assert(u <= d);
		i32 first = (hsh[d][r].x - (i64)hsh[u - 1][r].x * pw2[d - u + 1].x) % mod1;
		i32 tmp = (hsh[d][l - 1].x - (i64)hsh[u - 1][l - 1].x * pw2[d - u + 1].x) % mod1;
		first = ((first - (i64)tmp * pw1[r - l + 1].x) % mod1 + mod1) % mod1;
		i32 second = (hsh[d][r].y - (i64)hsh[u - 1][r].y * pw2[d - u + 1].y) % mod2;
		tmp = (hsh[d][l - 1].y - (i64)hsh[u - 1][l - 1].y * pw2[d - u + 1].y) % mod2;
		second = ((second - (i64)tmp * pw1[r - l + 1].y) % mod2 + mod2) % mod2;
		return std::make_pair(first, second);
	}
}
namespace Hash2
{
	const int mod1 = 999999937, mod2 = 1e9 + 7;
	std::pair<i32, i32> hsh[N][N];
	std::pair<i32, i32> pw1[N], pw2[N];
	void initHash(void)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				i32 pi = n - i + 1, pj = m - j + 1;
				hsh[i][j].x = ((i64)hsh[i][j - 1].x * 131 + str[pi][pj]) % mod1;
				hsh[i][j].y = ((i64)hsh[i][j - 1].y * 131 + str[pi][pj]) % mod2;
			}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				hsh[i][j].x = ((i64)hsh[i - 1][j].x * 1331 + hsh[i][j].x) % mod1;
				hsh[i][j].y = ((i64)hsh[i - 1][j].y * 1331 + hsh[i][j].y) % mod2;
			}
		pw1[0].x = pw1[0].y = pw2[0].x = pw2[0].y = 1;
		for (int i = 1; i <= std::max(n, m); ++i) {
			pw1[i].x = (i64)131 * pw1[i - 1].x % mod1;
			pw1[i].y = (i64)131 * pw1[i - 1].y % mod2;
			pw2[i].x = (i64)1331 * pw2[i - 1].x % mod1;
			pw2[i].y = (i64)1331 * pw2[i - 1].y % mod2;
		}
	}
	std::pair<i32, i32> get(i32 l, i32 r, i32 u, i32 d)
	{
		l = m - l + 1, r = m - r + 1;
		u = n - u + 1, d = n - d + 1;
		assert(l <= r);
		assert(u <= d);
		i32 first = (hsh[d][r].x - (i64)hsh[u - 1][r].x * pw2[d - u + 1].x) % mod1;
		i32 tmp = (hsh[d][l - 1].x - (i64)hsh[u - 1][l - 1].x * pw2[d - u + 1].x) % mod1;
		first = ((first - (i64)tmp * pw1[r - l + 1].x) % mod1 + mod1) % mod1;
		i32 second = (hsh[d][r].y - (i64)hsh[u - 1][r].y * pw2[d - u + 1].y) % mod2;
		tmp = (hsh[d][l - 1].y - (i64)hsh[u - 1][l - 1].y * pw2[d - u + 1].y) % mod2;
		second = ((second - (i64)tmp * pw1[r - l + 1].y) % mod2 + mod2) % mod2;
		return std::make_pair(first, second);
	}
}

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m;
	for (i32 i = 1; i <= n; ++i)
		scanf("%s", str[i] + 1);
	Hash1::initHash();
	Hash2::initHash();
	i64 res = 0;
	for (i32 i = 1; i <= n; ++i)
		for (i32 j = 1; j <= m; ++j) {
			i32 L = 1, R = n;
			while (L < R) {
				i32 mid = L + R + 1 >> 1;
				i32 u = i - mid + 1, d = i + mid - 1;
				i32 l = j - mid + 1, r = j + mid - 1;
				if (u < 1 || l < 1 || d > m || r > n) R = mid - 1;
				else if (Hash1::get(l, r, u, i) == Hash2::get(r, l, d, i)) L = mid;
				else R = mid - 1;
			}
			res += L;
		}
	for (i32 i = 1; i <= n; ++i)
		for (i32 j = 1; j <= m; ++j) {
			i32 L = 0, R = n;
			while (L < R) {
				i32 mid = L + R + 1 >> 1;
				i32 u = i - mid, d = i + mid - 1;
				i32 l = j - mid, r = j + mid - 1;
				if (u < 1 || l < 1 || d > m || r > n) R = mid - 1;
				else if (Hash1::get(l, r, u, i - 1) == Hash2::get(r, l, d, i)) L = mid;
				else R = mid - 1;
			}
			res += L;
		}
	printf("%ld\n", res);
	return 0;
}
