#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;

int n;
int x[N], m, a, c;

signed main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> a >> c >> x[0];
    for (int i = 1; i <= n; i++) {
        x[i] = (a * x[i - 1] % m + c) % m;
        //cout<<x[i]<<endl;
    }
    

    int ans = 0;

    for(int i = 1; i <= n; i++){

        //check to find a[i];
        int val = x[i];

        int low = 1, high = n, mid;
        while(low < high){
            mid = (low + high)/2;
            if(x[mid] == val){
                break;
            }else if(x[mid] < val){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        mid = (low + high)/2;
        if(x[mid]== val) ans++;

    }
    cout<<ans<<endl;
    return 0;
}