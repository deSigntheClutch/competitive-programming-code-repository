//g++ -std=c++14 B.cpp -o b && ./b
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k, l;
string s;
vector<int> a, b;
int sum[N], p[N];
int dp[N][2];

bool check(int cost) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        if (i >= l) {
            if (dp[i][0] < sum[i] - sum[i - l] - cost + dp[i - l][0]) {
                dp[i][0] = sum[i] - sum[i - l] - cost + dp[i - l][0];
                dp[i][1] = dp[i - l][1] + 1;
            } else if (dp[i][0] == sum[i] - sum[i - l] - cost + dp[i - l][0] && dp[i][1] > dp[i - l][1] + 1) {
                dp[i][1] = dp[i - l][1] + 1;
            }
        }
        if (dp[i][0] < dp[i - 1][0] || (dp[i][0] == dp[i - 1][0] && dp[i][1] > dp[i - 1][1])) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        } 
    }
    return k >= dp[n][1];
}

int solve(vector<int> x) {
    memset(p, 0, sizeof p);
    for (int xx : x) {
        p[xx] = 1;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
    if ((long long)k * l >= n) return 0;
    int left = 0, right = n, md;
    for (int itr = 0; itr < 22; itr++) {
        md = (left + right) >> 1;
        if (check(md)) right = md;
        else left = md + 1;
    } 
    int res = dp[n][0], choice = dp[n][1];
    check(md - 1);
    int available_zero = dp[n][1] - choice;
    return sum[n] - (res + md * choice + min(available_zero, k - choice) * md);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> l;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') a.push_back(i + 1);
        else b.push_back(i + 1);
    }
    cout << min(solve(b), solve(a)) << endl;
    return 0;
}