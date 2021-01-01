#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int INF = 2e9 + 5;

long long res[N];
int a[N];
int n, w, m;
int q[N], l, r;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> a[j];
        }
        l = 0, r = 0;
        int shift = w - m;
        for (int j = 1; j <= m; j++) {
            while (r - l > 0 && a[q[r - 1]] <= a[j]) r--;
            if (j <= m) q[r++] = j;
            if (j <= shift || j + shift > w) res[j] += max(0, a[q[l]]);
            else res[j] += a[q[l]];
            if (j - q[l] == shift) l++;
        }
    }
    for (int i = 1; i <= w; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}