#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <algorithm>

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

using i32 = int32_t;
using i64 = int64_t;

int main(void)
{
	//Think twice, code once? I'm back.
	i32 tt; read >> tt;
	while (tt--) {
		i32 n, m;
		read >> n >> m;
		std::vector<std::vector<i32>> mp;
		mp.resize(n);
		for (int i = 0; i < n; ++i)
			mp[i].resize(m);

		i32 cntp = 0, cntn = 0;
		for (int i = 0, bg = 0; i < n; ++i, bg = (bg + 2) % 5) {
			for (int j = bg; j < m; j += 5) {
				mp[i][j] = 1;
				cntp += 1;
			}
		}
		for (int i = 0, bg = 1; i < n; ++i, bg = (bg + 2) % 5) {
			for (int j = bg; j < m; j += 5) {
				mp[i][j] = -1;
				cntn += 1;
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (mp[i][j]) continue;
				if (cntp <= cntn) {
					mp[i][j] = 1;
					cntp += 1;
				}
				else {
					mp[i][j] = -1;
					cntn += 1;
				}
			}
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < m; ++j) {
				printf("%c", mp[i][j] == 1 ? 'x' : 'o');
			}
	}
	return 0;
}
