#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int M = 2e5 + 4;

int sum[M];
map<int, int> cnt;
int n;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cnt.clear();
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            cin >> sum[i];
            cnt[sum[i]] += 1;
            if (cnt[sum[i]] >= 2) flag = true;
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
