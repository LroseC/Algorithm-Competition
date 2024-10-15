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

const int N = 1e6 + 10;

bool vis[N];
i32 v[N], ome[N], dis[N], prime[N], idx;

void init(void)
{
	for (i32 i = 2; i < N; ++i) {
		if (!v[i]) {
			v[i] = i;
			ome[i] = 1;
			prime[++idx] = i;
		}
		for (i32 j = 1; j <= idx && prime[j] * i < N; ++j) {
			v[prime[j] * i] = prime[j];
			if (prime[j] == v[i]) {
				ome[prime[j] * i] = ome[i];
			} else {
				ome[prime[j] * i] = ome[i] + 1;
			}
		}
	}
//	i32 resson = 0, resmom = 1;
//	for (i32 i = 2; i <= idx; ++i) {
//		if (1ll * resson * resson * prime[i] < 1ll * (prime[i] - prime[i - 1]) * (prime[i] - prime[i - 1]) * resmom) {
//			resson = prime[i] - prime[i - 1];
//			resmom = prime[i];
//		}
//	}
//	printf("%d %d\n", resson, resmom);
}

i32 get_dis(i32 x, i32 y)
{
	i32 ret = 0;
	while (x != 1 && y != 1) {
		if (v[x] != v[y]) {
			if (v[x] > v[y]) std::swap(x, y);
			ret += 1;
			i32 vv = v[x];
			while (v[x] == vv) {
				x /= vv;
			}
		} else {
			ret += 1;
			i32 vv = v[x];
			while (v[x] == vv) {
				x /= vv;
			}
			while (v[y] == vv) {
				y /= vv;
			}
		}
	}
	return ret + ome[x] + ome[y];
}

void work(void)
{
	i32 l, r;
	read >> l >> r;
	i64 res = 0;
	i64 tmp = 0;
	for (i32 i = l; i <= r; ++i) {
		tmp += ome[i];
	}
	if (l == 1) {
		for (i32 i = 2; i <= r; ++i) {
			res += ome[i];
		}
		printf("%lld\n", res);
		return;
	}
	std::vector<i32> vec;
	bool have_prime = 0;
	for (i32 i = 2; i <= r; ++i) {
		if (vis[i]) continue;
		bool fail = 1;
		for (i32 j = i; j <= r; j += i) {
			if (l <= j && j <= r && ome[j] == ome[i]) {
				fail = 0;
			}
		}
		if (fail == 0) {
			if (v[i] == i) {
				have_prime = 1;
			}
			vec.emplace_back(i);
			res -= ome[i];
			for (i32 j = i; j <= r; j += i) {
				if (!vis[j]) {
					vis[j] = 1;
					if (l <= j && j <= r) {
						res += ome[j];
					}
				}
			}
		}
	}
	for (i32 i = 1; i <= r; ++i) {
		vis[i] = 0;
	}
	if (have_prime) {
		for (auto v: vec) {
			res += ome[v] + 1;
		}
		res -= 2;
	} else {
		for (auto v: vec) {
			dis[v] = INT_MAX;
		}
		dis[vec[0]] = 0;
		for (i32 i = 0; i < vec.size(); ++i) {
			i32 v = 0;
			for (i32 u: vec) {
				if (vis[u]) continue;
				if (v == 0 || dis[u] < dis[v]) {
					v = u;
				}
			}
			if (v == 0) break;
			res += dis[v];
			vis[v] = 1;
			for (i32 u: vec) {
				if (vis[u]) continue;
				dis[u] = std::min(dis[u], get_dis(v, u));
			}
		}
		for (auto v: vec) {
			vis[v] = 0;
		}
	}
	printf("%lld\n", res);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	init();
	i32 tt; read >> tt;
	while (tt--) {
		work();
	}
	return 0;
}
