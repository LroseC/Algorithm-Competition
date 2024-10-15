#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e18;

long long myrand(void)
{
	return 1ll * rand() * rand() % mod + 1;
}

int main(void)
{
	srand(time(NULL));
	int tt = 100;
	printf("%d\n", tt);
	while (tt--) {
		printf("%lld %lld\n", myrand(), myrand());
	}
	return 0;
}
