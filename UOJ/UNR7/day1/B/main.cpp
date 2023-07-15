#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
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

i32 C[110][110];
i32 f[1 << 11 | 1][1 << 9];
std::pair<i32, i32> pre[1 << 11 | 1][1 << 9];
i32 n, K, T;
i32 a[1 << 21];
std::vector<i32> G;
std::vector<std::pair<i32, i32>> op;

void getPre(i32 i, i32 j, i32 l)
{
	if (i == 0) return;
	i32 prj = pre[i][j].first;
	getPre(i - 1, prj, l);
	if (pre[i][j].second != -1)
		op.emplace_back(std::make_pair(l + i - 1, pre[i][j].second));
}
void work(i32 l, i32 r, bool flg)
{
	i32 len = r - l;
	for (i32 i = 0; i < len; ++i) {
		for (i32 st = 0; st < (1 << 9); ++st) {
			if (f[i][st] == 0x3f3f3f3f) continue;
			i32 tst = st ^ (a[l + i + 9] << 9);
			if (tst & 1) {
				for (i32 j = 0; j < 10; ++j) {
					i32 to = (tst ^ G[j]) >> 1;
					if (f[i][st] + 1 < f[i + 1][to]) {
						f[i + 1][to] = f[i][st] + 1;
						pre[i + 1][to] = std::make_pair(st, j);
					}
				}
			}
			else {
				i32 to = tst >> 1;
				if (f[i][st] < f[i + 1][to]) {
					f[i + 1][to] = f[i][st];
					pre[i + 1][to] = std::make_pair(st, -1);
				}
			}
		}
	}
	i32 mn = 0;
	for (i32 st = 0; st < (1 << 9); ++st) {
		if (f[len][st] < f[len][mn]) mn = st;
	}
	if (flg) mn = 0;
	i32 tmp = f[len][mn];
	getPre(len, mn, l);
	++tick;
	f[0][mn] = tmp;
}

int main(void)
{
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j <= i; ++j) {
			if (j == 0) C[i][j] = 1;
			else {
				C[i][j] = C[i - 1][j - 1] ^ C[i - 1][j];
			}
		}
	for (int i = 0; i < 16; ++i) {
		i32 state = 0;
		for (int j = 0; j <= i; ++j) {
			state ^= C[i][j] << j;
		}
		G.emplace_back(state);
	}
	std::memset(f, 0x3f, sizeof f);
	std::memset(pre, -1, sizeof pre);
	read >> n >> K >> T;
	for (int i = 0; i < n; ++i) {
		read >> a[i];
	}
	i32 tmp = 0;
	for (int i = 0; i < 9; ++i) {
		tmp ^= a[i] << i;
	}
	f[0][tmp] = 0;
	for (int i = 0; i < n; i += (1 << 11)) {
		i32 r = std::min(n, i + (1 << 11));
		work(i, r, r == n);
		/*
		tmp = f[(1 << 11)][0];
		std::memset(f, 0x3f, sizeof f);
		f[0][0] = tmp;
		*/
	}
	printf("%ld\n", op.size());
	for (auto t : op) {
		printf("%d %d\n", t.first, t.second);
	}
	return 0;
}
