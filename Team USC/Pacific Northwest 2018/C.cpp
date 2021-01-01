#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod =  998244353;

signed main(){
    int n, k; cin>>n>>k;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int cur; cin>>cur;
        m[cur]++;
    }

    vector<int> a;
    for(pair<int, int> c: m){
        a.push_back(c.second);
    }

    n = a.size();
    vector<vector<int> > dp(n, vector<int>(k+1));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    dp[0][0] = 1;
    dp[0][1] = a[0];
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i + 1 && j <= k; j++){
            //solving dp[i][j]

            dp[i][j] =dp[i-1][j-1]*a[i] + dp[i-1][j];
            dp[i][j] %= mod;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = dp[n-1][k];
    cout<<ans<<endl;
}