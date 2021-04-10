#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 5;

int A, B, n;
int a[N], b[N];
int sum;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B >> n;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        for (int i = 1; i <= n; i++) {
            int times = (b[i] + A - 1) / A;
            sum += times * a[i];
        }

        if (sum < B) {
            cout << "YES" << endl;
            continue;
        }

        bool flag = false;
        for (int i = 1; i <= n; i++) {
            int times = (b[i] + A - 1) / A;
            sum -= times * a[i];
            int men_round = (B - sum + (a[i] - 1)) / a[i];
            if (men_round >= times) flag = true;
            sum += times * a[i];
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}