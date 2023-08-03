#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

struct FSI
{
	template<typename T>
	FSI& operator>>(T &res)
	{
		res = 0; T f = 1; char ch = getchar();
		while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
		while (isdigit(ch)) { res = res * 10 + (ch - '0') * f; ch = getchar(); }
		return *this;
	}
} read;

const int N = 1e6 + 10;

i32 n, m;
i32 nex[N];
char s1[N], s2[N];

void getNex(char str[])
{
	for (int i = 2, j = 0; i <= n; ++i) {
		while (j && str[i] != str[j + 1])
			j = nex[j];
		if (str[i] == str[j + 1]) ++j;
		nex[i] = j;
	}
}
void match()
{
	for (int i = 1, j = 0; i <= m; ++i) {
		while (j && s2[i] != s1[j + 1])
			j = nex[j];
		if (s2[i] == s1[j + 1]) ++j;
		if (j == n) {
			printf("%d\n", i - n + 1);
			j = nex[j];
		}
	}
}

int main(void)
{
	//Think twice, code once? I'm back.
	scanf("%s", s2 + 1);
	scanf("%s", s1 + 1);
	n = strlen(s1 + 1);
	m = strlen(s2 + 1);
	getNex(s1);
	match();
	for (int i = 1; i <= n; ++i) printf("%d ", nex[i]);
	puts("");
	return 0;
}
