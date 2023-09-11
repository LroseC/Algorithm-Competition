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
		int n = read(), K = read();
		std::vector<int> a(n), dec(n);
		for (int i = 0; i < n; ++i) {
			a[i] = read();
			dec[i] = (i == 0 ? a[i] : a[i] - a[i - 1]);
		}
		if (n == 1) {
			printf("%d\n", a[0]);
			continue;
		}
		ll res = 0;
		for (int i = 0, j = n; i < j; ++i) {
			if (dec[i] <= 0) continue;
			while (i < j && dec[j] >= 0) --j;
			int tmp = std::min(dec[i], -dec[j]);
			res += tmp;
			dec[i] -= tmp;
			dec[j] += tmp;
		}
		ll sumn = 0, sump = 0;
		int cntp = 0;
		for (int i = 0; i < n; ++i) {
			if (dec[i] < 0) sumn -= dec[i];
			else if (dec[i] > 0) {
				sump += dec[i];
				cntp += 1;
			}
		}
		ll t = sumn / (K - 1);
		if (t * (K - 1) != sumn) t += 1;
		res += t * K;
		cntp = std::min((ll)cntp, t);
		cntp = std::min((ll)cntp, sump / (K - 1));
		sump -= cntp;
		res += sump;
		printf("%lld\n", res);
	}
}
