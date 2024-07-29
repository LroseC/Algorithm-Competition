# include <bits/stdc++.h>
# define N 250010
int a[N],b[N],c[N],id[N];
void _() {
	int n,q,i,j,k;
	long long sum;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++) scanf("%d",a+i);
	for(i=0;i<n;i++) scanf("%d",b+i);
	for (i = 0; i < n; ++i) {
		c[i] = -10 / log10(1 - (i + 1.0) / n);
	}
	for(i=0;i<n;i++) id[i]=i;
	std::sort(id,id+n,[](const int &i,const int &j){return b[i]>b[j];});
	// for(i=0;i<n;i++) printf("%d\n",id[i]);2
	for(i=1;i<=1 && i<=q;i++) {
		scanf("%d",&k); sum=0;
		for(j=0;j<n;j++) a[j]=std::max(a[j],b[(j+k)%n]), sum+=a[j];
		printf("%lld\n",sum);
	}
	for(;i<=q;i++) {
		scanf("%d",&k);
		for(j=0;j<n;j++) {
			if (i > c[j]) break;
			int bi=id[j],ai=(id[j]-k+n)%n,pre=a[ai];
			a[ai]=std::max(a[ai],b[bi]);
			sum+=a[ai]-pre;
		}
		printf("%lld\n",sum);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}
