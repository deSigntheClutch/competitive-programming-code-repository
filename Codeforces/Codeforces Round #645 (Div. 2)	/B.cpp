#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int MOD = 1e9 + 7;

int a[N], R[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin>>a[i];
        sort(a, a + n);
        int cnt = 1;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (a[i] <= 1 + i) {
                cnt = max(i + 2, cnt);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
