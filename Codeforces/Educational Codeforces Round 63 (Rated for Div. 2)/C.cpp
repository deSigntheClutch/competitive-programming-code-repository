#include <bits/stdc++.h>
using namespace std;
#define int long long

const double pi = acos(-1.0);
const int N = 3e5 + 5;

int n, m;
int events[N];
int alarms[N];

int nbgcd(int x, int y) {
    return x ? nbgcd(y % x, x) : y;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> events[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> alarms[i];
    }
    int gcd = events[1] - events[0];
    for (int i = 1; i + 1 < n; i++) {
        gcd = nbgcd(gcd, events[i + 1] - events[i]);
    }
    for (int i = 0; i < m; i++) {
        if (gcd % alarms[i] == 0) {
            cout << "YES" << endl;
            cout << ((events[0] % alarms[i] == 0)? alarms[i] : events[0] % alarms[i] ) << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
