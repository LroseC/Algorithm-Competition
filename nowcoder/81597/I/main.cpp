#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin
const i32 N = 3e3 + 10;

i32 arr[N * 2];
i32 l[N], r[N], len[N], ord[N];
i64 g[N], f[N * 2];

bool cmplen(i32 a, i32 b)
{
	return len[a] < len[b];
}

i64 calc(i32 l, i32 r, std::vector<std::pair<pii, i64>> vec)
{
	std::sort(vec.begin(), vec.end());
	for (i32 i = l - 1; i <= r; ++i) {
		f[i] = 0;
	}
	i64 res = 0;
	for (i32 i = l, j = 0; i <= r && j < vec.size(); ++i) {
		f[i] = std::max(f[i], f[i - 1]);
		auto pr = vec[j].first;
		i64 gval = vec[j].second;
		if (i == pr.first) {
			f[pr.second] = std::max(f[pr.second], f[i - 1] + gval);
			j += 1;
		}
	}
	for (i32 i = l; i <= r; ++i) {
		res = std::max(res, f[i]);
	}
	return res;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 n; read >> n;
	for (i32 i = 1; i <= 2 * n; ++i) {
		read >> arr[i];
		if (!l[arr[i]]) {
			l[arr[i]] = i;
		} else {
			r[arr[i]] = i;
			len[arr[i]] = r[arr[i]] - l[arr[i]] + 1;
		}
	}
	for (i32 i = 1; i <= n; ++i) {
		ord[i] = i;
	}
	std::sort(ord + 1, ord + 1 + n, cmplen);
	for (i32 k = 1; k <= n; ++k) {
		i32 i = ord[k];
		g[i] = len[i] * i;
		std::vector<std::pair<pii, i64>> vec;
		for (i32 j = i + 1; j <= n; ++j) {
			if (l[i] < l[j] && r[j] < r[i]) {
				vec.emplace_back(std::make_pair(l[j], r[j]), g[j] - len[j] * i);
			}
		}
		g[i] = std::max(g[i], len[i] * i + calc(l[i], r[i], vec));
	}
	for (i32 i = 0; i <= n * 2; ++i) {
		f[i] = 0;
	}
	i64 res = 0;
	for (i32 i = 1; i <= n * 2; ++i) {
		f[i] = std::max(f[i], f[i - 1]);
		if (i == l[arr[i]]) {
			i32 x = arr[i];
			f[r[x]] = std::max(f[r[x]], f[i - 1] + g[x]);
			res = std::max(res, f[r[x]]);
		}
	}
	std::cout << res << std::endl;
	return 0;
}
/*
5
2 3 1 3 4 1 4 2 5 5
*/
