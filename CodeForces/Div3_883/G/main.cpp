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

const int N = 10010;

int n, m;
char str[N];
int s[N], t[N], w[N];
int vis[N];
ll dis[N];
priority_queue<pair<ll, int>> q;

void dij(void)
{
	while (q.size()) {
		auto tp = q.top(); q.pop();
		int u = tp.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 1; i <= m; ++i) {
			int v = u;
			v &= s[i];
			v |= t[i];
			if (dis[v] > dis[u] + w[i]) {
				dis[v] = dis[u] + w[i];
				q.emplace(std::make_pair(-dis[v], v));
			}
		}
	}
}

int main() {
	int tt = read();
	while (tt--) {
		n = read(), m = read();
		int st = 0;
		scanf("%s", str);
		for (int i = 0; i < n; ++i)
			if (str[i] == '1') st ^= 1 << i;
		for (int i = 1; i <= m; ++i) {
			w[i] = read();
			s[i] = (1 << n) - 1;
			t[i] = 0;
			scanf("%s", str);
			for (int j = 0; j < n; ++j) {
				if (str[j] == '1') s[i] ^= 1 << j;
			}
			scanf("%s", str);
			for (int j = 0; j < n; ++j)
				if (str[j] == '1') t[i] ^= 1 << j;
		}
		for (int i = 0; i < (1 << n); ++i) {
			vis[i] = 0;
			dis[i] = 0x3f3f3f3f3f3f3f3f;
		}
		dis[st] = 0;
		q.emplace(std::make_pair(dis[st], st));
		dij();
		printf("%lld\n", dis[0] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[0]);
	}
}
