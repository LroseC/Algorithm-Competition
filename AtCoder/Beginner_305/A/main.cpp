#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>

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

int main(void)
{
	//Think twice, code once? I'm back.
	i32 x;
	read >> x;
	std::cout << ((x % 5 >= 5 - x % 5) ? (5 - x % 5 + x) : (x - x % 5)) << std::endl;
	return 0;
}
