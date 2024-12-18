#include <cmath>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using ldb = long double;
using pii = std::pair<i32, i32>;
using pdd = std::pair<ldb, ldb>;
#define read std::cin
#define x first
#define y second
#define mp std::make_pair

const int N = 4e3 + 10;

i32 n, nn, sz, top;
i32 stk[N];
bool used[N];
pdd p[N], pp[N], h[N];

pdd operator+(pdd a, pdd b)
{
	return mp(b.x + a.x, b.y + a.y);
}
pdd operator-(pdd a, pdd b)
{
	return mp(a.x - b.x, a.y - b.y);
}

ldb cross(pdd a, pdd b)
{
	return a.x * b.y - a.y * b.x;
}
ldb dot(pdd a, pdd b)
{
	return a.x * b.x + a.y * b.y;
}
ldb get_len(pdd x)
{
	return sqrt(dot(x ,x));
}
bool cmp_angle(pdd p1, pdd p2, pdd O, pdd Op)
{
	return dot(p1 - O, Op - O) * get_len(p2 - O) > 
		dot(p2 - O, Op - O) * get_len(p1 - O);
}
void andrew(void)
{
	std::sort(p, p + n);
	stk[++top] = 0;
	for (i32 i = 1; i < n; ++i) {
		while (top >= 2 && 
				cross(p[stk[top]] - p[stk[top - 1]], p[i] - p[stk[top]]) <= 0)
			used[stk[top--]] = 0;
		used[i] = 1;
		stk[++top] = i;
	}
	i32 tmp = top;
	for (i32 i = n - 2; i >= 0; --i) {
		if (!used[i]) {
			while (top > tmp && 
					cross(p[stk[top]] - p[stk[top - 1]], p[i] - p[stk[top]]) <= 0)
				used[stk[top--]] = 0;
			used[i] = 1;
			stk[++top] = i;
		}
	}
	sz = top - 1;
	for (i32 i = 1; i <= top; ++i) {
		h[i - 1] = p[stk[i]];
	}
	for (i32 i = 0; i < n; ++i) {
		if (!used[i]) {
			pp[nn++] = p[i];
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	i32 res = 0;
	for (i32 i = 0; i < n; ++i) {
		i32 x, y;
		read >> x >> y;
		p[i].x = x, p[i].y = y;
	}
	andrew();
	for (i32 i = 0; i < sz; ++i) {
		i32 j = i + 1;
		std::sort(pp, pp + nn, [&](pdd x, pdd y) {
			return cmp_angle(x, y, h[i], h[j]);
		});
//		printf("i = %Lf, %Lf, j = %Lf, %Lf\n", h[i].x, h[i].y, h[j].x, h[j].y);
		i32 min = -1;
		for (i32 k = 0; k < nn; ++k) {
			if (min == -1 || cmp_angle(pp[k], pp[min], h[j], h[i])) {
				min = k;
//				printf("(%Lf, %Lf)\n", pp[k].first, pp[k].second);
				res += 1;
			}
		}
	}
	printf("%d\n", res + 1);
	return 0;
}
