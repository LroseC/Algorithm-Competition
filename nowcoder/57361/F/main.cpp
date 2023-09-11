# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define SZ(v) ((int)(v).size())
# define N 500010
# define MOD 998244353 
typedef std::vector<int> poly;
const int G=3;
int qpow(int x,int k) {
	int res=1;
	while(k) {
		if(k&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; k>>=1;
	}
	return res;
}
void ntt(int a[],int n,int inv) {
	int i,j,m,k,gn,u,v,invn,g;
	for(i=0,j=0;i<n;i++) {
		if(i<j) std::swap(a[i],a[j]);
		for(int l=(n>>1);(j^=l)<l;l>>=1);
	}
	for(m=1,k=2;k<=n;m=k,k<<=1) {
		gn=qpow(G,(MOD-1)/k);
		if(inv==-1) gn=qpow(gn,MOD-2);
		for(i=0;i<n;i+=k) {
			g=1;
			for(j=0;j<m;j++,g=1ll*g*gn%MOD) {
				u=a[i+j],v=a[i+j+m];
				a[i+j]=(1ll*g*v+u)%MOD; a[i+j+m]=(u-1ll*g*v%MOD+MOD)%MOD;
			}
		}
		for(i=0;i<n;i++) a[i]=(a[i]%MOD+MOD)%MOD;
	}
	if(inv==1) return;
	invn=qpow(n,MOD-2);
	for(i=0;i<n;i++) a[i]=1ll*a[i]*invn%MOD;
}

poly operator*(poly a,poly b) {
	static int A[N],B[N],C[N];
	int lim=1,i;
	while(lim<SZ(a)+SZ(b)-1) lim<<=1;
	for(i=0;i<SZ(a);i++) A[i]=a[i];
	for(i=SZ(a);i<lim;i++) A[i]=0;
	for(i=0;i<SZ(b);i++) B[i]=b[i];
	for(i=SZ(b);i<lim;i++) B[i]=0;
	ntt(A,lim,1); ntt(B,lim,1);
	for(i=0;i<lim;i++) C[i]=1ll*A[i]*B[i]%MOD;
	ntt(C,lim,-1);
	poly c;
	for(i=0;i<SZ(a)+SZ(b)-1;i++) c.push_back(C[i]);
	return c;
}
poly operator+(poly a,poly b) {
	int i;
	while(SZ(a)<SZ(b)) a.push_back(0);
	while(SZ(b)<SZ(a)) b.push_back(0);
	for(i=0;i<SZ(a);i++) a[i]=(a[i]+b[i])%MOD;
	return a;
}
poly operator-(poly a,poly b) {
	int i;
	while(SZ(a)<SZ(b)) a.push_back(0);
	while(SZ(b)<SZ(a)) b.push_back(0);
	for(i=0;i<SZ(a);i++) a[i]=(a[i]-b[i]+MOD)%MOD;
	return a;
}
poly operator*(poly a,int b) {
	int i;
	b=(b%MOD+MOD)%MOD;
	for(i=0;i<SZ(a);i++) a[i]=1ll*a[i]*b%MOD;
	return a;
} 
poly operator*(int b,poly a) { return a*b; }
poly inv(poly a) {
	if(SZ(a)==1) return poly(1,qpow(a[0],MOD-2));
	int len=(SZ(a)+1)>>1;
	poly b=a; b.resize(len);
	b=inv(b);
	b=b+b-b*b*a; b.resize(SZ(a));
	return b;
}
poly derivative(poly a) {
	int i;
	for(i=0;i<SZ(a)-1;i++) a[i]=1ll*a[i+1]*(i+1)%MOD;
	a[SZ(a)-1]=0; 
	return a;
}
poly inter(poly a) {
	int i;
	for(i=SZ(a)-1;i>=1;i--) a[i]=1ll*a[i-1]*qpow(i,MOD-2)%MOD;
	a[0]=0;
	return a;
}
poly ln(poly a) {	
	poly res=inter(derivative(a)*inv(a));
	res.resize(SZ(a));
	return res;
}
poly exp(poly a) {
	if(SZ(a)==1) return poly(1,1);
	int len=(SZ(a)+1)>>1;
	poly b=a; b.resize(len); 
	b=exp(b); b.resize(SZ(a),0); 
	b=b*(poly(1,1)-ln(b)+a); b.resize(SZ(a));
	return b;
}
poly pow(poly a,int k) {return exp(k*ln(a));}
void _() {
	int n,m,k,i,fac=1,C=1;
	scanf("%d%d%d",&n,&m,&k);
	if(k&1) report("0\n");
	poly p,q; p.clear();
	fprintf(stderr, "???\n");
	for(i=0;i<=n && i<=k;i++) {
		fprintf(stderr, "i = %d\n", i);
		if(i&1) p.push_back(0);
		else p.push_back(1ll*C*qpow(fac,MOD-2)%MOD);
		fac=1ll*fac*(i+1)%MOD;
		C=1ll*C*(n-i)%MOD;
	}
	fprintf(stderr, "???\n");
	q=pow(p,m);
	fprintf(stderr, "???\n");
	fprintf(stderr, "k = %d, q[k] = %d\n", k, q[k]);
	fprintf(stderr, "k = %d, q[k] = %d\n", k, q[k]);
	printf("%d",1ll*q[k]*qpow(2,m)%MOD);
	fprintf(stderr, "???\n");
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

