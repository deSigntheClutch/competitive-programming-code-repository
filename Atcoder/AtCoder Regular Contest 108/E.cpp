#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 2e9 + 5;
const int TOP_INF = 1e18 + 3;

int a, b;

signed main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";
        int start;
        cin >> a >> b;
        if (a > b) {
            int diff = a - b;
            int l = 1, r = INF, md;
            for (int cs = 0; cs < 62; cs++) {
                md = (l + r) >> 1;
                bool flag = true;
                if (8 * TOP_INF / md <= (md + 1)) {
                    flag = false;
                } else {
                    if (md * (md + 1) > 2 * diff) flag = false;
                }
                if (flag)
                    l = md + 1;
                else
                    r = md;
            }// 1 48 9
            a -= l * (l - 1) / 2;
            start = l;
            swap(a, b);
            bool isSwap = true;
            l = 1, r = INF;
            for (int cs = 0; cs < 62; cs++) {
                md = (l + r) >> 1;
                bool flag = true;
                if (8 * TOP_INF / md <= (start + md - 1)) {
                    flag = false;
                } else {
                    if (md * (start + md - 1) > b) flag = false;
                }
                if (flag)
                    l = md + 1;
                else
                    r = md;
            }
            int ansb = l - 1;
            // a: r + 1, r + 3
            l = 1, r = INF;
            for (int cs = 0; cs < 62; cs++) {
                md = (l + r) >> 1;
                bool flag = true;
                if (8 * TOP_INF / md <= (start + md)) {
                    flag = false;
                } else {
                    if (md * (start + md) > a) flag = false;
                }
                if (flag)
                    l = md + 1;
                else
                    r = md;
            }
            int ansa = l - 1;
            if (ansa == ansb) {
                if (isSwap)
                    cout << 2 * ansa + start - 1 << " " << b - ansb * (start + ansb - 1) << " " << a - ansa * (start + ansa) << endl;
                else
                    cout << 2 * ansa + start - 1 << " " << a - ansa * (start + ansa) << " " << b - ansb * (start + ansb - 1) << endl;
            } else if (ansa < ansb) {
                if (isSwap)
                    cout << 2 * ansa + start << " " << b - ansb * (start + ansb - 1) << " " << a - ansa * (start + ansa) << endl;
                else
                    cout << 2 * ansa + start << " " << a - ansa * (start + ansa) << " " << b - ansb * (start + ansb - 1) << endl;
            }
        } else {
            int diff = b - a;
            int l = 1, r = INF, md;
            for (int cs = 0; cs < 62; cs++) {
                md = (l + r) >> 1;
                bool flag = true;
                if (8 * TOP_INF / md <= (md + 1)) {
                    flag = false;
                } else {
                    if (md * (md + 1) > 2 * diff) flag = false;
                }
                if (flag)
                    l = md + 1;
                else
                    r = md;
            }
            b -= l * (l - 1) / 2;
            start = l;
            bool isSwap = false;
            if (a == b) isSwap = true;

            l = 1, r = INF;
            for (int cs = 0; cs < 62; cs++) {
                md = (l + r) >> 1;
                bool flag = true;
                if (8 * TOP_INF / md <= (start + md - 1)) {
                    flag = false;
                } else {
                    if (md * (start + md - 1) > b) flag = false;
                }
                if (flag)
                    l = md + 1;
                else
                    r = md;
            }
            int ansb = l - 1;

            l = 1, r = INF;
            for (int cs = 0; cs < 62; cs++) {
                md = (l + r) >> 1;
                bool flag = true;
                if (8 * TOP_INF / md <= (start + md)) {
                    flag = false;
                } else {
                    if (md * (start + md) > a) flag = false;
                }
                if (flag)
                    l = md + 1;
                else
                    r = md;
            }
            int ansa = l - 1;
            if (ansa == ansb) {
                if (isSwap)
                    cout << 2 * ansa + start - 1 << " " << b - ansb * (start + ansb - 1) << " " << a - ansa * (start + ansa) << endl;
                else
                    cout << 2 * ansa + start - 1 << " " << a - ansa * (start + ansa) << " " << b - ansb * (start + ansb - 1) << endl;
            } else if (ansa < ansb) {
                if (isSwap)
                    cout << 2 * ansa + start << " " << b - ansb * (start + ansb - 1) << " " << a - ansa * (start + ansa) << endl;
                else
                    cout << 2 * ansa + start << " " << a - ansa * (start + ansa) << " " << b - ansb * (start + ansb - 1) << endl;
            }
        }
    }
    return 0;
}