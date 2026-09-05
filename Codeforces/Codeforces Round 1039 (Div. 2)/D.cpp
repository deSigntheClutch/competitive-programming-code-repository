#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
int p[N];
bool special[N];

int main() {
    int T; cin >> T;

    while (T--) {
        cin >> n;

        memset(special, 0, sizeof(special));

        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (i > 0 && p[i - 1] < p[i]) {
                special[i - 1] = 1;
            }
        }

        long long sum = 0;
        int x = 1;
        for (int i = 0; i < n; i++) {
            sum += (long long)x * (n + 1 - x);
            x++;
        }
       // cout << sum << endl;

        for (int i = 0; i < n; i++) {
            if (special[i]) {
                sum -= (long long)(i + 1) * (n - 1 - i);
            }
        }

        cout << sum << endl;
    }
    return 0;
}