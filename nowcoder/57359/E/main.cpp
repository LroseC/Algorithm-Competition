#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e3 + 10;

struct OP
{
	i32 l, r, w;
	OP(void) {}
	OP(i32 _l, i32 _r, i32 _w) : l(_l), r(_r), w(_w) {}
};

i32 n, m, idx;
std::vector<OP> op;
i32 val[N];

void buildTree(i32 l, i32 r)
{
	i32 w = -1;
	while (idx < op.size() && op[idx].l == l && op[idx].r == r) {
		w = op[idx].w;
		idx += 1;
	}
	i32 sw = 0;
	bool flg = 0;
	i32 last1 = -1, last2 = -1;
	while (idx < op.size() && op[idx].r <= r) {
		sw ^= op[idx].w;
		last2 = last1;
		last1 = idx;
		buildTree(op[idx].l, op[idx].r);
	}
	if (w == -1) return;
	if (sw != w) {
		if (last1 == -1) {
			std::swap(val[r], val[r - 1]);
		}
		else if (last1 != -1 && last2 != -1 && op[last2].r == op[last1].l - 1) {
			i32 mx = op[last2].l;
			for (i32 i = mx + 1; i <= op[last2].r; ++i)
				if (val[i] > val[mx]) mx = i;
			i32 mn = op[last1].l;
			for (i32 i = mn + 1; i <= op[last1].r; ++i)
				if (val[i] < val[mn]) mn = i;
			std::swap(val[mx], val[mn]);
		}
		else {
			if (op[last1].l == l) {
				i32 mx = op[last1].l;
				for (i32 i = op[last1].l + 1; i <= op[last1].r; ++i) {
					if (val[i] > val[mx]) mx = i;
				}
				std::swap(val[mx], val[op[last1].r + 1]);
			}
			else {
				i32 mn = op[last1].l;
				for (i32 i = op[last1].l + 1; i <= op[last1].r; ++i) {
					if (val[i] < val[mn]) mn = i;
				}
				std::swap(val[mn], val[op[last1].l - 1]);
			}
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> m;
	op.resize(m);
	for (i32 i = 0; i < m; ++i) {
		read >> op[i].l >> op[i].r >> op[i].w;
	}
	auto cmp = [](OP a, OP b)->bool {
		return a.l == b.l ? a.r > b.r : a.l < b.l;
	};
	std::sort(op.begin(), op.end(), cmp);
	for (i32 i = 0; i < m; ++i) {
		if (op[i].l == op[i - 1].l && op[i].r == op[i - 1].r && op[i].w != op[i - 1].w) {
			puts("-1");
			return 0;
		}
		if (op[i].l == op[i].r && op[i].w == 1) {
			puts("-1");
			return 0;
		}
	}
	for (i32 i = 1; i <= n; ++i)
		val[i] = i;
	buildTree(1, n);
	for (i32 i = 1; i <= n; ++i)
		printf("%d ", val[i]);
	puts("");
	return 0;
}
