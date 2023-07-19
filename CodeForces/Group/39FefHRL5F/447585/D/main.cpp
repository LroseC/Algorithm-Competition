#include <cmath>
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

const int N = 1e6 + 10;

i32 n, m;
char str[N];
i32 cnta, qcnt, cntl[N], cntr[N];
i64 scntl, scntr;
i64 ansBase, ans;

i64 calc(i32 addq, i32 qleft)
{
	i32 qright = addq - qleft;
	i64 res = ansBase;
	res += 1ll * cnta * qleft * qright;
	res += 1ll * scntl * qright;
	res += 1ll * qleft * scntr;
	i32 qsum = qcnt + addq;
	i32 ql = qsum / 2, qr = qsum - ql;
	res += 1ll * (m - addq) * ql * qr;
	return res;
}

int main(void)
{
	read >> n >> m;
	scanf("%s", str + 1);
	for (int i = 1, cnt = 0; i <= n; ++i) {
		if (str[i] == 'q') ++cnt;
		else {
			cnta += 1;
			cntl[i] = cnt;
			scntl += cnt;
		}
	}
	for (int i = n, cnt = 0; i >= 1; --i) {
		if (str[i] == 'q') {
			++cnt;
			qcnt += 1;
		}
		else {
			cntr[i] = cnt;
			scntr += cnt;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (str[i] == 'a') ansBase += 1ll * cntl[i] * cntr[i];
	i64 ans = 0;
	for (int qc = 0; qc <= m; ++qc) { //放置 qc 个 q
		i32 ac = m - qc;
		double t = 1.0 * (1ll * qc * cnta - scntl + scntr) / (2 * cnta);
		if (t < 0) {
			ans = std::max(ans, calc(qc, 0));
		}
		else if (t > qc) {
			ans = std::max(ans, calc(qc, qc));
		}
		else {
			ans = std::max(ans, calc(qc, (i32)std::ceil(t)));
			ans = std::max(ans, calc(qc, (i32)std::floor(t)));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
