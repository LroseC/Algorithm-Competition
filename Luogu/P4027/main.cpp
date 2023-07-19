#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const i32 N = 1e5 + 10;

i32 n, root, idx;
double f[N];
double A[N], B[N], R[N];

inline double getX(i32 id)
{ return B[id] / A[id]; }
inline double getK(i32 id)
{ return f[id] / (R[id] * A[id] + B[id]); }
inline double getB(i32 id)
{ return f[id] * R[id] / (R[id] * A[id] + B[id]); }

struct Line
{
	double k, b;
	Line(void) {}
	Line(double _k, double _b) : k(_k), b(_b) {}
};
struct node
{
	Line line;
	i32 l, r;
} tr[N << 6];

double calc(Line line, double x)
{ return line.k * x + line.b; }

void insert(Line line, i32 &u, double l = 0, double r = 1e20)
{
	if (!u) {
		u = ++idx;
		tr[u].line = line;
		return;
	}
	double mid = (l + r) / 2;
	if (calc(line, mid) > calc(tr[u].line, mid)) {
		std::swap(line, tr[u].line);
	}
	if (calc(line, l) > calc(tr[u].line, l)) {
		insert(line, tr[u].l, l, mid);
	}
	else if (calc(line, r) > calc(tr[u].line, r)) {
		insert(line, tr[u].r, mid, r);
	}
}
double query(double pos, i32 u, double l = 0, double r = 1e20)
{
	if (!u) return 0;
	double mid = (l + r) / 2;
	double res = calc(tr[u].line, pos);
	if (pos < mid) {
		res = std::max(res, query(pos, tr[u].l, l, mid));
	}
	else {
		res = std::max(res, query(pos, tr[u].r, mid, r));
	}
	return res;
}
void insert_line(i32 id)
{
	double k = getK(id), b = getB(id);
	insert(Line(k, b), root);
}

int main(void)
{
	//Think twice, code once? I'm back.
	std::ios::sync_with_stdio(false);
	read >> n >> f[1];
	for (i32 i = 1; i <= n; ++i) {
		read >> A[i] >> B[i] >> R[i];
	}
	insert_line(1);
	for (i32 i = 2; i <= n; ++i) {
		f[i] = query(getX(i), root) * A[i];
		f[i] = std::max(f[i], f[i - 1]);
		insert_line(i);
	}
	printf("%.3lf\n", f[n]);
	return 0;
}
