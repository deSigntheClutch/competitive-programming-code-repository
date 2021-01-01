#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, d;
int pizza[11111];
bool is_n_prime[777777];
vector<int> prime;


signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";
        cin >> n >> d;
        for (int i = 0; i < n; i++) {
            cin >> pizza[i];
        }
        int ans;
        if (d == 2) {
            ans = 1;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (pizza[i] == pizza[j]) {
                        ans = min(ans, 0ll);
                        break;
                    }
                }
            }
            cout << ans << endl;
        } else {
            ans = 2;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (pizza[i] == pizza[j] && pizza[k] == pizza[i]) {
                            ans = min(ans, 0ll);
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (pizza[i] == pizza[j]) {
                        for (int k = 0; k < n; k++) {
                            if (i == k || j == k) continue;
                            if (pizza[k] > pizza[i]) ans = min(ans, 1ll);
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    if (i == k) continue;
                    if (pizza[k] % 2 == 0 && pizza[k] / 2 == pizza[i]) {
                        ans = min(ans, 1ll);
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}