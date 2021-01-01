#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N = 1e5 + 9;

int cnt[N];
int L, R;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": ";
        cin >> L >> R;
        memset(cnt, 0, sizeof cnt);
        int T = sqrt(1.0 * R);
        for (int i = 1; i <= T; i++) {
            int start = L + (i - L % i) % i;
            for (int j = start; j <= R; j += i) {
                if (i * i > j) continue;
                cnt[j - L] += 2 * (int)(i & 1) - 1;
                if(i != j / i) cnt[j - L] += 2 * (int)((j / i) & 1) - 1;
            }
        }
        long long res = 0; 
        for (int j = L; j <= R; j++) {
            res += (abs(cnt[j - L]) <= 2);
        }
        cout << res << endl;
    }
    return 0;
}
