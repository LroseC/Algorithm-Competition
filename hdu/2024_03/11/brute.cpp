# include <bits/stdc++.h>
# define N 200010
int n;
long long a[N],b[N],dir[N],mxx[4],mnx[4],mxy[4],mny[4];
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
long long calc(int t) {
    if(t<0) return 9e18;
    long long mxx=-9e18,mnx=9e18,mxy=-9e18,mny=9e18;    
    int i;
    for(i=1;i<=n;i++) {
        long long lsx=1ll*t*dx[dir[i]]+a[i],lsy=1ll*t*dy[dir[i]]+b[i];
        mxx=std::max(mxx,lsx);
        mnx=std::min(mnx,lsx);
        mxy=std::max(mxy,lsy);
        mny=std::min(mny,lsy);
    }
    return 2*(mxx-mnx+mxy-mny);
}
std::vector<int> vec;
int main() {
    int i;
    char s[5];
    scanf("%d",&n);
    for(i=1;i<=n;i++)  {
        scanf("%lld%lld%s",a+i,b+i,s+1);
        if(s[1]=='E') dir[i]=0;
        else if(s[1]=='W') dir[i]=1;
        else if(s[1]=='S') dir[i]=2;
        else if(s[1]=='N') dir[i]=3;
        mxx[dir[i]]=std::max(mxx[dir[i]],a[i]);
        mnx[dir[i]]=std::min(mnx[dir[i]],a[i]);
        mxy[dir[i]]=std::max(mxy[dir[i]],b[i]);
        mny[dir[i]]=std::min(mny[dir[i]],b[i]);
    }
    long long l=0,r=2e9,mid;
    while(l<r) {
        mid=l+r+1>>1;
        if(calc(mid+1)-calc(mid)>0) r=mid-1;
        else l=mid;
    }
    long long ans=std::min(std::min(calc(l),calc(l+1)),std::min(calc(l-1),calc(l+2)));
    // vec.push_back(0);
    // long long _=std::max(mxx[2],mxx[3]);
    // vec.push_back(mxx[1]-_); vec.push_back(_-mxx[0]);
    // vec.push_back((mxx[1]-mxx[0])/2);
    // vec.push_back((mxx[1]-mxx[0]+1)/2);

    // _=std::min(mnx[2],mnx[3]);
    // vec.push_back(mnx[1]-_); vec.push_back(_-mnx[0]);
    // vec.push_back((mnx[1]-mnx[0])/2);
    // vec.push_back((mnx[1]-mnx[0]+1)/2);

    // _=std::min(mny[0],mny[1]);
    // vec.push_back(mny[2]-_); vec.push_back(_-mny[3]);
    // vec.push_back((mny[2]-mny[3])/2);
    // vec.push_back((mny[2]-mny[3]+1)/2);

    // _=std::max(mxy[0],mxy[1]);
    // vec.push_back(mxy[2]-_); vec.push_back(_-mxy[3]);
    // vec.push_back((mxy[2]-mxy[3])/2);
    // vec.push_back((mxy[2]-mxy[3]+1)/2);
    // long long ans=9e18;
    // for(auto t:vec) {
    //     if(t>=0) ans=std::min(ans,calc(t));
    // }
    printf("%lld\n",ans);
    return 0;
}
