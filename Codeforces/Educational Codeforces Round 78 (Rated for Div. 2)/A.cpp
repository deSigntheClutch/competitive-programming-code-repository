#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;

int n, m;
string a, b;
int cnt[2][30];

bool check(int x, int y) {
    
    for (int i = x; i <= y; i++) {
        cnt[0][b[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        cnt[1][a[i] - 'a']++;
    }
    for (int i = 0; i < 30; i++) {
        //cout << cnt[0][i] << " " << cnt[1][i] << endl;
        if (cnt[0][i] != cnt[1][i]) 
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        n = a.length();
        m = b.length();
        bool flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                        memset(cnt, 0, sizeof cnt);
                if (check(i, j) == true) {
                    flag = true;
                }
            }
        }
        //cout << check(3, 9) << endl;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}