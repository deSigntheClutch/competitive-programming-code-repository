#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1  1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;

int dp[N];
int n;
string s;
int last_valid_a[N];

int main() {
    cin >> s;
    int n = s.length();
    dp[0] = 0;
    bool find_b = false;
    int last_a = -1;
    memset(last_valid_a, -1, sizeof last_valid_a);

    for (int i = 0; i < n; i++) {
        if (find_b == true && last_a != -1) {
            last_valid_a[i] = last_a;
        } else if(find_b == false && i > 0) {
            last_valid_a[i] = last_valid_a[i - 1];
        }
        if (s[i] == 'b') find_b = true;
        if (s[i] == 'a') {
            find_b = false;
            last_a = i;
        }
        //cout << last_valid_a[i] << " ";
    }
   // cout << endl;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            dp[i + 1] = 1;
            if (last_valid_a[i] != -1) {
                dp[i + 1] = (dp[i + 1] + dp[last_valid_a[i] + 1]) % MOD;
            }
        }
        if (i > 0) dp[1 + i] = (dp[i] + dp[i + 1]) % MOD;
        continue;
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n] << endl;
    return 0;
}

