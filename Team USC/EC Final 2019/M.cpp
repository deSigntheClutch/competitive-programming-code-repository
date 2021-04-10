#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int a[N], b[N];
bool used[N];
int n;

int cal(vector<int> v) {
    sort(v.begin(), v.end(), greater<int>());
    int res = 0;
    for (int msk = 0; msk < (1 << v.size()); msk++) {
        unordered_map<int, bool> checked;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (msk >> i & 1) {
                cnt += a[v[i]];
                checked[v[i]] = true;
                for (int j = v[i] * v[i]; j <= n; j *= v[i]) {
                    if (checked[j] == true) {
                        cnt -= b[j];
                    }
                }
            }
        }
        res = max(res, cnt);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int score = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    score = a[1];
    for (int i = 2; i <= n; i++) {
        if (used[i]) continue;
        vector<int> v;
        for (int j = i; j <= n; j *= i) {
            used[j] = true;
            v.push_back(j);
        }
        score += cal(v);
    }
    cout << score << endl;
    return 0;
}