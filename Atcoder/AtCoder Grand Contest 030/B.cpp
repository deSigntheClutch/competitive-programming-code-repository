#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int n;
long long L, x[N];
long long pref[2][N], suff[2][N];

long long cal(int type, int from, int to) {
    if (type == 0) { // cw 
        return (x[from] < x[to]) ? (x[to] - x[from]) : (L - (x[from] - x[to]));
    } else {
        return (x[from] > x[to]) ? (x[from] - x[to]) : (L - (x[to] - x[from]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> L >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        pref[0][i] = pref[0][i - 1] + cal(0, i - 1, i);
        if (i >= 2) suff[1][i] = suff[1][i - 1] + cal(1, 1, i);
    }
    for (int i = n; i >= 1; i--) {
        pref[1][i] = pref[1][i + 1] + cal(1, ((i + 1 <= n) ? (i + 1) : 0), i);
        if (i <= n - 1) suff[0][i] = suff[0][i + 1] + cal(0, i + 1, i);
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, pref[0][i] + suff[0][i + 1]);
    }
    for (int i = n; i > 1; i--) {
        ans = max(ans, pref[1][i] + suff[1][i - 1]);
    }
    cout << ans << endl;
    return 0;
}

/*

10 3
2
7
9


*/
