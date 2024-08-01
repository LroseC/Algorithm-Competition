#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 1e5 + 10;

i32 n, K;
i32 arr[N];
std::queue<i32> indx[N];

void work(void)
{
	std::vector<std::vector<i32>> op;
	read >> n >> K;
	for (i32 i = 1; i <= n; ++i) {
		read >> arr[i];
		indx[arr[i]].emplace(i);
	}
	i32 flag = 0;
	for (i32 i = 2; i <= K; ++i)
		if (indx[i].size() != 0) {
			flag += 1;
		}
	if (flag == K - 1 && flag != 1) {
		puts("-1");
		return;
	}
	if (flag == K - 1) {
		i32 x;
		for (i32 i = 2; i <= K; ++i)
			if (indx[i].size() != 0) {
				x = i;
				break;
			}
		if (x != n || indx[x].size() != n) {
			puts("-1");
			return;
		}
		printf("1\n");
		printf("%d ", x);
		for (i32 i = 1; i <= n; ++i) {
			printf("%d ", i);
		}
		puts("");
		return;
	}
	if (indx[2].size() == 0) {
		printf("%d\n", n - 1);
		std::queue<i32> q;
		for (i32 i = 1; i <= n; ++i) {
			q.emplace(i);
		}
		i32 idx = 0;
		while (q.size() != 1) {
			i32 u = q.front(); q.pop();
			i32 v = q.front(); q.pop();
			printf("2 %d %d\n", u, v);
			idx += 1;
			q.emplace(n + idx * 2);
		}
		return;
	}
	i32 Merge;
	for (i32 i = 2; i <= K; ++i)
		if (indx[i].size() == 0) {
			Merge = i;
			break;
		}
	std::queue<i32> q;
	i32 idx = 0;
	for (i32 i = 1; i <= n; ++i) {
		if (arr[i] != 2) {
			q.emplace(i);
		}
	}
	i32 delta = n - Merge;
	if (delta < 0) {
		puts("-1");
		return;
	}
	while (delta >= 2 && indx[2].size() >= 3) {
		delta -= 2;
		idx += 1;
		std::vector<i32> tmp;
		for (i32 i = 1; i <= 3; ++i) {
			tmp.emplace_back(indx[2].front());
			indx[2].pop();
		}
		indx[2].emplace(n + 2 * idx);
		op.emplace_back(tmp);
	}
	while (delta > 0 && q.size() >= 2) {
		delta -= 1;
		idx += 1;
		std::vector<i32> tmp;
		for (i32 i = 1; i <= 2; ++i) {
			tmp.emplace_back(q.front());
			q.pop();
		}
		q.emplace(n + 2 * idx);
		op.emplace_back(tmp);
	}
	if (delta) {
		delta -= 1;
		idx += 1;
		std::vector<i32> tmp;
		for (i32 i = 1; i <= 2; ++i) {
			tmp.emplace_back(indx[2].front());
			indx[2].pop();
		}
		indx[2].emplace(n + 2 * idx - 1);
		op.emplace_back(tmp);
	}
	std::vector<i32> tmp;
	while (indx[2].size()) {
		tmp.emplace_back(indx[2].front());
		indx[2].pop();
	}
	while (q.size()) {
		tmp.emplace_back(q.front());
		q.pop();
	}
	op.emplace_back(tmp);
	printf("%d\n", op.size());
	for (auto &vec: op) {
		printf("%d ", vec.size());
		for (auto &x: vec) {
			printf("%d ", x);
		}
		puts("");
	}
}
void clear(void)
{
	for (i32 i = 1; i <= n; ++i) {
		while (indx[arr[i]].size())
			indx[arr[i]].pop();
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	return 0;
}
