#include <queue>
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

const int N = 510;

i32 gox[] = {+1, -1,  0,  0};
i32 goy[] = { 0,  0, +1, -1};
i32 n, m, a, b;
i32 dis[N][N];
std::queue<std::pair<i32, i32>> q;

void bfs(void)
{
	while (q.size()) {
		std::pair<i32, i32> t = q.front();
		q.pop();
		i32 x = t.first, y = t.second;
		for (i32 e = 0; e < 4; ++e) {
			i32 xx = x + gox[e];
			i32 yy = y + goy[e];
			if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
			if (dis[xx][yy] == -1) {
				dis[xx][yy] = dis[x][y] + 1;
				q.push(std::make_pair(xx, yy));
			}
		}
	}
}

int main(void)
{
	//Think twice, code once? I'm back.
	read >> n >> m >> a >> b;
	std::memset(dis, -1, sizeof dis); //-1 表示未访问过
	for (i32 i = 1; i <= a; ++i) {
		i32 x, y;
		read >> x >> y;
		dis[x][y] = 0;
		q.push(std::make_pair(x, y));
	}

	bfs();
	for (i32 i = 1; i <= b; ++i) {
		i32 x, y;
		read >> x >> y;
		printf("%d\n", dis[x][y]);
	}
	return 0;
}
