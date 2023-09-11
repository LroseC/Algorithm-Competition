# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 210
int a[N][N],b[N],t[N];
bool vis[N];
int abs(int x) {return x>=0?x:-x;}
int calc(int n) {
	int i,j,cnt=0;
	memset(vis,false,sizeof(vis));
	for(i=1;i<=n;i++) if(!vis[i]) {
		for(j=i;!vis[j];j=t[j]) vis[j]=true;
		cnt++;
	}
	return n-cnt;
}
void _() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) scanf("%d",a[i]+j);
	}
	if(n>2 && m>2) {
		int cnt=0,x,y;
		for(i=1;i<=n;i++) {
			for(j=1;j<=m && a[i][j]==a[i][1]+j-1;j++);
			if(j<=m || a[i][1]%m!=1) report("NSFW\n");
			b[i]=(a[i][1]-1)/m+1;
			cnt+=(i!=b[i]);
		}
		assert(cnt);
		if(cnt!=2) report("NSFW\n");
		for(x=1;x<=n && x==b[x];x++);
		for(y=n;y>=1 && y==b[y];y--);
		if(b[x]==y && b[y]==x) report("FOX\n");
		else report("NSFW\n");
	}
	else if(n==2 && m==2) {
		int A=a[1][1],B=a[1][2],C=a[2][1],D=a[2][2];
		assert(!(A==1 && B==2 && C==3 && D==4));
		if(C==1 && D==2 && A==3 && B==4) report("FOX\n");
		if(D==1 && C==2 && B==3 && A==4) report("CAT\n");
		if(B==1 && A==2 && D==3 && C==4) report("FOX\n");
		report("NSFW\n");
	}
	else if(n==2) {
		int cnt1=0,cnt2=0;
		for(j=1;j<=m;j++) cnt1+=(a[1][j]<=m);
		for(j=1;j<=m;j++) cnt2+=(a[2][j]<=m);
		for(j=1;j<=m && abs(a[1][j]-a[2][j])==m;j++);
		if((cnt1==0 && cnt2==m || cnt1==m && cnt2==0) && j>m) {
			bool rev;
			if(cnt1==0 && cnt2==m) {
				rev=true;
				for(j=1;j<=m;j++) t[j]=a[2][j];
			} else {
				rev=false;
				for(j=1;j<=m;j++) t[j]=a[1][j];
			}
			if(rev==calc(m)%2) report("CAT\n");
			else report("NSFW\n");
			
		} else {
			report("NSFW\n");
		}
	}
	else {
		int cnt1=0,cnt2=0;
		for(i=1;i<=n;i++) cnt1+=(a[i][1]%2==1);
		for(i=1;i<=n;i++) cnt2+=(a[i][2]%2==1);
		for(i=1;i<=n && abs(a[i][1]-a[i][2])==1;i++);
		if((cnt1==0 && cnt2==n || cnt1==n && cnt2==0) && i>n) {
			bool rev;
			if(cnt1==0 && cnt2==n) {
				rev=true;
				for(i=1;i<=n;i++) t[i]=a[i][1]/2;
			} else {
				rev=false;
				for(i=1;i<=n;i++) t[i]=a[i][2]/2;
			}
			if(rev!=calc(n)%2) report("FOX\n");
			else report("NSFW\n");
			
		} else {
			report("NSFW\n");
		}
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) {
		_();
	}
	return 0;
}

