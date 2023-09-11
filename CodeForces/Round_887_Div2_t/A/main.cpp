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

int main() {
	int tt = read();
	while (tt--) {
		int n = read();
		vector<int> a(n);
		for (int i = 0; i < n; ++i) a[i] = read();
		if (!is_sorted(a.begin(), a.end())) {
			printf("0\n");
			continue;
		}
		vector<int> dec(n - 1);
		int mn = 1e9;
		for (int i = 0; i < n - 1; ++i)
			mn = min(mn, a[i + 1] - a[i]);
		printf("%d\n", (mn + 1 + 1) / 2);
	}
	return 0;
}
