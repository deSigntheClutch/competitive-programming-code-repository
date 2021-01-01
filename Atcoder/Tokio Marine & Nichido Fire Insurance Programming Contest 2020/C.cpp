#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;

int n, k;
int a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int ite = 0; ite < 100; ite++) {
        if (ite == k) break;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) {
            cnt[max(1, i - a[i])] += 1;
            cnt[min(n, i + a[i]) + 1] -= 1;
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
            a[i] = cnt[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " "; 
    }
    cout << endl;
    return 0;
}