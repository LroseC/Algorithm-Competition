#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
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

const int N = 1e3 + 10;

i32 n, K;
i32 fa[N], a[N], have[N];
std::vector<i32> G[N];

void clear(void)
{
	for (int i = 1; i <= n; ++i) G[i].clear();
}
void calc(i32 u, i32 &uncolor)
{
	if (a[u] == -1) ++uncolor;
	else have[a[u]] = 1;
	for (int v : G[u]) calc(v, uncolor);
}

int main(void)
{
	//Think twice, code once. I'm back.
	i32 tt; read >> tt;
	while (tt--) {
		read >> n >> K;
		for (int i = 2; i <= n; ++i) {
			read >> fa[i];
			G[fa[i]].emplace_back(i);
		}
		for (int i = 1; i <= n; ++i) read >> a[i];
		bool flag = 0;
		for (int i = 1; i <= n; ++i) {
			i32 uncolor = 0, cnt = 0;
			calc(i, uncolor);
			for (int j = 0; j < K; ++j)
				if (!have[j]) ++cnt;
			if ((uncolor == 1 && cnt <= 1 && have[K] == 0) || (uncolor == 0 && cnt == 0 && have[K] == 0)) flag = 1;
			for (int j = 0; j <= n; ++j) have[j] = 0;
		}
		puts(flag ? "Alice" : "Bob");
		clear();
	}
	return 0;
}
