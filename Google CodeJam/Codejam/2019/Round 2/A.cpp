#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const double eps = 1e-9;

int n;
long long a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cin >> n;
        cout << "Case #" << cs << ": ";
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        set<pair<long long, long long>> S;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] > a[j] && b[i] < b[j]) {
                    long long gcd = __gcd(abs(a[i] - a[j]), abs(b[i] - b[j]));
                    long long x = abs(a[i] - a[j]) / gcd;
                    long long y = abs(b[i] - b[j]) / gcd;
                    S.insert(make_pair(x, y));
                }
            }
        }
        cout << (int)S.size() + 1 << endl;
    }
    return 0;
}
