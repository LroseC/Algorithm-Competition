#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using pii = std::pair<i32, i32>;
using ppi = std::pair<pii, i32>;
#define read std::cin
#define x first
#define y second
#define mp std::make_pair

const i32 gox[] = {1, -1, 0, 0};
const i32 goy[] = {0, 0, 1, -1};

const int N = 3010, LEN = 1e5 + 10;

i32 n, m, K;
i32 dis[N][N][4], f[N][N];
bool vis[N][N][4];
char map[N][N];
i32 tim[N][N];
pii body[LEN];

void BFS1(void)
{
	std::memset(dis, -1, sizeof dis);
	std::queue<ppi> q;
	for (i32 k = 0; k < 4; ++k) {
		if (body[1].x + gox[k] == body[2].x && body[1].y + goy[k] == body[2].y) {
			dis[body[1].x][body[1].y][k] = 0;
			q.emplace(body[1], k);
		}
	}
	i32 top = 0, nowdis = 0;
	while (q.size() || top < K) {
		auto t = q.size() ? q.front() : mp(mp(-1, -1), -1);
		pii pos = t.first;
		i32 x = pos.x, y = pos.y;
		i32 ko = t.second;
		if (q.size()) {
			nowdis = dis[x][y][ko];
		}
		if (top < K && (!q.size() || top + 1 <= nowdis)) {
			nowdis = top + 1;
			bool sec = 0;
			i32 xx = body[K - top].x;
			i32 yy = body[K - top].y;
			for (i32 k = 0; k < 4; ++k) {
				if (dis[xx][yy][k] != top + 1) continue;
				if (!vis[xx][yy][k]) {
					vis[xx][yy][k] = 1;
					if (dis[xx][yy][k] != -1) {
						sec = 1;
						x = xx, y = yy, ko = k;
						break;
					}
				}
			}
			if (!sec) {
				top += 1;
				continue;
			}
		} else {
			q.pop();
		}
//		if (top < dis[x][y][ko] < K && !vis[dis[x][y][ko]]) {
//			vis[dis[x][y][ko]] = 1;
//			i32 xx = body[K - dis[x][y][ko]].x;
//			i32 yy = body[K - dis[x][y][ko]].y;
//			for (i32 k = 0; k < 4; ++k) {
//				if (dis[xx][yy][k] != -1) {
//					q.emplace(mp(xx, yy), k);
//				}
//			}
//		}
		for (i32 k = 0; k < 4; ++k) {
			if (k == ko) continue;
			i32 xx = x + gox[k];
			i32 yy = y + goy[k];
			if (xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
			if (dis[xx][yy][k ^ 1] != -1 || map[xx][yy] == '#') continue;
			if (dis[x][y][ko] < tim[xx][yy]) {
				dis[xx][yy][k ^ 1] = tim[xx][yy] + 1;
			} else {
				dis[xx][yy][k ^ 1] = dis[x][y][ko] + 1;
				q.emplace(mp(xx, yy), k ^ 1);
			}
		}
	}
}
void BFS2(void)
{
	std::memset(dis, -1, sizeof dis);
	std::queue<pii> q;
	dis[body[1].x][body[1].y][0] = 0;
	q.emplace(body[1].x, body[1].y);
	while (q.size()) {
		i32 x = q.front().x, y = q.front().y;
		q.pop();
		for (i32 k = 0; k < 4; ++k) {
			i32 xx = x + gox[k];
			i32 yy = y + goy[k];
			if (xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
			if (dis[xx][yy][0] != -1 || map[xx][yy] == '#') continue;
			dis[xx][yy][0] = dis[x][y][0] + 1;
			q.emplace(xx, yy);
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n >> m >> K;
	for (i32 i = 1; i <= K; ++i) {
		read >> body[i].x >> body[i].y;
		tim[body[i].x][body[i].y] = K - i;
	}
	for (i32 i = 1; i <= n; ++i) {
		read >> (map[i] + 1);
	}
	BFS1();
	std::memset(f, 0x3f, sizeof f);
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= m; ++j) {
			for (i32 k = 0; k < 4; ++k) {
				if (dis[i][j][k] == -1) continue;
				f[i][j] = std::min(f[i][j], dis[i][j][k]);
			}
		}
	}
	BFS2();
	i32 delt = std::max(0, K - 2);
	u64 res = 0;
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= m; ++j) {
			if (dis[i][j][0] != -1) {
				f[i][j] = std::min(f[i][j], dis[i][j][0] + delt);
			}
			if (f[i][j] != f[0][0]) {
				res += u64(f[i][j]) * u64(f[i][j]);
			}
		}
	}
	printf("%llu\n", res);
	return 0;
}
