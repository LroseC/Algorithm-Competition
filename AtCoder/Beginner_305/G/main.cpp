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

const i32 S = 1 << 5;
const i32 mod = 998244353;

struct modInt
{
	i32 v;
	modInt(i32 x = 0) { v = 0; }
	modInt operator+(const modInt &b) const
	{
		i32 t = v + b.v;
		return t > mod ? t - mod : t;
	}
	modInt operator*(const modInt &b) const
	{ return 1ll * v * b.v % mod; }
};
struct matrix
{
	modInt m[S][S];
	matrix(void)
	{ std::memset(m, 0, sizeof m); }
	matrix(i32 x)
	{
		if (x == 0) {
			for (int i = 0; i < S; ++i)
				m[i][i] = 1;
			return;
		}
		for (int i = 0; i < S; ++i)
			for (int j = 0; j < S; ++j) m[i][j] = x;
	}
	matrix operator[](const i32 &a) { return m[a]; }
	matrix operator*(const matrix &a) const
	{
		matrix res(0);
		for (int i = 0; i < 5; ++i)
			for (int k = 0; k < 5; ++k) {
				auto tmp = a[i][k];
				for (int j = 0; j < 5; ++j)
					res[i][j] = res[i][j] + tmp * m[k][j];
			}
		return res;
	}
};

int main(void)
{
	//Think twice, code once? I'm back.
	i64 n;
	read >> n;
	i32 m;
	read >> m;
	for (int i = 1; i <= m; ++i) {
		scanf("%s", str);
	}
	return 0;
}
