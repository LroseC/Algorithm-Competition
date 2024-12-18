#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
#define read std::cin

const int N = 1e5 + 10;

i32 top, n;
char s[N];
char stk[N];
bool vis[N][2];

void clear(void)
{
		top = 0;
	for (i32 i = 0; i <= n; ++i) {
		vis[i][0] =  vis[i][1] = 0;
	}
}

bool insert(char ch)
{
	i32 type = (ch == '(') ? 0 : 1;
	if (top && ch == stk[top]) {
		if (vis[top][type]) return 1;
		vis[top][type] = 1;
		top -= 1;
	} else {
		stk[++top] = ch;
	}
	return 0;
}

void work(void)
{
	read >> s;
	n = strlen(s);
	for (i32 i = 0; i < n; ++i) {
		if (s[i] == ')') s[i] = '(';
		if (s[i] == ']') s[i] = '[';
	}
	for (i32 i = 0; i < n; ++i) {
		if (insert(s[i])) {
			puts("No");
			return;
		}
	}
	puts("Yes");
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		work();
		clear();
	}
	return 0;
}
