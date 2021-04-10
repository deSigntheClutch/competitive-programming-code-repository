#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int T;
int n, q;
int a[N];

multiset<int> cnt[N];
set<int> dedupe_cnt[N];
int val[N];
int ans = 1;

vector<int> factor[N];
bool isn[N];

void clear(int fac) {
    for (int i = 1; i <= n; i++) {
        cnt[fac].erase(cnt[fac].find(i));
        if (cnt[fac].find(i) == cnt[fac].end()) {
            dedupe_cnt[fac].erase(dedupe_cnt[fac].find(i));
        }
    }
    val[fac] += 1;
    ans = (long long)ans * fac % MOD;
}

int main() {
    ios::sync_with_stdio(false);

    for (int i = 2; i < N; i++) {
        if (isn[i]) continue;
        factor[i].push_back(i);
        for (int j = i + i; j < N; j += i) {
            isn[j] = true;
            factor[j].push_back(i);
        }
    }

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int t = a[i];
        for (int f : factor[a[i]]) {
            while (t % f == 0) {
                t /= f;
                cnt[f].insert(i);
                if (i == n) dedupe_cnt[f].insert(i);
                if (dedupe_cnt[f].size() == n) {
                    clear(f);
                }
            }
            if (i < n) dedupe_cnt[f].insert(i);
        }
    }

    while (q--) {
        int id, x;
        cin >> id >> x;
        int t = x;
        for (int f : factor[x]) {
            while (t % f == 0) {
                t /= f;
                cnt[f].insert(id);
                dedupe_cnt[f].insert(id);
                if (dedupe_cnt[f].size() == n) {
                    clear(f);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}