#include <bits/stdc++.h>
using namespace std;
#define int long long

int q;

const int N = 1e2 + 10;

vector<int> go[N];
vector<int> G[N];
bool used[N];

void dfs(int u) {
    used[u] = true;
    for (int x : G[u]) {
        if (!used[x]) {
            dfs(x);
        }
    }
}

string bi(int x) {
    string res = "";
    while (x) {
        res += (x & 1) + '0';
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool strong_compare(int x, int y) {
    vector<int> xx, yy;
    int cnt = 0;
    while (x) {
        if (x & 1) xx.push_back(cnt);
        x /= 2, cnt += 1;
    }
    cnt = 0;
    while (y) {
        if (y & 1) yy.push_back(cnt);
        y /= 2, cnt += 1;
    }
    reverse(xx.begin(), xx.end());
    reverse(yy.begin(), yy.end());

    int pt = 0;
    for (int i = 0; i < yy.size(); i++) {
        // cout << pt << ' ' << i << endl;
        // cout << xx[pt] << " " << yy[i] << endl;
        assert(xx.size() - pt >= yy.size() - i);
        if (xx[pt] > yy[i])
            return false;
        else if (xx[pt] < yy[i]) {
            while (xx.size() - pt >= yy.size() - i) pt += 1;
        } else pt += 1;
    }
    return true;
}

int compare(int x, int y) {
    vector<int> xx, yy;
    int cnt = 0;
    while (x) {
        if (x & 1) xx.push_back(cnt);
        x /= 2, cnt += 1;
    }
    cnt = 0;
    while (y) {
        if (y & 1) yy.push_back(cnt);
        y /= 2, cnt += 1;
    }
    if (xx.size() > yy.size())
        return 1;
    else if (xx.size() < yy.size())
        return -1;
    else
        return 0;
}

bool solve(int x, int y) {
    if (x > y) return false;
    if (compare(x, y) == -1) return false;
    return strong_compare(x, y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        bool yes = solve(x, y);
        cout << (yes ? "yes" : "no") << endl;
    }

    // for (int i = 1; i < N; i++) {
    //     for (int j = 1; j < N; j++) {
    //         if (i + j < N && (i & j) == j) {
    //             G[i].push_back(i + j);
    //         }
    //     }
    // }

    // for (int i = 1; i < N; i++) {
    //     memset(used, 0, sizeof used);
    //     dfs(i);
    //     for (int j = 1; j < N; j++) {

    //         if (solve(i, j) != used[j]) {
    //             cout << used[j] << " " << solve(i, j) << endl;
    //             cout << i << " " << j << endl;
    //         }
    //     }
    // }
    return 0;
}
