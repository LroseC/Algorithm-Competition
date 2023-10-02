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

void calc(i32 n, i32 m, i32 dn, i32 dm, std::vector<std::pair<i32, i32>> &res)
{
	bool swp = 0;
	if (n < m) {
		swp = 1;
		std::swap(n, m);
		std::swap(dn, dm);
	}
	for (i32 i = 1, t = 1; t <= n / m; i += m, t += 1) {
		for (i32 j = 1; j <= m; ++j) {
			i32 a = i + dn, b = j + dm;
			if (swp) std::swap(a, b);
			res.emplace_back(a, b);
		}
	}
	dn += n / m * m;
	n %= m;
	if (n == 0) {
		for (i32 j = 2; j < m; ++j) {
			i32 a = n + dn, b = j + dm;
			if (swp) std::swap(a, b);
			res.emplace_back(a, b);
		}
		return;
	}
	if (swp) {
		std::swap(n, m);
		std::swap(dn, dm);
	}
	calc(n, m, dn, dm, res);
}

int main(void)
{
	//Think tiwce, code once.
	i32 n, m;
	read >> n >> m;
	std::vector<std::pair<i32, i32>> res;
	calc(n, m, 0, 0, res);
	printf("%d\n", res.size());
	for (auto t : res) {
		printf("%d %d\n", t.first, t.second);
	}
	return 0;
}
