#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int k; cin>>k;

    for(int tc = 1; tc <= k; tc++){
        int temp; cin>>temp;

        int b, n; cin>>b>>n;

        int sum = 0;
        int rem = n;
        while(rem > 0){
            int cur = rem%b;
            rem /= b;
            sum += cur*cur;
        }
        cout<<tc<<" "<<sum<<endl;
    }
}