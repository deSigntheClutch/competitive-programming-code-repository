#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
const int MOD = 1e9 + 7;

int n, m;
int a[N];

int dfs(int pos, vector<pair<int, int>> candidates) {
    if (pos == -1 || candidates.size() == 0) return 0;
    vector<pair<int, int>> ones, nil;
    for (auto x : candidates) {
        if (x.first >> pos & 1) {
            ones.push_back(x);
        } else {
            nil.push_back(x);
        }
    }
    return (2 * dfs(pos - 1, candidates) % MOD + (long long) dfs(pos - 1, ones) * dfs(pos - 1, nil) % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> n;
    vector<pair<int, int>> candidates;
    for (int i = 0; i < (1 << m); i++) {
        cin >> a[i];
        candidates.push_back({i, a[i]});
    }
    cout << dfs(m - 1, candidates) << endl;
    return 0;
}

/*

3 6
1
1
2
2
3
4
5
6

*/