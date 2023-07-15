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

const int N = 1e6 + 10;

i32 n, cnt[2];
i32 a[N], arr[N];

bool check(i32 x)
{
	cnt[0] = cnt[1] = 0;
	for (i32 i = 1; i <= n; ++i) {
		if (a[i] >= x) arr[i] = 1;
		else arr[i] = 0;
	}
	std::vector<i32> vec;
	for (i32 l = 1, r = l; l <= n; l = r + 1) {
		while (r + 1 <= n && arr[r + 1] == arr[l]) r += 1;
		i32 len = r - l + 1;
		cnt[arr[l]] += len / 2;
		if (len & 1) {
			if (vec.size() && vec.back() == arr[l]) {
				vec.pop_back();
				cnt[arr[l]] += 1;
			}
			else {
				vec.emplace_back(arr[l]);
			}
		}
	}
	i32 tmp = std::min(cnt[0], cnt[1]);
	cnt[0] -= tmp;
	cnt[1] -= tmp;
	if (!cnt[0] && !cnt[1]) {
		if (vec.front() == 0) return 0;
		else return 1;
	}
	if (cnt[0] && vec.front() == 0) return 0;
	if (cnt[1] && vec.front() == 1) return 1;
	if (cnt[0]) {
		if (vec.size() / 2 + 1 < cnt[0]) return 0;
		return 1;
	}
	else {
		if (vec.size() / 2 + 1 <= cnt[1]) return 1;
		return 0;
	}
}

int main(void)
{
	i32 tt; read >> tt;
	while (tt--) {
		read >> n;
		for (i32 i = 1; i <= n; ++i) {
			read >> a[i];
		}
		i32 l = 1, r = n;
		while (l < r) {
			i32 mid = l + r + 1 >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
