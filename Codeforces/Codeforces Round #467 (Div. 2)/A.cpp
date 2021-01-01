#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
         cin >> a[i];         
    }
    sort(a + 1, a + 1 + n);
    int len = unique(a + 1, a + 1 + n) - (a + 1);
    cout << len - (a[1] == 0) << endl;
    return 0;
}