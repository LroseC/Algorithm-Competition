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

using i32 = int32_t;
using i64 = int64_t;

const int N = 2e5 + 10;

int n;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	std::cin >> n;
	int del = 1e9;
	int cnt = 0, cnt2 = 0;
	ll sum = 0;
	rep (i, 1, n) {
		std::cin >> a[i] >> b[i];
		if (a[i] != b[i]) {
			del = std::min(del, std::abs(a[i] - b[i]));
		}
		sum += max(a[i], b[i]);
		if (a[i] > b[i]) ++cnt;
		if (a[i] == b[i]) ++cnt2;
	}
	if (cnt % 2 == 1 && cnt2 == 0) sum -= del;
	printf("%lld\n", sum);
	return 0;
}
