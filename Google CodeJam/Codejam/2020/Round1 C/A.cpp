#include <bits/stdc++.h>
using namespace std;

int X, Y;
string rte;

pair<int, int> pos[1234];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";
        cin >> X >> Y >> rte;
        int st_x = X, st_y = Y;
        int cnt = 0;
        pos[cnt++] = {st_x, st_y};
        for (char c : rte) {
            if (c == 'S') {
                st_y -= 1;
            }
            else if(c == 'N') {
                st_y += 1;
            } else if (c == 'W') {
                st_x -= 1;
            } else {
                st_x += 1;
            }
            pos[cnt++] = {st_x, st_y};
        }
        bool find_ = false;
        for (int i = 0; i < cnt; i++) {
            int used_time = abs(pos[i].first) + abs(pos[i].second);
            if (used_time <= i) {
                cout << i << endl;
                find_ = true;
                break;
            }
        }
        if (!find_) cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}