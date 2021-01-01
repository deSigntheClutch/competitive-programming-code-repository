#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 9;
const int N = 1e2 + 2;

int n;
int G[N][N];
vector<int> loser[N];
int at[N], df[N], hp[N];
string name[N];

pair<int, pair<int, int>> gen(int x, int y, int z) {
    if (z < y) swap(z, y);
    if (y < x) swap(x, y);
    if (z < y) swap(y, z);
    return make_pair(x, make_pair(y, z));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> hp[i] >> at[i] >> df[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int time1, time2;
            if (at[j] <= df[i]) time1 = INF;
            else time1 = ceil(1.0 * hp[i] / (at[j] - df[i]));
            if (at[i] <= df[j]) time2 = INF;
            else time2 = ceil(1.0 * hp[j] / (at[i] - df[j]));
            if (time1 > time2) G[i][j] = 1, loser[i].push_back(j);
            else if (time1 < time2) G[j][i] = 1, loser[j].push_back(i);
        }
    }
    map<pair<int, pair<int, int>>, bool> g;
    vector<pair<int, pair<int, int>>> ans;
    for (int i = 0; i < n; i++) {
        for (int to : loser[i]) {
            for (int to2 : loser[to]) {
                if (G[to2][i] == 1) {
                    auto sb = gen(i, to, to2);
                    if (g[sb] == false) {
                        g[sb] = true;
                        ans.push_back(sb);
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << name[x.first] << " " << name[x.second.first] << " " << name[x.second.second] << endl;
    }
    return 0;
}