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

const int N = 2e5 + 10;

int n, m;
int c[N], fa[N];
pii ed[N];

int find(int x)
{ return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int a, int b)
{ fa[find(a)] = find(b); }

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		cin >> ed[i].first >> ed[i].second;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i <= m; ++i) {
		if (c[ed[i].first] != c[ed[i].second]) merge(ed[i].first, ed[i].second);
	}
	bool flag = 0;
	for (int i = 1; i <= m; ++i) {
		if (c[ed[i].first] == c[ed[i].second] && find(ed[i].first) == find(ed[i].second))
			flag = 1;
	}
	puts(flag ? "Yes" : "No");
	return 0;
}
