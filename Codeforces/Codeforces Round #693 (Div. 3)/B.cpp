#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3300 + 5;
const int B = 1455 + 5;

int n;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int s = 0;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            if (a[i] == 1)
                c1 += 1;
            else
                c2 += 1;
        }
        if (s & 1)
            cout << "no" << endl;
        else {
            bool flag = false;
            int half = s / 2;
            for (int i = 0; i <= c2; i++){
                int cur = i * 2;
                if (half - cur < 0) break;
                if (c1 >= half - cur) flag = true; 
            }
            if (flag) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}