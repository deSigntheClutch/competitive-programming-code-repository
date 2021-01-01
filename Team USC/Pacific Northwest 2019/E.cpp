#include <bits/stdc++.h>
using namespace std;

int cnt[1000];
const int mod = 11092019;

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        cnt[c] += 1;
    }
    int ans = 1;
    for (int i = 'a'; i <= 'z'; i++) {
        ans = (long long) ans * (cnt[i] + 1) % mod;
    }
    cout << ans << endl;
    return 0;
}