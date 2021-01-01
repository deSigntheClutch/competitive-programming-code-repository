//  g++ -std=c++14 B.cpp -o b && ./b
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;

long long a[N], sum[N];
int n, k;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        set<long long> ss;
        long long maxi = -INF;

        for (int i = 1; i <= n; i++) {
            if (i == n) {
                maxi = max(maxi, sum[i] - *ss.begin());
            }
            else {
                maxi = max(maxi, sum[i]);
                maxi = max(maxi, sum[i] - *ss.begin());
            }
            ss.insert(sum[i]);
        }
        if (maxi >= sum[n]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}