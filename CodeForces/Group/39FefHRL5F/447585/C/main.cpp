#include <vector>
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

const int N = 310, mod = 998244353;
inline int Mod(int x) { return x >= mod ? x - mod : x; }

struct ModInt
{
	int val;
	ModInt(void) {}
	ModInt(i32 x) { val = x; }

	ModInt operator+(const ModInt other) const
	{ return Mod(val + other.val); }
	ModInt operator-(const ModInt other) const
	{ return Mod(val + mod - other.val); }
	ModInt operator*(const ModInt other) const
	{ return 1ll * val * other.val % mod; }
};

int n, m, K;
int a[N];
ModInt f[2][N][N], sum[N];

int main(void)
{
	read >> n >> m >> K;
	for (int i = 1; i <= n; ++i) read >> a[i];
	f[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j <= m; ++j)
//			for (int k = 0; k < K; ++k) {
//				printf("f[%d][%d][%d] = %d\n", i, j, k, f[i & 1][j][k].val);
//			}
		for (int j = 0; j <= m; ++j)
			for (int k = 0; k < K; ++k)
				f[(i & 1) ^ 1][j][k] = 0;
		for (int j = 0; j <= m; ++j) {
			sum[0] = f[i & 1][j][0];
			for (int k = 1; k < K; ++k)
				sum[k] = sum[k - 1] + f[i & 1][j][k];
			for (int k = 1; k < K; ++k) {
				f[(i & 1) ^ 1][j][k] = f[(i & 1) ^ 1][j][k] + sum[k];
				i32 left = k - a[i + 1] - 1;
				if (left < 0) {
					left += K;
					f[(i & 1) ^ 1][j][k] = f[(i & 1) ^ 1][j][k] + sum[K - 1] - sum[left];
				}
				else {
					f[(i & 1) ^ 1][j][k] = f[(i & 1) ^ 1][j][k] - sum[left];
				}
			}
			{
				int k = 0;
				f[(i & 1) ^ 1][j + 1][k] = f[(i & 1) ^ 1][j + 1][k] + sum[k];
				i32 left = k - a[i + 1] - 1;
				if (left < 0) {
					left += K;
					f[(i & 1) ^ 1][j + 1][k] = f[(i & 1) ^ 1][j + 1][k] + sum[K - 1] - sum[left];
				}
				else {
					f[(i & 1) ^ 1][j + 1][k] = f[(i & 1) ^ 1][j + 1][k] - sum[left];
				}
			}
		}
	}
	ModInt ans = 0;
	for (int i = 0; i < K; ++i) ans = ans + f[n & 1][m][i];
	printf("%d\n", ans.val);
	return 0;
}
