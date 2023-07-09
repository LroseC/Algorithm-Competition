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

const int N = 110;

char a[N][N];
char b[N][N];

int main() {
	int n = read();
	rep (i, 1, n) {
		scanf("%s", a[i] + 1);
	}
	rep (i, 1, n)
		rep (j, 1, n) b[i][j] = a[i][j];
	rep (i, 2, n) {
		b[1][i] = a[1][i - 1];
		b[i][n] = a[i - 1][n];
	}
	rep (i, 1, n - 1) {
		b[n][i] = a[n][i + 1];
		b[i][1] = a[i + 1][1];
	}
	rep (i, 1, n) printf("%s\n", b[i] + 1);
}
