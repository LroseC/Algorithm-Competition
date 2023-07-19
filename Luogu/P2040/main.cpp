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

i32 a[10][10], b[10][10];
bool flg[10][10];

bool check(void)
{
//	for (i32 i = 1; i <= 3; ++i, puts(""))
//		for (i32 j = 1; j <= 3; ++j)
//			printf("%d ", flg[i][j]);
//	puts("");
	for (i32 i = 1; i <= 3; ++i)
		for (i32 j = 1; j <= 3; ++j)
			b[i][j] = a[i][j];
	for (i32 i = 1; i <= 3; ++i)
		for (i32 j = 1; j <= 3; ++j)
			if (flg[i][j]) {
				b[i][j] ^= 1;
				b[i - 1][j] ^= 1;
				b[i + 1][j] ^= 1;
				b[i][j - 1] ^= 1;
				b[i][j + 1] ^= 1;
				// 对边界外的操作可以直接无视
			}
	for (i32 i = 1; i <= 3; ++i)
		for (i32 j = 1; j <= 3; ++j)
			if (b[i][j] != 1) return 0;
	return 1;
}
bool dfs(i32 pos, i32 limit) //pos = (x - 1) * 3 + y - 1; 把一个坐标 (x, y) 映射成一个 1 到 9 之间的数
{
	if (pos == 10) { //九个格子已经填完, 搜索结束
		return check();//检查该方案能否点亮所有灯, 是则返回 1.
	}
	i32 x = (pos - 1) / 3 + 1;
	i32 y = (pos - 1) % 3 + 1;
	if (limit) {
		flg[x][y] = 1;
		if (dfs(pos + 1, limit - 1)) return 1; //如果搜索到合法方案, 直接返回 1.
		flg[x][y] = 0;
	}
	if (dfs(pos + 1, limit)) return 1;
	return 0;
}

int main(void)
{
	//Think twice, code once? I'm back.
	for (i32 i = 1; i <= 3; ++i)
		for (i32 j = 1; j <= 3; ++j)
			read >> a[i][j];
	for (i32 i = 0; i <= 9; ++i) {
		if (dfs(1, i)) { // 如果搜索到 i 步点亮所有灯的方案.
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
