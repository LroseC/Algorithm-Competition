#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

using i32 = long long;
using i64 = long long;
#define read std::cin

i32 n;
i32 gox[] = {1, -1, 0, 0};
i32 goy[] = {0, 0, -1, 1};
i32 maxx[4], minx[4], maxy[4], miny[4];

i64 calc(i32 t)
{
	i64 max, mix, may, miy;
	max = std::max(maxx[0] + t, maxx[1] - t);
	max = std::max(max, std::max(maxx[2], maxx[3]));
	mix = std::min(minx[0] + t, minx[1] - t);
	mix = std::min(mix, std::min(minx[2], minx[3]));
	may = std::max(maxy[3] + t, maxy[2] - t);
	may = std::max(may, std::max(maxy[0], maxy[1]));
	miy = std::min(miny[3] + t, miny[2] - t);
	miy = std::min(miy, std::min(miny[0], miny[1]));
	printf("t = %lld\n", t);
	printf("%lld - %lld + %lld - %lld\n", max, mix, may, miy);
	return 2ll * (max - mix + may - miy);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	read >> n;
	std::memset(minx, 0x3f, sizeof minx);
	std::memset(maxx, 0xcf, sizeof maxx);
	std::memset(miny, 0x3f, sizeof miny);
	std::memset(maxy, 0xcf, sizeof maxy);

	std::vector<i32> tim;

	for (i32 i = 1; i <= n; ++i) {
		i32 x, y; read >> x >> y;
		char d; read >> d;
		i32 dir;
		if (d == 'E') {
			dir = 0;
		} else if (d == 'W') {
			dir = 1;
		} else if (d == 'S') {
			dir = 2;
		} else {
			dir = 3;
		}
		minx[dir] = std::min(minx[dir], x);
		maxx[dir] = std::max(maxx[dir], x);
		miny[dir] = std::min(miny[dir], y);
		maxy[dir] = std::max(maxy[dir], y);
	}
	for (i32 i = 0; i < 4; ++i) {
		tim.emplace_back(maxx[i] - maxx[0]);
		tim.emplace_back(minx[1] - minx[i]);
		tim.emplace_back(miny[2] - miny[i]);
		tim.emplace_back(maxy[i] - maxy[3]);
	}
	tim.emplace_back((maxx[1] - maxx[0]) / 2);
	tim.emplace_back((maxx[1] - maxx[0] + 1) / 2);
	tim.emplace_back((minx[1] - minx[0]) / 2);
	tim.emplace_back((minx[1] - minx[0] + 1) / 2);
	tim.emplace_back((miny[2] - miny[3]) / 2);
	tim.emplace_back((miny[2] - miny[3] + 1) / 2);
	tim.emplace_back((maxy[2] - maxy[3]) / 2);
	tim.emplace_back((maxy[2] - maxy[3] + 1) / 2);
	i64 res = LLONG_MAX;
	for (auto t: tim) {
		if (t < 0) continue;
		res = std::min(res, calc(t));
	}
	std::cout << res << std::endl;
	return 0;
}
