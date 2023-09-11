#include<bits/stdc++.h>
using namespace std;
const int N=2e6+11;
void solve() {
	map<int,bool> mp;
	int n = 0, k = 0;
	cin>>n>>k;
	std::vector<int> a(n + 1), b;
	for(int i=1;i<=n;i++) 
		cin>>a[i], mp[a[i]]=1;
	for(int i=1;i<=n;i++)
		if(mp.count(a[i]^k)) {
			cout<<"Alice"<<endl;
			return;
		}
	if(!mp[k]) {
		cout<<"Draw"<<endl;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(a[i]!=k&&mp[a[i]]) {
			b.emplace_back(a[i]);
			mp[a[i]]=0;
		}
	}
	if(b.size()==0) cout<<"Bob"<<endl;
	else if(b.size()==1) cout<<"Bob"<<endl;
	else if(b.size()==3) {
		if((b[0]^b[1]^b[2])==k) cout<<"Bob"<<endl;
		else cout<<"Draw"<<endl; 
	}
	else cout<<"Draw"<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}
