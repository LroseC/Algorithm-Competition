#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e5;

i32 s[N + 10];

void work(void)
{
	read >> n;
	for (i32 i = 1; i <= n; ++i) {
		read >> s[i];
		add(s[i], 1);
	}
	while (true) {
		i32 t = query();
		add(t, 1);

		i32 op; read >> op;
		if (op == -1) break;
		else insert(op, -1);
	}
}

int main(void)
{
	//Think tiwce, code once? I'm back.
	std::ios::sync_with_stdio(false);
	i32 tt; read >> tt;
	while (tt--) {
		clear();
		work();
	}
	return 0;
}
