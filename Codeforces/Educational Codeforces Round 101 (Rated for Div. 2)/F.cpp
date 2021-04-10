#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 3;
const int INF = 1e15;

int n, k;
int l[N];
int sum[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    sort(l + 1, l + 1 + n, greater<int>());
    sum[0] = 1, sum[1] = -1;
    int pt = 1, total = 0;
    for (int i = 0; i < N - 5; i++) {
        sum[i + 1] += sum[i];
        int cur = sum[i];
        total += cur;
        if (total >= k) {
            cout << i << endl;
            return 0;
        } else if (total + sum[i + 1] >= k) {
            cout << i + 1 << endl;
            return 0;
        }
        while (cur >= 1 && pt <= n) {
            int a = l[pt] / 2, b = l[pt] / 2;
            if (l[pt] % 2 == 0) a -= 1;
            pt += 1;
            sum[i + 2] += 2;
            sum[i + 2 + a]--;
            sum[i + 2 + b]--;
            cur -= 1;
            total -= 1;
        }
    }
    cout << -1 << endl;
    return 0;
}