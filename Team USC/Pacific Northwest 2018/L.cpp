#include<bits/stdc++.h>
using namespace std;
int n,got,ans,l[2000],h[2000];
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>l[i]>>h[i];
    }
    for(ans=n;ans>=0;--ans){
        got=0;
        for(int i=0;i<n;++i)if(ans>=l[i]&&ans<=h[i])++got;
        if(got==ans){
        cout<<ans<<endl;
        exit(0);
        }
    }
    puts("-1");
}