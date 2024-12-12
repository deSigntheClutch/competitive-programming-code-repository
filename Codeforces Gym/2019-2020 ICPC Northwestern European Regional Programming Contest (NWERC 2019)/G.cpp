
#include "bits/stdc++.h"
using namespace std;

const int N = 2e3 + 1;
const int B = 1e6;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    double alpha = 1.0 * k / n, beta = 1.0 * (n - k) / n;
    for (int i = 0; i < n; i++) {
        cout << alpha * a[i] + beta * (a[i] + a[(i - 1 + n) % n]) + beta << " ";
    }
    cout << endl;
    return 0;
}
