#include <queue>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;
using pii = std::pair<i32, i32>;
#define read std::cin

const int S = 1 << 10, N = 40;
const int gox[] = { 0,  0, +1, -1};
const int goy[] = {+1, -1,  0,  0};

i32 n, m, K, d, sx, sy;
bool vis[N][N];
i32 x[N], y[N], val[N], atk[N], dis[N];
i32 f[S][N][N], cost[S][N][N], monster[S][N][N];

void init_cost(void)
{
	std::memset(cost, 0, sizeof cost);
	for (i32 st = 0; st < (1 << K); ++st) {
		for (i32 t = 0; t < K; ++t) {
			if (st >> t & 1) {
				for (i32 i = 1; i <= n; ++i)
					for (i32 j = 1; j <= m; ++j) {
						if (std::abs(x[t] - i) + std::abs(y[t] - j) <= dis[t])
							cost[st][i][j] += atk[t];
					}
			}
		}
	}
}
void init_monster(void)
{
	std::memset(monster, -1, sizeof monster);
	for (i32 st = 0; st < (1 << K); ++st) {
		for (i32 t = 0; t < K; ++t) {
			if (st >> t & 1) {
				monster[st][x[t]][y[t]] = t;
			}
		}
	}
}
i32 check_monster(i32 st, i32 x, i32 y)
{
	return monster[st][x][y];
}

void dijkstra(i32 dis[N][N], i32 state)
{
	std::priority_queue<std::pair<i32, pii>> heap;
	std::memset(vis, 0, sizeof vis);
	for (i32 i = 1; i <= n; ++i)
		for (i32 j = 1; j <= m; ++j) {
			heap.emplace(dis[i][j], std::make_pair(i, j));
		}
	while (heap.size()) {
		pii pr = heap.top().second;
		i32 x = pr.first, y = pr.second;
		heap.pop();
		if (vis[x][y]) continue;
		vis[x][y] = 1;
		for (i32 dir = 0; dir < 4; ++dir)
			for (i32 delt = 1; delt <= d; ++delt) {
				i32 xx = x + gox[dir] * delt;
				i32 yy = y + goy[dir] * delt;
				if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
				if (check_monster(state, xx, yy) != -1) break;
				if (dis[x][y] - cost[state][x][y] > dis[xx][yy]) {
					dis[xx][yy] = dis[x][y] - cost[state][x][y];
					heap.emplace(dis[xx][yy], std::make_pair(xx, yy));
				}
			}
	}
}

void work(void)
{
	read >> n >> m >> K >> d;
	for (i32 i = 0; i < K; ++i) {
		read >> x[i] >> y[i] >> val[i] >> atk[i] >> dis[i];
	}
	read >> sx >> sy;
	init_cost();
	init_monster();

	std::memset(f, 0, sizeof f);
	for (i32 st = 1; st < (1 << K); ++st) {
		for (i32 i = 1; i <= n; ++i) {
			for (i32 j = 1; j <= m; ++j) {
				if (check_monster(st, i, j) != -1) continue;
				for (i32 dir = 0; dir < 4; ++dir) {
					i32 to_st = st;
					i32 val_s = 0;
					for (i32 delt = 1; delt <= d; ++delt) {
						i32 xx = i + gox[dir] * delt;
						i32 yy = j + goy[dir] * delt;
						if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
						i32 mon = check_monster(to_st, xx, yy);
						if (mon != -1) {
							to_st ^= 1 << mon;
							val_s += val[mon];
							continue;
						}
//						if (st == 1 && i == 1 && j == 1) {
//							printf("%d %d %d = %d\n", to_st, xx, yy, f[to_st][xx][yy] + val_s - cost[to_st][xx][yy]);
//						}
						f[st][i][j] = std::max(f[st][i][j], f[to_st][xx][yy] + val_s - cost[to_st][xx][yy]);
					}
				}
			}
		}
		dijkstra(f[st], st);
	}
	for (i32 st = 1; st < (1 << K); ++st) {
		for (i32 i = 1; i <= n; ++i) {
			for (i32 j = 1; j <= m; ++j) {
//				printf("f[%d][%d][%d] = %d\n", st, i, j, f[st][i][j]);
			}
		}
	}
	std::cout << f[(1 << K) - 1][sx][sy] << std::endl;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
//		clear();
		work();
	}
	return 0;
}
