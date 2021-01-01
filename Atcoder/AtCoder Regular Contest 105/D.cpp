#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, xorsum = 0;
int a[N];
map<int, int> cnt;
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cnt.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]] += 1;
            //xorsum ^= a[i];
        }
        if (n & 1)
            cout << "Second" << endl;
        else {
            bool flag = false;
            for (int i = 1; i <= n; i++) {
                if (cnt[a[i]] & 1) flag = true;
            }
            if (flag == true)
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
    }
    return 0;
}
