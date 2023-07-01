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

i32 dis[] = {0, 3, 1, 4, 1, 5, 9, 2, 6};
i32 sum[1000];

int main(void)
{
	//Think twice, code once? I'm back.
	for (char i = 'A' + 1; i <= 'G'; i += 1) {
		i32 pos = i - 'A';
		sum[pos] = sum[pos - 1] + dis[pos];
	}
	char p, q;
	scanf("%c %c", &p, &q);
	if (p > q) std::swap(q, p);
	printf("%d\n", sum[q - 'A'] - sum[p - 'A']);
	return 0;
}
