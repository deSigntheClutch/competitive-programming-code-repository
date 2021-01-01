#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

int x[N], y[N];
int n, m;
int row[N], col[N];
bool used[N];
int fa[N], cnt[N];
bool checked[N];
set<int> ss[N];

int find(int x) {
    if (fa[x] != x)
        return fa[x] = find(fa[x]);
    else
        return fa[x];
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            fa[i] = i;
            cnt[i] = 1;
            checked[i] = false;
            ss[i].clear();
        }
        memset(used, 0, sizeof used);
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);

        int res = 0;
        for (int i = 1; i <= m; i++) {
            cin >> x[i] >> y[i];
            row[x[i]] = i;
            col[y[i]] = i;
            if (x[i] == y[i]) {
                used[x[i]] = true;
                checked[i] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            if (row[i] && col[i]) {
                int xx = find(row[i]);
                int yy = find(col[i]);
                //cout << xx << " " << yy << endl;
                if (xx != yy) {
                    //cout << xx << " " << yy << endl;
                    cnt[yy] += cnt[xx];
                    fa[xx] = yy;
                    //cout << cnt[xx] << cnt[yy] << endl;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            int xx = find(i);
            if (checked[xx]) continue;
            ss[xx].insert(x[i]);
            ss[xx].insert(y[i]);
        }
        for (int i = 1; i <= m; i++) {
            int xx = find(i);
            if (checked[xx]) continue;
            //cout << cnt[xx] << endl;
            int val = (ss[xx].size() > cnt[xx]) ? cnt[xx] : cnt[xx] + 1;
            res += val;
            checked[xx] = true;
        }
        cout << res << endl;
        //cout << endl;
    }
    return 0;
}