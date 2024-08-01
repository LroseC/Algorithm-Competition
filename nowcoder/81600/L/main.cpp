#include <stack>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int N = 110, mod = 998244353;

std::pair<i64, i32> stk[N];

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		i32 idx = 0;
		i32 n; read >> n;
		std::vector<i32> arr(n);
		for (i32 i = 0; i < n; ++i) {
			read >> arr[i];
		}
		for (i32 i = 0; i < n; ++i) {
			stk[++idx] = std::make_pair(arr[i], 1);
			while (idx > 1 && stk[idx].first * stk[idx - 1].second >= stk[idx - 1].first * stk[idx].second) {
				auto t = stk[idx--];
				stk[idx].first += t.first;
				stk[idx].second += t.second;
			}
		}
		i32 res = 1;
		for (i32 i = 1; i <= idx; ++i) {
			auto t = stk[i];
			i32 v = t.first / t.second;
			i32 num = t.first % t.second;
			for (i32 j = 1; j <= num; ++j) {
				res = 1ll * res * (v + 1) % mod;
			}
			for (i32 j = num + 1; j <= t.second; ++j) {
				res = 1ll * res * v % mod;
			}
		}
		std::cout << res << std::endl;
	}
	return 0;
}
