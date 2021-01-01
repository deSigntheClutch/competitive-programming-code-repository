#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1 << 22;

bool inp[N];
vector<int> prime;
int C;

int ppow(int a, int b, int mod) {
    int ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

bool Miller_Rabin(int p) {
    srand(time(0));
    if (p == 1) return false;
    int t = p - 1, c = 0;
    while (t % 2 == 0) t /= 2, c++;
    for (int i = 0; i < 10; i++) {
        int rd = rand() % p + rand();
        int a = ppow(rd, t, p), last = a;
        for (int j = 1; j <= c; j++) {
            last = a * a % p;
            if (last == 1 && a != 1 && a != p - 1) return false;
            a = last;
        }
        if (a != 1) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> C;
    for (int i = 2; i < N; i++) {
        if (!inp[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                inp[j] = true;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < prime.size(); i++) {
        int cnt = 0;
        while (C % prime[i] == 0) {
            C /= prime[i];
            cnt += 1;
        }
        if (cnt & 1) ans *= prime[i];
    }
    if (Miller_Rabin(C) == true)
        ans *= C;
    else {
        if (C > 100000000000) {
            int test = (int)sqrt(C + 0.5);
            if ((C % test == 0 && (C / test == test)) ||
                (C % (test + 1) == 0 && (C / (test + 1) == test + 1)) ||
                (C % (test - 1) == 0 && (C / (test - 1) == test - 1))) {
                ans = ans;
            } else {
                ans *= C;
            }
        }
    }
    cout << ans << endl;
    return 0;
}