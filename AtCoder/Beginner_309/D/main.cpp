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

int n1, n2, m;
vector<int> G[N];
int d[N];

void bfs(int u)
{
	queue<int> q;
	q.emplace(u);
	d[u] = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : G[u])
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.emplace(v);
			}
	}
}

int main() {
	n1 = read(), n2 = read(), m = read();
	rep (i, 1, m) {
		int u = read(), v = read();
		G[u].eb(v);
		G[v].eb(u);
	}
	memset(d, -1, sizeof d);
	bfs(1);
	bfs(n1 + n2);
	int m1 = 0, m2 = 0;
	rep (i, 1, n1) m1 = max(m1, d[i]);
	rep (i, n1 + 1, n1 + n2) {
		m2 = max(m2, d[i]);
	}
	printf("%d\n", m1 + m2 + 1);
	return 0;
}
