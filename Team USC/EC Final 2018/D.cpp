#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
signed main(){
	int t; cin>>t;
	while(t--){
		int n, m; cin>>n>>m;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		
		for(int i = 0; i < m; i++){
			cin>>b[i];
		}
		
		if(n <= m) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}