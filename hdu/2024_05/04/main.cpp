# include <bits/stdc++.h>
# define N 100010
# define Q 1000010
struct pair{
	int x,y,lcm;
}pr[8888888];
std::vector<int> e[N],ad[N],qry[N];
bool operator <(const pair &i,const pair &j) {return i.x<j.x || i.x==j.x && i.y<j.y;}
bool operator ==(const pair &i,const pair &j) {return i.x==j.x && i.y==j.y;}
int pr_n=0,fat[N],dep[N],siz[N],son[N],top[N],dfl[N],dfr[N],dfn,rr[Q],xx[Q],tr[N],ans[N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void dfs1(int x,int fa) {
	fat[x]=fa; dep[x]=dep[fa]+1; siz[x]=1; son[x]=0; dfl[x]=++dfn;
	for(auto v:e[x]) if(v!=fa) {
		dfs1(v,x);
		siz[x]+=siz[v];
		if(!son[x] || siz[v]>siz[son[x]]) son[x]=v;
	}
	dfr[x]=dfn;
}
void dfs2(int x,int t) {
	top[x]=t;
	if(son[x]) dfs2(son[x],t);
	for(auto v:e[x]) if(v!=fat[x] && v!=son[x]) {
		dfs2(v,v);
	}
}
int lca(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]>dep[top[y]]) x=fat[top[x]];
		else y=fat[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
int n;
void add(int x,int y) {
	for(int i=x;i<=n;i+=i&(-i)) tr[i]+=y;
}
int query(int x) {
	int ans=0;
	for(int i=x;i>=1;i-=i&(-i)) ans+=tr[i];
	return ans;
}
int rd() {
	int num=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) num=num*10+ch-'0';
	return num;
}
void _() {
	int q,i,x,y;
	n=rd();
	for(i=1;i<=n;i++) e[i].clear();
	for(i=1;i<n;i++) {
		x=rd(); y=rd();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dep[1]=0; dfn=0; dfs1(1,1); dfs2(1,1);
	for(i=1;i<=100000;i++) ad[i].clear(), qry[i].clear();
	for(i=1;i<=pr_n;i++) {
		if(pr[i].x<=n && pr[i].y<=n) ad[pr[i].lcm].push_back(dfl[lca(pr[i].x,pr[i].y)]);
	}
	q=rd();
	for(i=1;i<=q;i++) {
		rr[i]=rd(); xx[i]=rd();
//		  scanf("%d%d",rr+i,xx+i);
		qry[xx[i]].push_back(i);
	}
	memset(tr,0,n+5<<2);
	for(i=1;i<=100000;i++) {
		for(auto x:ad[i]) add(x,2);
		if(i<=n) add(i,1);
		for(auto qid:qry[i]) {
			ans[qid]=query(dfr[rr[qid]])-query(dfl[rr[qid]]-1);
		}
	}
	for(i=1;i<=q;i++) printf("%d ",ans[i]);
	puts("");
}
int main() {
	freopen("data.in","r",stdin);
	freopen("1.out","w",stdout);
	int T,n=1e5,i,j,k;
	for(i=1;i<=n;i++) {
		for(j=i;j<=n;j+=i) {
			for(k=j+i;1ll*j*k/i<=n;k+=i) pr[++pr_n]=(pair){j,k};
		}
	}
	std::sort(pr+1,pr+pr_n+1);
	pr_n=std::unique(pr+1,pr+pr_n+1)-pr-1;
	for(i=1;i<=pr_n;i++) pr[i].lcm=1ll*pr[i].x*pr[i].y/gcd(pr[i].x,pr[i].y);
	T = rd();
	while(T--) _();
	return 0;
}
