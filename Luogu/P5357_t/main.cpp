#include <queue>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 2e5 + 10, M = 2e6 + 10;

i32 n;
char str[M];
i32 stk[N], top;
i32 ch[N][26], id[N], cnt[N], fail[N], idx;

void insert(char str[], i32 index)
{
	i32 u = 0;
	for (i32 i = 1; str[i]; ++i) {
		if (!ch[u][str[i] - 'a']) {
			idx += 1;
			ch[u][str[i] - 'a'] = idx;
		}
		u = ch[u][str[i] - 'a'];
	}
	id[index] = u;
}
void buildAuto(void)
{
	std::queue<i32> q;
	for (i32 i = 0; i < 26; ++i)
		if (ch[0][i]) q.emplace(ch[0][i]);
	while (q.size()) {
		i32 u = q.front(); q.pop();
		stk[++top] = u;
		for (i32 i = 0; i < 26; ++i) {
			if (ch[u][i]) {
				q.emplace(ch[u][i]);
				fail[ch[u][i]] = ch[fail[u]][i];
			}
			else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
}

int main(void)
{
	//Think twice, code once? I'm back.
	std::ios::sync_with_stdio(false);
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> str + 1;
		insert(str, i);
	}
	buildAuto();
	read >> str + 1;
	i32 u = 0;
	for (i32 i = 1; str[i]; ++i) {
		u = ch[u][str[i] - 'a'];
		++cnt[u];
	}
	for (i32 i = top; i >= 1; --i) {
		i32 u = stk[i];
		cnt[fail[u]] += cnt[u];
	}
	for (i32 i = 1; i <= n; ++i) {
		printf("%d\n", cnt[id[i]]);
	}
	return 0;
}
