#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define mp make_pair

typedef long long int64;

const int N = 1e5 + 9;

struct state {
    int pos;
    int time;
    int cnt;
};

int n, g, m;
int cnt[2][N];
int ord[N], pos[N];
map<int, pair<int, int>> cand;
int dis[2][N], cho[2][N];
map<pair<int, int>, int> ans;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ":";
        cin >> n >> g >> m;

        memset(cnt, 0, sizeof cnt);
        memset(dis, 0x3f, sizeof dis);
        memset(cho, -1, sizeof cho);
        cand.clear();

        for (int i = 0; i < g; i++) {
            string order;
            cin >> pos[i] >> order;
            if (order == "A") {
                ord[i] = 0;
                pos[i] = (pos[i] - 1 - m) % n;
                while(pos[i] < 0) pos[i] = (pos[i] + n) % n;
            }
            else ord[i] = 1, pos[i] = (pos[i] - 1 + m + n) % n;
            cand[i] = mp(ord[i], pos[i]);
            cnt[ord[i]][pos[i]]++;
        }

        for (int dir = 0; dir < 2; dir++) {
            vector<int> v;
            for (int i = 0; i < g; i++) {
                if (dir == ord[i]) v.push_back(pos[i]);
            }
            if ((int)v.size() == 0) continue;
            sort(v.begin(), v.end());
            unique(v.begin(), v.end());
            for (int i = 0; i < n; i++) {
                int res = -1;
                if (dir == 0) {
                    res = upper_bound(v.begin(), v.end(), i) - v.begin() - 1;
                    if (res == -1) {
                        dis[dir][i] = abs(n + i - v[(int)v.size() - 1]);
                        cho[dir][i] = v[(int)v.size() - 1];
                    }
                    else {
                        dis[dir][i] = abs(v[res] - i);
                        cho[dir][i] = v[res];
                    }
                }
                else {
                    res = lower_bound(v.begin(), v.end(), i) - v.begin();
                    if (res == (int)v.size()) {
                        dis[dir][i] = abs(n + v[0] - i);
                        cho[dir][i] = v[0];
                    } 
                    else {
                        dis[dir][i] = abs(v[res] - i);
                        cho[dir][i] = v[res];
                    }
                }
            }
        }
        ans.clear();
        for (int i = 0; i < n; i++) {
            // cout << i << endl;
            // cout << dis[0][i] << " - " << cho[0][i] << " " << pos[i] << endl;
            // cout << dis[1][i] << " - " << cho[1][i] << " " << pos[i] << endl;

            if (dis[0][i] == dis[1][i] && dis[0][i] <= m) {
                ans[mp(0, cho[0][i])]++;
                ans[mp(1, cho[1][i])]++;
            } else {
                if (min(dis[0][i], dis[1][i]) > m) continue;
                if (dis[0][i] < dis[1][i]) ans[mp(0, cho[0][i])]++;
                else ans[mp(1, cho[1][i])]++;
            }
        }
        for (int i = 0; i < g; i++) {
            cout << " " << ans[cand[i]];
        }
        cout << endl;
    }
    return 0;
}

/*



4
5 3 2
5 C
2 A
1 A

1

*/