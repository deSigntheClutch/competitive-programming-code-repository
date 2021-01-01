#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int n, m, k;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int move = n - 11;
    int cnt = 0;
    int vasya = move - move / 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '8') {
            cnt += 1;
            continue;
        }
        else vasya -= 1;
        if (vasya == 0) {
            int pt = i + 1;
            while (pt < n && s[pt] == '8') {
                pt += 1;
                cnt += 1;
            }
            break;
        }
    }
    if (cnt > move / 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
