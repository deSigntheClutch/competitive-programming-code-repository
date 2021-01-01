#include<bits/stdc++.h>

using namespace std;

int main(){
    int k; cin>>k;
    string a, b; cin>>a>>b;
    int n = a.length();
    vector<int> d(n);
    //cout<<"A: "<<a<<endl;
    for(int i = 0; i < n; i++){
        d[i] = (a[i] != b[i]);
    }
    sort(d.begin(), d.end());

    //first k are correct

    // for(int i = 0; i < n; i++){
    //     cout<<d[i]<<" ";
    // }
    // cout<<endl;

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i < k){
            if(d[i] == 0) ans++;
        }else{
            if(d[i] == 1) ans++;
        }
    }
    cout<<ans<<endl;

}