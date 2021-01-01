#include <bits/stdc++.h>
using namespace std;

const int N = 333;
const int M = 2e5 + 4;

int cnt[N];
int rel[N];
int n, k;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        memset(rel, 0, sizeof rel);
        cin >> n >> k;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            rel[a[i]]++;
            cnt[b[i]]++;
        }
        bool flag = true;
        int use = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            if (rel[i] > cnt[i]) {
                if (rel[i] % k == cnt[i] % k) {
                    use += (rel[i] - cnt[i]) / k;
                } else {
                    flag = false;
                }
            } else if (rel[i] == cnt[i]) {
                continue;
            } else {
                if (rel[i] % k == cnt[i] % k) {
                    int real_use = -(rel[i] - cnt[i]) / k;
                    if (real_use > use) {
                        flag = false;
                    } else {
                        use -= real_use;
                    }
                } else {
                    flag = false;
                }
            }
        }
        if (use == 0 && flag == true) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
