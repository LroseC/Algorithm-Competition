#include <vector>
#include <random>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

i32 randInt(i32 l, i32 r)
{ return rand() % (r - l + 1) + l; }

void work(void)
{
	i32 n = (rand() & 1) ? 2 : randInt(3, 10);
	i32 m = (rand() & 1) ? 2 : randInt(3, 10);
	std::vector<i32> val(n * m);
	for (i32 i = 0; i < n * m; ++i) val[i] = i + 1;
	while (std::is_sorted(val.begin(), val.end()))
		std::random_shuffle(val.begin(), val.end());
	std::cout << n << ' ' << m << '\n';
	for (i32 i = 0; i < n; ++i, std::cout << '\n')
		for (i32 j = 0; j < m; ++j) {
			std::cout << val[i * m + j] << ' ';
		}
}

int main(void)
{
	std::random_device srd;
	srand(srd() * time(NULL));
	i32 tt = 10;
	std::cout << tt << std::endl;
	while (tt--) work();
	return 0;
}
