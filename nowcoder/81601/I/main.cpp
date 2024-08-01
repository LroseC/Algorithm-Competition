#include <vector>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

i32 n, m;

void work(void)
{
	read >> n >> m;
	std::vector<i64> max_ans(m + 1);
	for (i32 i = 1; i <= n; ++i) {
		std::vector<i64> sum(m + 1);
		std::vector<i64> pre_max(m + 1);
		std::vector<i64> suf_max(m + 2);
		pre_max[0] = LLONG_MIN;
		suf_max[m + 1] = LLONG_MIN;
		for (i32 j = 1; j <= m; ++j) {
			i32 x; read >> x;
			sum[j] = sum[j - 1] + x;
		}
		i64 pre_sm = LLONG_MIN, suf_sm = LLONG_MIN;
		for (i32 j = 1; j <= m; ++j) {
			pre_sm = std::max(pre_sm, -sum[j - 1]);
			pre_max[j] = std::max(pre_max[j - 1], pre_sm + max_ans[j]);
		}
		for (i32 j = m; j >= 1; --j) {
			suf_sm = std::max(suf_sm, sum[j]);
			suf_max[j] = std::max(suf_max[j + 1], suf_sm + max_ans[j]);
		}
		std::vector<i64> tmp(m + 1);
		pre_sm = suf_sm = LLONG_MIN;
		for (i32 j = m; j >= 1; --j) {
			suf_sm = std::max(suf_sm, sum[j]);
			tmp[j] = suf_sm + pre_max[j];
		}
		for (i32 j = 1; j <= m; ++j) {
			pre_sm = std::max(pre_sm, -sum[j - 1]);
			tmp[j] = std::max(tmp[j], pre_sm + suf_max[j]);
		}
		std::swap(tmp, max_ans);
	}
	i64 res = LLONG_MIN;
	for (i32 i = 1; i <= m; ++i) {
		res = std::max(res, max_ans[i]);
	}
	printf("%lld\n", res);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
