#include <bits/stdc++.h>
using namespace std;
#define int long long

const int D = 1e9 / 2;

//nwse
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int A, B;
bool flag;

int get_response() {
    string res;
    cin >> res;
    if (res[0] == 'C') flag = true;
    if (res[0] == 'H') return 1;
    else return 0;
}

pair<int, int> to_extreme(int x, int y, int dir) {
    int l = 0, r = 4 * D, mid;
    for (int i = 0; i < 34; i++) {
        mid = l + (r - l) / 2;
        int next_pos_x = min(2 * D, (int)max(x + dx[dir] * mid, -2 * D));
        int next_pos_y = min(2 * D, (int)max(y + dy[dir] * mid, -2 * D));
        cout << next_pos_x << " " << next_pos_y << endl;
        fflush(stdout);
        if (get_response() == 1) l = mid + 1;
        else r = mid;
        if (flag) return {-1, -1};
    }
    return {min(2 * D, (int)max(x + dx[dir] * (l - 1), -2 * D)), min(2 * D, (int)max(y + dy[dir] * (l - 1), -2 * D))};
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T >> A >> B;
    for (int cas = 1; cas <= T; cas++) {
        flag = false;
        int X = -4 * D, Y = -4 * D;
        for (int x = -D; x <= D && !flag; x += D) {
            for (int y = -D; y <= D && !flag; y += D) {
                cout << x << " " << y << endl;
                fflush(stdout);
                if (get_response() == 1) {
                    X = x, Y = y;
                    break;
                }
            }
            if (X != -4 * D) break;
        }
        if (flag) continue;
        pair<int, int> c = to_extreme(X, Y, 1);
        if (flag) continue;
        pair<int, int> b = to_extreme(c.first, c.second, 0);
        if (flag) continue;
        pair<int, int> a = to_extreme(c.first, c.second, 2);
        if (flag) continue;
        a = {X, (a.second + b.second) / 2};
        pair<int, int> left_border = to_extreme(a.first, a.second, 1); 
        if (flag) continue;
        pair<int, int> right_border = to_extreme(a.first, a.second, 3); 
        if (flag) continue;
        cout << (left_border.first + right_border.first) / 2 << " " << left_border.second << endl;
        fflush(stdout);
        get_response();
    }
    return 0;
}