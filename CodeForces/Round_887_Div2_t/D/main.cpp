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
		std::vector<pii> a(n);
		std::vector<int> res(n);
		for (int i = 0; i < n; ++i) {
			a[i].fi = read();
			a[i].se = i;
		}
		std::sort(a.begin(), a.end());
		int i = 0, j = n - 1, cntp = 0, cntn = 0, mx = n;
		bool fail = 0;
		while (i <= j) {
			int l = a[i].fi, r = n - a[j].fi;
			if (l == cntp) {
				res[a[i].se] = -(mx--);
				i += 1;
				cntn += 1;
			}
			else if (r == cntn) {
				res[a[j].se] = (mx--);
				j -= 1;
				cntp += 1;
			}
			else {
				fail = 1;
				break;
			}
		}
		if (fail) puts("NO");
		else {
			puts("YES");
			for (int i = 0; i < n; ++i)
				printf("%d ", res[i]);
			puts("");
		}
	}
	return 0;
}
