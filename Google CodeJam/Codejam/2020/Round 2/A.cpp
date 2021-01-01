#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;
bool order = false;

ll cal(ll val) {
    ll l = 0, r = 2e9 + 1;
    ll md;
    for (int j = 0; j < 34; j++) {
        md = (l + r) >> 1;
        if ((md + 1) * md / 2 <= val) {
            l = md + 1;
        } else {
            r = md;
        }
    }
    return l - 1;
}



void cal2(ll start_day, ll u, ll v) {
    ll l = 0, r = 2e9 + 1, md;
    for (int i = 0; i < 34; i++) {
        md = (l + r) >> 1;
        bool ok = true;
        if (md != 0) {
            if (md % 2 == 1) {
                if ((start_day + 1 + start_day + md) / 2 * ((md + 1) / 2) > u) ok = false;
                if ((start_day + 2 + start_day + md - 1) / 2 * (md / 2) > v) ok = false;
            } else {
                if ((start_day + 1 + start_day + md - 1) / 2 * ((md + 1) / 2) > u) ok = false;
                if ((start_day + 2 + start_day + md) / 2 * (md / 2) > v) ok = false;
            }
        }
        if (ok) l = md + 1;
        else r = md;
    }   
    int as = l - 1;
    if (as % 2 == 1) {
        u -= (start_day + 1 + start_day + as) / 2 * ((as + 1) / 2);
        v -= (start_day + 2 + start_day + as - 1) / 2 * (as / 2);
    } else {
        u -= (start_day + 1 + start_day + as - 1) / 2 * ((as + 1) / 2);
        v -= (start_day + 2 + start_day + as) / 2 * (as / 2);
    }
    if (order == false) cout << start_day + l - 1 << " " << u << " " << v << endl;
    else cout << start_day + l - 1 << " " << v << " " << u << endl;
} 

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";
        cin >> a >> b;
        order = false;
        if (a > b) {
            order = true;
            swap(a, b);
        }
        long long x = cal(b - a);
        b -= x * (x + 1) / 2;
        if (a < b && b - (x + 1) >= 0) {
            x += 1;
            b -= x;
        }
        cal2(x, a, b);
    }
    return 0;
}