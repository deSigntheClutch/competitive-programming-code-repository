#include<bits/stdc++.h>
using namespace std;
const int mx=10000000+2;
int md[mx],phi[mx];
vector<int>fact[mx];
long long ans;
int solve(int i,int j){
    // i with [1,j]
    int rt=0;
    for(int k=1;k< 1<<fact[i].size();++k){
        int pro=1;
        for(int z=0;z<fact[i].size();++z)if(k>>z&1)pro*=fact[i][z];
        rt+=(__builtin_popcount(k)&1?1:-1)*(j/pro);
    }
    //cerr<<"solve"<<i<<' '<<j<<' '<<j-rt<<endl;
    return j-rt;
}

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=1;i<=mx;++i)md[i]=i;
    for(int i=2;i*i<mx;++i){
        if(md[i]==i){
            for(int j=i*2;j<mx;j+=i){
                md[j]=i;
                fact[j].push_back(i);
            }
        }
    }
    for(int i=a;i<=b;++i){
        if(i==1){
            ans+=d-c+1;
            continue;
        }
        if(md[i]==i){
            ans+=d-c+1-(d/i-(c-1)/i);
            //cerr<<i<<' '<<d-c+1-(d/i-(c-1)/i)<<endl;
        }
        else ans+=solve(i,d)-solve(i,c-1);
    }
    cout<<ans<<endl;
}