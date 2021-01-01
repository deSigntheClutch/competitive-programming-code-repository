#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] == i + 1) {
            swap(p[i], p[i + 1]);
            cnt++;
        }
    }
    if (p[n - 1] == n) cnt++;
    cout << cnt << endl;
    return 0;
}


