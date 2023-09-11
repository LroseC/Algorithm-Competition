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
int fib1[N], fib2[N];

int main() {
	fib1[1] = 1;
	fib2[2] = 1;
	for (int i = 3; i < N; ++i) {
		fib1[i] = fib1[i - 1] + fib1[i - 2];
		if (fib1[i - 1] == -1 || fib1[i] > N) fib1[i] = -1;
		fib2[i] = fib2[i - 1] + fib2[i - 2];
		if (fib2[i - 1] == -1 || fib2[i] > N) fib2[i] = -1;
	}
	int tt = read();
	while (tt--) {
		int n = read(), k = read();
		if (k >= N) {
			puts("0");
			continue;
		}
		if (fib1[k] == -1 && fib2[k] == -1) {
			puts("0");
			continue;
		}
		else if (fib1[k] == -1) {
			puts(n % fib2[k] ? "0" : "1");
		}
		else if (fib2[k] == -1) {
			puts(n % fib1[k] ? "0" : "1");
		}
		else {
			int cnt = 0;
			for (int i = 0; i <= n; ++i)
				if ((n - fib1[k] * i) % fib2[k] == 0) {
					if (i <= (n - fib1[k] * i) / fib2[k]) cnt += 1;
				}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
