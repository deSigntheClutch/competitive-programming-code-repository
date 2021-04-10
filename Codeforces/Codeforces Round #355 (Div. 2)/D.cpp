#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 1;
const int INF = 1e9 + 7;

vector<pair<int, int>> pos[N * N];
int n, m, p;
int a[N][N];
int dp[2][N][N];
set<int> s[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pos[a[i][j]].push_back({i, j});
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= m; k++) {
            dp[0][j][k] = INF;
            dp[1][j][k] = INF;
        }
    }

    pos[0].push_back({1, 1});
    dp[0][1][1] = 0;
    s[1].insert(1);

    for (int i = 1; i <= p; i++) {
        for (auto x : pos[i]) {
            dp[i % 2][x.first][x.second] = INF;
            for (int j = 1; j <= n; j++) {
                // for (auto xx : s[j]) cout << xx << " ";
                // cout << endl;
                auto itr = s[j].upper_bound(x.second);
                if (itr != s[j].end()) {
                  //  cout << j << " " << *itr << " " <<  dp[(i + 1) % 2][j][*itr] << " -> " << x.first << " " << x.second <<  endl;
                    dp[i % 2][x.first][x.second] = min(dp[i % 2][x.first][x.second], dp[(i + 1) % 2][j][*itr] + abs(x.first - j) + abs(*itr - x.second));
                }
                if (itr != s[j].begin()) {
                    itr--;
                    //cout << j << " " << *itr << " " <<  dp[(i + 1) % 2][j][*itr] << " -> " << x.first << " " << x.second <<  endl;
                    dp[i % 2][x.first][x.second] = min(dp[i % 2][x.first][x.second], dp[(i + 1) % 2][j][*itr] + abs(x.first - j) + abs(*itr - x.second));
                }
            }
            // cout << dp[i % 2][x.first][x.second] << "!" << endl;
        }
        for (int j = 1; j <= n; j++) {
            s[j].clear();
        }
        for (auto x : pos[i]) {
            //cout << x.first << " in " << x.second << endl;
            s[x.first].insert(x.second);
        }
        // for (int h = 1; h <= n; h++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout << dp[i % 2][h][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for (auto x : pos[i]) {
            dp[(i + 1) % 2][x.first][x.second] = INF;
        }
    }

    int min1 = INF;
    for (auto x : pos[p]) {
        min1 = min(min1, dp[p % 2][x.first][x.second]);
    }
    cout << min1 << endl;
    return 0;
}