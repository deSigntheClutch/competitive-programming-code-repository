#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define int long long

using namespace std;

const int N = 1e5 + 5;

int n;
string s, f;
int v10, v01;
bool special[N];

int cal(string t) {
    int cnt[2] = {0, 0};
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') res += cnt[0] * v01;
        else res += cnt[1] * v10;
        cnt[t[i] - '0'] += 1;
    }
    return res;
}

int fill_answer(int v) {
    s = f;
    int cnt[2] = {0, 0};
    int total[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') s[i] = '0' + v;
        total[s[i] - '0'] += 1;
    }
    int res = cal(s);
    int ans = res;
   // cout << s << ": " << res << endl;

    for (int i = 0; i < n; i++) {
        if (special[i]) {
            if (v == 0) {
                res -= cnt[1] * v10 + (total[1] - cnt[1]) * v01;
                res += cnt[0] * v01 + (total[0] - cnt[0] - 1) * v10;
            } else {
                res -= cnt[0] * v01 + (total[0] - cnt[0]) * v10;
                res += cnt[1] * v10 + (total[1] - cnt[1] - 1) * v01;
            }
            ans = min(ans, res);
            s[i] = v^1 + '0';
            cnt[v^1] += 1;
            total[v] -= 1;
            total[v^1] += 1;
            //cout << s << ": " << res << endl;

        } else {
            cnt[s[i] - '0'] += 1;
        }
    }
    //cout << endl;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
//    int T;
//    cin >> T;
//    while (T--) {
        cin >> f;
        n = f.length();
        cin >> v01 >> v10;
        for (int i = 0; i < n; i++) {
            if (f[i] == '?') special[i] = true;
        }
        cout << min(fill_answer(0), fill_answer(1)) << endl;
       // cout << "---" << endl;
//        int cnt = 0;
//        for (int i = 0; i < n; i++) {
//            if (s[i] == '?') {
//                if (v10 * lside[1] + v01 * rside[1] > v10 * rside[0] + v01 * lside[0]) {
//                    s[i] = '1';
//                    lside[1] += 1;
//                } else {
//                    s[i] = '0';
//                    lside[0] += 1;
//                }
//            } else {
//                rside[s[i] - '0'] -= 1;
//                lside[s[i] - '0'] += 1;
//            }
//        }
//        cout << cal(s) << endl;
    //}
}