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

void work(void)
{
	int n = read(), K = read();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) a[i] = read();
	if (a[0] != 1) puts("1");
	else {
		ll l = 1, r = 1e11;
		while (l < r) {
			auto check = [&](ll pos)->bool {
				ll sum = 0;
				for (int i = 1; i <= K; ++i) {
					if (sum >= pos) return 0;
					auto t = std::upper_bound(a.begin(), a.end(), pos - sum);
					int num = t - a.begin();
					sum += num;
				}
				if (sum < pos) return 1;
				return 0;
			};
			ll mid = l + r >> 1;
			if (check(mid))
				r = mid;
			else
				l = mid + 1;
		}
		printf("%lld\n", l);
	}
}

int main() {
	int tt = read();
	while (tt--) {
		work();
	}
	return 0;
}
