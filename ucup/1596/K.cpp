#include <vector>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
#define read std::cin

const int mod = 998244353;

i32 modAdd(i32 x, i32 y)
{
	x += y;
	return x >= mod ? x - mod : x;
}

struct ModInt
{
	i32 val;
	ModInt(void) {}
	ModInt(i32 x)
	{ val = x; }
	ModInt operator+(const ModInt &other) const
	{
		return modAdd(val, other.val);
	}
	ModInt operator*(const ModInt &other) const
	{
		return ModInt(1ll * val * other.val % mod);
	}
	ModInt operator-(const ModInt &other) const
	{
		return modAdd(val, mod - other.val);
	}
	bool operator==(int other) const
	{
		return val == other;
	}
};

const int N = 3010;

i32 n;
ModInt f[N][N][4], g[N][N], h[N][N];
ModInt pwCol[N][N], pwRow[N][N];
bool ctCol[N][N], ctRow[N][N];
char M[N][N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i)
		read >> (M[i] + 1);
	f[0][0][0] = 1;
	for (i32 i = 1; i <= n; ++i) {
		f[i][0][1] = 1;
		f[0][i][2] = 1;
		f[i][0][3] = 1;
		pwCol[0][i] = 1;
		pwRow[i][0] = 1;
		ctCol[0][i] = ctRow[i][0] = 1;
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= n; ++j) {
			if (ctCol[i - 1][j]) {
				if (M[i][j] == '1') {
					pwCol[i][j] = 1;
				}
				else if (M[i][j] == '0') {
					pwCol[i][j] = pwCol[i - 1][j];
				} else {
					pwCol[i][j] = pwCol[i - 1][j] + 1;
				}
				ctCol[i][j] = M[i][j] != '0';
			}
			else {
				if (M[i][j] == '1') {
					pwCol[i][j] = 0;
				} else {
					pwCol[i][j] = pwCol[i - 1][j];
				}
			}
			if (ctRow[i][j - 1]) {
				if (M[i][j] == '1') {
					pwRow[i][j] = 1;
				}
				else if (M[i][j] == '0') {
					pwRow[i][j] = pwRow[i][j - 1];
				} else {
					pwRow[i][j] = pwRow[i][j - 1] + 1;
				}
				ctRow[i][j] = M[i][j] != '0';
			}
			else {
				if (M[i][j] == '1') {
					pwRow[i][j] = 0;
				} else {
					pwRow[i][j] = pwRow[i][j - 1];
				}
			}
		}
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= n; ++j) {
			printf("%d", ctRow[i][j]);
		}
		puts("");
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= n; ++j) {
			printf("%d", ctCol[i][j]);
		}
		puts("");
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= n; ++j) {
			printf("%d ", pwRow[i][j].val);
		}
		puts("");
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= n; ++j) {
			printf("%d ", pwCol[i][j].val);
		}
		puts("");
	}
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= n; ++j) {
			h[i][j] = (f[i - 1][j - 1][0] + f[i - 1][j - 1][1] + f[i - 1][j - 1][2]) *
				(ctRow[i][j]) *
				(ctCol[i][j]);
			g[i][j] = g[i][j - 1] * pwCol[i][j - 1] + f[i][j - 1][3];
			f[i][j][1] = (f[i - 1][j][0] + f[i - 1][j][1] + f[i - 1][j][2]) *
				(ctRow[i][j]);
			f[i][j][1] = f[i][j][1] - h[i][j];
			f[i][j][2] = (f[i][j - 1][0] + f[i][j - 1][1] + f[i][j - 1][2]) *
				(ctCol[i][j]);
			f[i][j][0] = g[i][j] * pwCol[i - 1][j] + f[i - 1][j][3] * pwRow[i][j - 1];
			if (M[i][j] == '0') {
				f[i][j][1] = f[i][j][2] = 0;
			}
			if (M[i][j] == '1') {
				f[i][j][0] = 0;
			}
			f[i][j][3] = f[i][j][1] + f[i - 1][j][3] * pwRow[i][j - 1];
			for (i32 k = 0; k <= 3; ++k) {
				printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k].val);
			}
			printf("g[%d][%d] = %d\n", i, j, g[i][j].val);
		}
	}
	ModInt res = f[n][n][0] + f[n][n][1] + f[n][n][2];
	printf("%d\n", res.val);
	return 0;
}
