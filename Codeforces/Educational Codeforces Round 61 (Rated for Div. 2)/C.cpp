#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int n, q;
int l[N], r[N];
int sum[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    int total = 0;
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        sum[l[i]]++;
        sum[r[i] + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        if (sum[i] > 0) total += 1;
    }
    //cout << total << endl;
    int ans = 0;
    for (int fst = 1; fst <= q; fst++) {
        int tmp = total;
        for (int x = l[fst]; x <= r[fst]; x++) {
            sum[x] -= 1;
            if (sum[x] == 0) tmp -= 1;
        }
        for (int j = 1; j <= n; j++) {
            cnt[j] = cnt[j - 1] + (sum[j] == 1);
           // cout << cnt[j] << " ";
        }
        //cout << endl;
        for (int j = 1; j <= q; j++) {
            if (j == fst) continue;
            ans = max(ans, tmp - (cnt[r[j]] - cnt[l[j] - 1]));
        }
        for (int x = l[fst]; x <= r[fst]; x++) {
            sum[x] += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
