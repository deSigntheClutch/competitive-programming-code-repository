//g++ -std=c++14 B.cpp -o b && ./b
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
long long s;
long long a[N];
long long sum[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        int pt = 0;
        while (pt <= n && sum[pt] <= s) pt++;
        int ans = pt - 1;
        int choice = 0;
        for (int i = 1; i <= n; i++) {
            long long cur = sum[i - 1];
            if (cur > s) break;
            int idx = upper_bound(sum + i + 1, sum + 1 + n, s - cur + sum[i]) - sum;
            //cout << i << " " << idx << endl;
            if (ans < i + idx - 1 - i) {
                choice = i;
                ans = i + idx - 1 - i;
            }
        }
        cout << choice << endl;
    }
    return 0;
}