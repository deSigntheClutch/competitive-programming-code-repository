#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int xor_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xor_sum ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << (xor_sum ^ a[i]) << " ";
    }
    cout << endl;
    return 0;
}