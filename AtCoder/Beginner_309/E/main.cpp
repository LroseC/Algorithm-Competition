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

const int N = 3e5 + 10;

int n, m, ans;
int fa[N], op[N];
vector<int> G[N];

void dfs(int u, int dep)
{
	dep = max(dep, op[u]);
	if (dep) ans += 1;
	for (int v : G[u])
		dfs(v, max(0, dep - 1));
}

int main() {
	n = read(), m = read();
	rep (i, 2, n) {
		fa[i] = read();
		G[fa[i]].eb(i);
	}
	rep (i, 1, m) {
		int x = read(), y = read();
		op[x] = max(op[x], y + 1);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
