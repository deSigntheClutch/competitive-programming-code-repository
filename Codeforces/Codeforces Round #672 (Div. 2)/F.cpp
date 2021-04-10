#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;
int dp[N];
int a[N];
unordered_map<string, bool> used;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;

    //string s;
    int cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt0 += (a[i] == 0);
        //s += (char)(a[i] + '0');
    }
    int x = cnt0 / (n - cnt0 + 1);
    // int cnt = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i + 1; j <= n; j++) {
    //         if (a[i] == 0 && a[j] == 0) {
    //             bool fd = false;
    //             for (int k = i + 1; k < j; k++) {
    //                 fd |= (a[k] == 1);
    //             }
    //             if (fd) cnt += 1;
    //         }
    //     }
    // }

    // queue<pair<string, int>> q;
    // used[s] = true;
    // q.push({s, cnt});
    // while (!q.empty()) {
    //     auto st = q.front();
    //     q.pop();
    //     string parttern = st.first;
    //     int step = st.second;
    //     for (int i = 0; i < n; i++) {

    //     }
    // }
    return 0;
}