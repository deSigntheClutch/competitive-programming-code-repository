#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long n, m, k;
long long a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    long long prev_page = 0;
    long long cnt = 0, dumped = 0;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        long long cur_page = (a[i] - dumped - 1) / k + 1;
        int pt = i;
        while (pt <= m && ((a[pt] - dumped - 1) / k + 1) == cur_page) pt++;
        cnt += 1;
        dumped += pt - i;
        i = pt - 1;
    }
    cout << cnt << endl;
    return 0;
}