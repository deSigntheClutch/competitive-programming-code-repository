#include <bits/stdc++.h>
using namespace std;

int n;
int pref[3234];

int main() {
    ios::sync_with_stdio(false);
    pref[0] = 0;
    for (int i = 1; i <= 1500; i++) {
        pref[i] = pref[i - 1] + i;
    }
    cin >> n;
    if(n == 0) {
        cout << "a" << endl;
        return 0;
    }
    vector<int> vec;
    while (n) {
        int t = upper_bound(pref + 1, pref + 1 + 1500, n) - pref;
        t--;
        vec.push_back(t);
        n -= pref[t];
    }
    char s = 'a';
    for (int x : vec) {
        for (int i = 0; i < x + 1; i++) {
            cout << s;
        }
        s++;
    }
    cout << endl;
    return 0;
}
