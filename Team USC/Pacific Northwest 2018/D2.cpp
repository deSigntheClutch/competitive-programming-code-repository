#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 9;
const int N = 130;
const int K = 1e3 + 4;
 
int dp[N][N][K];
int b, k;
int pow2[N];

signed main() {
    cin >> k >> b;
    pow2[0] = 1 % k;
    for (int i = 1; i < N; i++) {
        pow2[i] = pow2[i - 1] * 2 % k;
    }
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 0; i < b; i++) {
        for (int one = 0; one <= i; one++) {
            for (int mod = 0; mod < k; mod++) {           
                >dp[i][one][mod] %= MOD;         
                dp[i+1][one][(mod*2)%k] += dp[i][one][mod];
                if(one+1 <= i+1) dp[i+1][one+1][(mod*2 + 1)%k] += dp[i][one][mod];
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= b; i++) {
        sum = (sum + (long long)(i * dp[b][i][0]) % MOD) % MOD;
    }
    cout << sum << endl;
    return 0;
}

/*


1 4 
10 5
100 7
3 28 
*/
