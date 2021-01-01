#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18 + 1;
ll n, k;
bool flag;

void print(ll x) {
    if (x == 20) {
        flag = true;
    }
    while (x > 1) {
        if (x % 2 == 0) x = x / 2;
        else x = x - 1;
        if (x == 20) {
            flag = true;
        }
    }
} 

bool check1(ll x) {
    if (x == 1) return n >= k;
    ll base = 1;
    ll cnt = 0;
    while (true) {
        ll start = base * x;
        ll end = base * x - 1 + base;
        if (start > n) {
            return cnt >= k;
        }
        if (end >= n) {
            return cnt + n - start + 1 >= k;
        }
        cnt += end - start + 1;
        base = base * 2;
    }
}

bool check2(ll x) {
    if (x == 2) return n - 1 >= k;
    ll base = 1;
    ll cnt = 0;
    while (true) {
        ll start = base * x;
        ll end = base * x - 1 + 2 * base;
        if (start > n) {
            return cnt >= k;
        }
        if (end >= n) {
            //cout << end << " " << n << endl;
            //cout << n - start + 1 << " " << cnt << " " << k << endl;
            return cnt + n - start + 1 >= k;
        }
        cnt += end - start + 1;
        base = base * 2;
    }
}

void check(ll x) {
    ll base = 1;
    ll cnt = 0;
    while (true) {
        ll start = base * x;
        ll end = base * x - 1 + 2 * base;
        if (end >= n) {
            cout << cnt << endl;
            break;
        }
        cnt += end - start + 1;
        base = base * 2;
    }   
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;

    ll l = 0, r = 6e17, md;
    for (int i = 0; i < 64; i++) {
        md = (l + r) >> 1;
        if (check1(md * 2 + 1) == true) l = md + 1;
        else r = md;
    }
    ll odd = 2 * md + 1;
    l = 1, r = 6e17, md;
    for (int i = 0; i < 64; i++) {
        md = (l + r) >> 1;
        if (check2(md * 2) == true) l = md + 1;
        else r = md;
    }
    ll even = 2 * md;
    odd -= 2;
    even -= 2;
    cout << max(odd, even) << endl;
    return 0;
}