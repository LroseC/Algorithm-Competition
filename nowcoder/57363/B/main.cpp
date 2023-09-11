#include <cctype>
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <algorithm>

using i32 = int32_t;
using i64 = int64_t;

#define read std::cin

const int N = 1e7 + 10;
int tot,phi[N],prime[N];
bool flag[N];
void eular(int n) {
	phi[1]=1; tot=0;
	for(int i=2;i<=n;i++) {
		if(!flag[i]) {
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot&&prime[j]<=n/i;j++) {
			flag[i*prime[j]]=1;
			if(!(i%prime[j])) {
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int eular1(int n) {
	int ans=n;
	for(int i=2;i*i<=n;i++) {
		if(n%i==0) {
			ans/=i; ans*=(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans/=n,ans*=(n-1);
	return ans;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	getPhi();
	return 0;
}
