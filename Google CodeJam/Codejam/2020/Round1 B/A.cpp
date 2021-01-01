#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool neg_x, neg_y;
int f[35][2];

string solve1(ll x, ll y) {
    neg_x = neg_y = false;
    memset(f, 0, sizeof f);
    if (x < 0) neg_x = true, x *= -1;
    if (y < 0) neg_y = true, y *= -1;
    int max_len = -1;
    int modified_len = -1;
    for (int i = 33; i >= 0; i--) {
        if ((x >> i & 1) || (y >> i & 1)) {
            max_len = i;
            break;
        }
    }
    modified_len = max_len;
    for (int i = 0; i < 34; i++) {
        int xx = x >> i & 1;
        int yy = y >> i & 1;
        if (xx == 0 && yy == 0) {
            if (f[i - 1][0] == 1) {
                f[i - 1][0] = -1;
                f[i][0] = 1;
            } else if(f[i - 1][1] == 1) {
                f[i - 1][1] = -1;
                f[i][1] = 1;
            } else {
                break;
            }
        } else if (xx == 1 && yy == 1) {
            if (f[i - 1][0] == 1) {
                f[i - 1][0] = -1;
                f[i][1] = 1;
                f[i + 1][0] = 1;
            } else if(f[i - 1][1] == 1) {
                f[i - 1][1] = -1;
                f[i][0] = 1;
                f[i + 1][1] = 1;
            } else {
                return "IMPOSSIBLE";
            }
            i += 1;
            modified_len = max(modified_len, i);
        } else if (xx == 1) {
            f[i][0] = 1;
        } else {
            f[i][1] = 1;
        }
    }
    string ans = "";
    for (int i = 0; i <= modified_len + 1; i++) {
        cout << i << ": " << f[i][0] << " " << f[i][1] << endl;
        if ((f[i][0] == 1 && neg_x == false) || (f[i][0] == -1 && neg_x == true)) ans += "E";
        if ((f[i][0] == -1 && neg_x == false) || (f[i][0] == 1 && neg_x == true)) ans += "W";
        if ((f[i][1] == 1 && neg_y == false) || (f[i][1] == -1 && neg_y == true)) ans += "N";
        if ((f[i][1] == -1 && neg_y == false) || (f[i][1] == 1 && neg_y == true)) ans += "S";
    }
    return ans;
}

ll positive_mod(ll x, ll y) {
    return (x % y < 0) ? (y + (x % y)) : (x % y);
}

string solve2(ll x, ll y) {
    string ans = "";
    while (!(x == 0 && y == 0)) {
        if (x == 0) {
            if (y == 1) {
                ans += 'N';
                break;
            }
            else if (y == -1) {
                ans += 'S';
                break;
            }
        } else if (y == 0) {
            if (x == 1) {
                ans += 'E';
                break;
            }
            else if (x == -1) {
                ans += 'W';
                break;
            }
        }
        if ((x ^ y) & 1) {
            if (y & 1) {
                if ((positive_mod(y, 4) == 3 && positive_mod(x, 4) == 2) || (positive_mod(y, 4) == 1 && positive_mod(x, 4) == 0)) y += 1, ans += 'S';
                else y += -1, ans += 'N';
            } else {
                if ((positive_mod(x, 4) == 3 && positive_mod(y, 4) == 2) || (positive_mod(x, 4) == 1 && positive_mod(y, 4) == 0)) x += 1, ans += 'W';
                else x += -1, ans += 'E';
            }
        } else {
                return "IMPOSSIBLE";
        }
        x /= 2, y /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << solve1(7, 2);
    // for (int i = -10; i <= 10; i++) {
    //     for (int j = -10; j <= 10; j++) {
    //         if (solve1(i, j) != solve2(i, j)) {
    //             cout << i << " " << j << endl;
    //             cout << solve1(i, j) << " vs " << solve2(i, j) << endl;
    //         }
    //     }
    // }
    // int T;
    // cin >> T;
    // for (int cas = 1; cas <= T; cas++) {
    //     cout << "Case #" << cas << ": ";
    //     solve1();
    // }
    return 0;
}

/*

4 1

81
-4 -4
-4 -3
-4 -2
-4 -1
-4 0
-4 1
-4 2
-4 3
-4 4
-3 -4
-3 -3
-3 -2
-3 -1
-3 0
-3 1
-3 2
-3 3
-3 4
-2 -4
-2 -3
-2 -2
-2 -1
-2 0
-2 1
-2 2
-2 3
-2 4
-1 -4
-1 -3
-1 -2
-1 -1
-1 0
-1 1
-1 2
-1 3
-1 4
0 -4
0 -3
0 -2
0 -1
0 0
0 1
0 2
0 3
0 4
1 -4
1 -3
1 -2
1 -1
1 0
1 1
1 2
1 3
1 4
2 -4
2 -3
2 -2
2 -1
2 0
2 1
2 2
2 3
2 4
3 -4
3 -3
3 -2
3 -1
3 0
3 1
3 2
3 3
3 4
4 -4
4 -3
4 -2
4 -1
4 0
4 1
4 2
4 3
4 4

Case #1: IMPOSSIBLE
Case #2: SSW
Case #3: IMPOSSIBLE
Case #4: NSW
Case #5: IMPOSSIBLE
Case #6: SNW
Case #7: IMPOSSIBLE
Case #8: NNW
Case #9: IMPOSSIBLE
Case #10: WWS
Case #11: IMPOSSIBLE
Case #12: ESW
Case #13: IMPOSSIBLE
Case #14: WW
Case #15: IMPOSSIBLE
Case #16: ENW
Case #17: IMPOSSIBLE
Case #18: WWN
Case #19: IMPOSSIBLE
Case #20: NWS
Case #21: IMPOSSIBLE
Case #22: SW
Case #23: IMPOSSIBLE
Case #24: NW
Case #25: IMPOSSIBLE
Case #26: SWN
Case #27: IMPOSSIBLE
Case #28: EWSS
Case #29: IMPOSSIBLE
Case #30: WS
Case #31: IMPOSSIBLE
Case #32: W
Case #33: IMPOSSIBLE
Case #34: WN
Case #35: IMPOSSIBLE
Case #36: EWNN
Case #37: IMPOSSIBLE
Case #38: SS
Case #39: IMPOSSIBLE
Case #40: S
Case #41: 
Case #42: N
Case #43: IMPOSSIBLE
Case #44: NN
Case #45: IMPOSSIBLE
Case #46: WESS
Case #47: IMPOSSIBLE
Case #48: ES
Case #49: IMPOSSIBLE
Case #50: E
Case #51: IMPOSSIBLE
Case #52: EN
Case #53: IMPOSSIBLE
Case #54: WENN
Case #55: IMPOSSIBLE
Case #56: NES
Case #57: IMPOSSIBLE
Case #58: SE
Case #59: IMPOSSIBLE
Case #60: NE
Case #61: IMPOSSI4BLE
Case #62: SEN
Case #63: IMPOSSIBLE
Case #64: EES
Case #65: IMPOSSIBLE
Case #66: WSE
Case #67: IMPOSSIBLE
Case #68: EE
Case #69: IMPOSSIBLE
Case #70: WNE
Case #71: IMPOSSIBLE
Case #72: EEN
Case #73: IMPOSSIBLE
Case #74: SSE
Case #75: IMPOSSIBLE
Case #76: NSE
Case #77: IMPOSSIBLE
Case #78: SNE
Case #79: IMPOSSIBLE
Case #80: NNE
Case #81: IMPOSSIBLE

*/