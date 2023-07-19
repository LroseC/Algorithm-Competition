#include<bits/stdc++.h>
typedef __int128 ll;
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

inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

int main() {
	int tt = read();
	while (tt--) {
		ll n = read();
		bool flag = 0;
		rep(i, 2, 59) {
			ll l = 2, r = 1e9;
			while (l <= r) {
				ll mid = l + r >> 1;
				ll sum = 0;
				ll mul = 1;
				int exit = 0;
				for (int k = 0; k <= i; ++k) {
					sum += mul;
					mul *= mid;
					if (mul < 0 || sum < 0 || sum > n) {
						exit = -1;
						break;
					}
				}
				if (sum == n && exit == 0) {
					flag = 1;
					break;
				}
				else if (sum < n && exit == 0) l = mid + 1;
				else r = mid - 1;
			}
			if (flag) break;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
	return 0;
}
/*
QAQ, 居然卡了下 E 捏
给 LPF 丢脸了捏
好像不是卡了一下啊, 怎么回事
*/
