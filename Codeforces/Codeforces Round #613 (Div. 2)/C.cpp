//  g++ -std=c++14 C.cpp -o c && ./c
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
typedef long long ll;

ll x, X;
bool isp[N];
vector<ll> prime;
vector<pair<ll, int>> cnt;

int main() {
    ios::sync_with_stdio(false);
    for (ll i = 2; i < N; i++) {
        if (isp[i]) continue;
        prime.push_back(i);
        for (ll j = 2 * i; j < N; j += i) {
            isp[j] = true;
        }
    }

    cin >> X;
    x = X;
    for (int i = 0; prime[i] * prime[i] <= x; i++) {
        if (x % prime[i] == 0) {
            pair<ll, int> pp;
            pp.second = 0;
            pp.first = prime[i];
            while (x % prime[i] == 0) {
                x /= prime[i];
                pp.second += 1;
            }
            cnt.push_back(pp);
        }
    }  
    ll ans = 1e18;
    ll t1 = -1, t2 = -1;
    for (int i = 0; i < (1 << (cnt.size())); i++) {
        ll res = 1;
        for (int j = 0; j < cnt.size(); j++) {
            if (i >> j & 1) {
                for (int l = 0; l < cnt[j].second; l++) {
                    res *= cnt[j].first;
                }
            }
        }
        if (ans > max(res, X / res)) {
            ans = max(res, X / res);
            t1 = res, t2 = X/res;
        }
    }
    cout << t1 << " " << t2 <<endl;
    return 0;
}