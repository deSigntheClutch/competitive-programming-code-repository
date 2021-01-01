#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N = 1e5 + 9;

int n, k;
int64 opt_left[N], opt_right[N];
pair<int, int> p[N];
int c[N], x[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": ";
        cin >> k >> n;
        for (int i = 1; i <= n; i++) { 
            cin >> p[i].first;
        }
        for (int i = 1; i <= n; i++) { 
            cin >> p[i].second;
        }
        sort(p + 1, p + 1 + n);
        for (int i = 1; i <= n; i++) { 
            c[i] = p[i].second;
            x[i] = p[i].first;
        }
        
        priority_queue<int64> Q;
        int64 carry = 0;
        
        for (int i = 2; i <= n; i++) {
            Q.push(c[i - 1] - x[i - 1]);
            carry += c[i - 1] - x[i - 1];
            if (i - k / 2 < 1) {
                continue;
            }
            if ((int)Q.size() > k / 2) {
                carry -= Q.top();
                Q.pop();
            }
            opt_left[i] = carry;
        }
        
        while(!Q.empty()) Q.pop();
        carry = 0;
        
        for (int i = n - 1; i >= 1; i--) {
            Q.push(c[i + 1] + x[i + 1]);
            carry += c[i + 1] + x[i + 1];
            if (i + (k - k / 2) > n) {
                continue;
            }
            if ((int)Q.size() > (k - k / 2)) {
                carry -= Q.top();
                Q.pop();
            }
            opt_right[i] = carry;
        }
        int64 ans = 1e18;
        for (int i = 1; i <= n; i++) {
            if (i - k / 2 < 1 || i + (k - k / 2) > n) continue;
            //cout << i << " " << opt_left[i] << " " << opt_right[i] << " " << c[i] << " " << ((k - k / 2) - k / 2) * x[i] << endl;
            ans = min(ans, opt_left[i] + opt_right[i] + c[i] - ((k - k / 2) - k / 2) * x[i]); 
        }
        cout << ans << endl;
    }
    return 0;
}