#include<bits/stdc++.h>
using namespace std;

const int N = 150 + 5;
const int INF = 1e9 + 1;

char alphabet[5] = {'A', 'E', 'I', 'O', 'U'};
string bins;
int val[N];
int n, m;
int ans = INF; 
int dp[6][N];
int work[555];
int pref[555][N];

int main(){
    ios::sync_with_stdio(false);

    cin >> bins;
    n = bins.length();
    for (int i = 0; i < n; i++) 
        cin >> val[i];

    cin >> m;
    for (int i = 0; i < m; i++) {
        int idx;
        cin >> idx;
        bins[idx - 1] = 'X';
    }

    string ins;
    cin >> ins;

    for (int i = 0; i < n; i++) {
        work[bins[i]] += 1;
    }
    for (int i = 0; i < ins.length(); i++) {
        work[ins[i]] += 1;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) pref[alphabet[i]][j] = (alphabet[i] == bins[j]) * val[j];
            else pref[alphabet[i]][j] = pref[alphabet[i]][j - 1] + (alphabet[i] == bins[j]) * val[j];
        }
    }
    vector<int> perm;
    for (int i = 0; i < 5; i++) 
        perm.push_back(i);
    //cout << bins << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << work[alphabet[i]] << endl;
    // }
    do {
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        // idx from 1 not 0
        for (int i = 0; i < 5; i++) {
            int idx = alphabet[perm[i]];
            if (work[idx] == 0) {
                for (int j = 0; j <= n; j++) {
                    dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
                }
                continue;
            }
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == INF) continue;
                for (int k = j + 1; k <= n; k++) {
                    if (k + work[idx] - 1 <= n) {
                        int left = k - 1;
                        int right = k + work[idx] - 2;
                        dp[i + 1][k + work[idx] - 1] = 
                        min(dp[i + 1][k + work[idx] - 1], dp[i][j] + pref[idx][n - 1] - (pref[idx][right] - ((left - 1 >= 0) ? pref[idx][left - 1] : 0)));
                    }
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            ans = min(ans, dp[5][j]);
        }
    } while(next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
    return 0;    
}