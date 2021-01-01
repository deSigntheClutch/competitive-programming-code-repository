#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

string str;
int n, k;
int a[N];
int sum[N];
int left_next[2][N], right_next[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    for (int i = 1; i <= n; i++) {
        if (str[i - 1] == '0') a[i] = 0;
        else a[i] = 1;
        sum[i] = sum[i - 1] + a[i];
    }
    bool flag1 = false, flag0 = false;
    for (int i = 1; i + k - 1 <= n; i++) {
        if (sum[n] == sum[i + k - 1] - sum[i - 1]) flag0 = true;
        if (n - sum[n] == k - sum[i + k - 1] + sum[i - 1]) flag1 = true;
    }
    if (flag1 || flag0) {
        cout << "tokitsukaze" << endl;
        return 0;
    }
    int prev0 = 0, prev1 = 0;
    left_next[0][0] = 0;
    left_next[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) prev0 = i;
        else prev1 = i;
        left_next[0][i] = prev0;
        left_next[1][i] = prev1; 
    }
    prev0 = n + 1, prev1 = n + 1;
    right_next[0][n + 1] = n + 1;
    right_next[1][n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) prev0 = i;
        else prev1 = i;
        right_next[0][i] = prev0;
        right_next[1][i] = prev1; 
    }
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        if ((i - 1 - (sum[i - 1] - sum[0]) == 0 && left_next[0][n] - right_next[0][i + k] + 1 <= k) 
        || (n - i - k + 1 - (sum[n] - sum[i + k - 1]) == 0 && left_next[0][i - 1] - right_next[0][1] + 1 <= k))
            cnt1 += 1;
        if ((sum[i - 1] - sum[0] == 0 && left_next[1][n] - right_next[1][i + k] + 1 <= k) 
        || (sum[n] - sum[i + k - 1] == 0 && left_next[1][i - 1] - right_next[1][1] + 1 <= k))
            cnt0 += 1;
    }
    if (cnt1 == n - k + 1 && cnt0 == n - k + 1) {
        cout << "quailty" << endl;
    } else {
        cout << "once again" << endl;
    }
    return 0;
}

/*

20 17
01001001101010111011

*/