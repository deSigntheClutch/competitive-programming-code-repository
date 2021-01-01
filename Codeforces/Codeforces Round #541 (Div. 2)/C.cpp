#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];

int main() {
    cin >>  n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i += 2) {
        cout << a[i] << " ";
    }
    int end = n - 1;
    if (n & 1) end -= 1;

    for (int i = end; i >= 0; i-=2) {
        cout << a[i] << " ";
    } 
    cout << endl;
    return 0;
}