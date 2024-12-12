#include "bits/stdc++.h"
using namespace std;
#define int long long 
int n;
 
signed main() {
    cin >> n;
    int even = n / 3;
    cout << even * n - even * (even - 1) / 2 - even << endl;
    return 0;
}