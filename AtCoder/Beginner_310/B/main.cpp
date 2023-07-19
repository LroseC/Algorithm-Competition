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

const int N = 110;

i32 n, m;
i32 p[N], c[N];
std::vector<i32> vec[N];

i32 greater(i32 a, i32 b)
{
	if (vec[a].size() == vec[b].size()) {
		for (int i = 0; i < vec[a].size(); ++i)
			if (vec[a][i] != vec[b][i]) return 0;
		return 2;
	}
	i32 res = vec[a].size() > vec[b].size() ? 1 : -1;
	if (res == -1) {
		std::swap(a, b);
	}
	i32 i = 0;
	for (i32 j = 0; j < vec[b].size(); ++j) {
		while (i < vec[a].size() && vec[a][i] != vec[b][j]) ++i;
		if (i == vec[a].size()) return 0;
	}
	return res;
}

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m;
	for (int i = 1; i <= n; ++i) {
		read >> p[i] >> c[i];
		vec[i].resize(c[i]);
		for (int j = 0; j < c[i]; ++j) read >> vec[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (p[i] > p[j] && greater(j, i) > 0) {
				puts("Yes");
				return 0;
			}
			else if (p[i] < p[j] && greater(i, j) > 0) {
				puts("Yes");
				return 0;
			}
			else if (p[i] == p[j] && (greater(i, j) & 1)) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
