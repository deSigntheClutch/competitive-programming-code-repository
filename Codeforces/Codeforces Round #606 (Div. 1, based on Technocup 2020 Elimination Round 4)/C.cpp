#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

map<int, int> ap;
int n, m;
int a[N];
int sum[N];
pair<int, int> p[N];

void print_answer(int r, int c) {
    vector<vector<int>> table(r, vector<int>(c, 0));
    vector<int> operate;
    for (int i = m; i >= 1; i--) {
        for (int j = 0; j < min(r, p[i].first); j++) {
            if (operate.size() == r * c) break;
            operate.push_back(p[i].second);
        }
    }
    int tx = 0, ty = 0;
    for (int x : operate) {
        table[tx][ty] = x;
        tx = (tx + 1) % r;
        ty = (ty + 1) % c;
        if (table[tx][ty] != 0) {
            tx = (tx + 1) % r;
        }
    }
    cout << r * c << endl << r << " " << c << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int max_apperance = 0;
    for (int i = 0; i < n; i++) cin >> a[i], ap[a[i]] += 1, max_apperance = max(max_apperance, ap[a[i]]);
    for (map<int, int>::iterator it = ap.begin(); it != ap.end(); it++) {
        p[++m] = make_pair(it->second, it->first);
    }
    sort(p + 1, p + 1 + m);
    for (int i = 1; i <= m; i++) {
        sum[i] = p[i].first + sum[i - 1];
    }
    for (int ans = n; ans >= 2; ans--) {
        for (int hei = 1; hei * hei <= ans; hei++) {
            if (ans % hei != 0) continue;
            int wid = ans / hei;
            int idx = lower_bound(p + 1, p + 1 + m, make_pair(hei, (int)1e9 + 10)) - p;
            bool check = (sum[idx - 1] + (m - idx + 1) * hei) >= ans;
            if (check) {
                print_answer(hei, wid);
                return 0;
            }
        }
    }
    cout << 1 << endl << 1 << " " << 1 << endl << a[0] << endl;
    return 0;
}