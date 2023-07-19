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

char G[10][10];

int get(char ch)
{
	if (ch == '.') return 0;
	else if (ch == 'X') return 1;
	else if (ch == 'O') return 2;
	else return 3;
}

int main() {
	int tt = read();
	while (tt--) {
		rep(i, 1, 3) scanf("%s", G[i] + 1);
		int win = 0;
		rep(i, 1, 3) {
			if (G[i][1] == G[i][2] && G[i][1] == G[i][3] && G[i][1] != '.') {
		//		printf("i = %d, 1 = 1, G[i][1] = %c\n", i, G[i][1]);
				win = get(G[i][1]);
			}
			if (G[1][i] == G[2][i] && G[1][i] == G[3][i] && G[1][i] != '.') {
		//		printf("i = %d, 1 = 1, G[1][i] = %c\n", i, G[1][i]);
				win = get(G[1][i]);
			}
		}
		if (G[1][1] == G[2][2] && G[1][1] == G[3][3] && G[1][1] != '.')
			win = get(G[1][1]);
		if (G[1][3] == G[2][2] && G[1][3] == G[3][1] && G[1][3] != '.')
			win = get(G[1][3]);
		if (win == 0) cout << "DRAW\n";
		else if (win == 1) cout << "X\n";
		else if (win == 2) cout << "O\n";
		else cout << "+\n";
	}
}
