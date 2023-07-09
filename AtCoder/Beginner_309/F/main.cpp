#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

const int P = 998244353;
inline int plu(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int del(int x, int y) {return x - y <  0 ? x - y + P : x - y;}
inline void add(int &x, int y) {x = plu(x, y);}
inline void sub(int &x, int y) {x = del(x, y);}
inline int qpow(int a, int b) {int s = 1; for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) s = 1ll * s * a % P; return s;} 

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

struct node
{
	int v[4];
	bool operator<(const node &other) const
	{ return v[1] == other.v[1] ? v[2] > other.v[2] : v[1] < other.v[1]; }
};

const int N = 1e6 + 10;

int n;
int bit[N];
node nd[N];

inline int lowbit(int x) { return x & -x; }
void Add(int pos, int x)
{
	for (int i = pos; i < N; i += lowbit(i))
		bit[i] = min(bit[i], x);
}
int query(int pos)
{
	int res = 1e9;
	for (int i = pos; i; i -= lowbit(i))
		res = min(res, bit[i]);
	return res;
}

int main() {
	n = read();
	vector<int> vec;
	rep (i, 1, n) {
		rep (j, 1, 3) nd[i].v[j] = read();
		sort(nd[i].v + 1, nd[i].v + 3 + 1);
		rep (j, 1, 3) vec.eb(nd[i].v[j]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	rep (i, 1, n) {
		rep (j, 1, 3)
			nd[i].v[j] = lower_bound(vec.begin(), vec.end(), nd[i].v[j]) - vec.begin() + 1;
	}
	sort(nd + 1, nd + 1 + n);
	memset(bit, 0x3f, sizeof bit);
	rep (i, 1, n) {
		if (query(nd[i].v[2] - 1) < nd[i].v[3]) {
			puts("Yes");
			return 0;
		}
		Add(nd[i].v[2], nd[i].v[3]);
	}
	puts("No");
	return 0;
}
