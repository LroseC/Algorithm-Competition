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

int a[100010];
int cnt[100], cnt2[100];

int main() {
	int tt = read();
	while (tt--) {
		rep (i, 1, 9) cnt[i] = cnt2[i] = 0;
		int n = read();
		rep (i, 1, n) cnt[read()] += 1;
		int stage = 0;
		printf("- 0\n");
		fflush(stdout);
		int undel = 0;
		while (true) {
			rep (i, 1, n) {
				a[i] = read();
			}
			if (stage == 0) {
				rep (i, 1, 9) cnt2[i] = 0;
				rep (i, 1, n) {
					cnt2[a[i]] += 1;
				}
				rep (i, 1, 9) {
					if (cnt2[i] == cnt[i] + 1) {
						undel = i;
						break;
					}
				}
				if (undel) {
					stage = 1;
					printf("- %d ", n - cnt2[undel]);
					rep (i, 1, n)
						if (a[i] != undel) printf("%d ", i);
					puts("");
					fflush(stdout);
					n = cnt2[undel];
				}
				else {
					printf("- 0\n");
					fflush(stdout);
				}
			}
			else {
				bool sec = 0;
				rep (i, 1, n)
					if (a[i] != undel) {
						printf("! %d\n", i);
						fflush(stdout);
						sec = 1;
						break;
					}
				if (sec) break;
				printf("- 0\n");
				fflush(stdout);
			}
		}
	}
}
