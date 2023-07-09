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

int a[N], b[N];
ll sum[N];

int main() {
	int n = read(), K = read();
	vector<int> dy;
	rep (i, 1, n) {
		a[i] = read();
		b[i] = read();
		dy.eb(a[i] + 1);
	}
	dy.eb(1);
	dy.eb(0);
	sort(dy.begin(), dy.end());
	dy.erase(unique(dy.begin(), dy.end()), dy.end());
	rep (i, 1, n) {
		a[i] = lower_bound(dy.begin(), dy.end(), a[i] + 1) - dy.begin();
		sum[1] += b[i];
		sum[a[i]] -= b[i];
	}
	rep (i, 1, dy.size() - 1) {
		sum[i] += sum[i - 1];
		if (sum[i] <= K) {
			printf("%d\n", dy[i]);
			return 0;
		}
	}
	return 0;
}
