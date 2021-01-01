#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
vector<int> va, vb;
bool visa[N], visb[N];
int cnt1[N], cnt2[N];
vector<int> divisor[N];

int main() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisor[j].push_back(i);
        }
    }
    int tcase = 0;
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        va.clear();
        vb.clear();
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        memset(visa, 0, sizeof visa);
        for (int i = 0; i < n; i++) {
            if (visa[i] == false) {
                visa[i] = true;
                int cur = a[i];
                int cnt = 1;
                while (cur != i) {
                    visa[cur] = true;
                    cnt += 1;
                    cur = a[cur];
                }
                va.push_back(cnt);
            }
        }
        memset(visb, 0, sizeof visb);
        for (int i = 0; i < m; i++) {
            if (visb[i] == false) {
                visb[i] = true;
                int cur = b[i];
                int cnt = 1;
                while (cur != i) {
                    visb[cur] = true;
                    cnt += 1;
                    cur = b[cur];
                }
                vb.push_back(cnt);
                cnt2[cnt] += 1;
            }
        }
        int ans = 1;
        for (int x : va) {
            int tmp = 0;
            for (int t : divisor[x]) {
                tmp = (tmp + (long long)cnt2[t] * t % MOD) % MOD;
            }
            ans = (long long) ans * tmp % MOD;
        }
        cout << "Case #" << ++tcase << ": " << ans << endl;
    }
    return 0;
}
