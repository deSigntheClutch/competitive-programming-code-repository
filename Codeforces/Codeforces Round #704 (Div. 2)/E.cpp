#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;

int T;
int n, m;
string s, t;

void show(int u) {
    while(u) {
        cout << (u&1);
        u >>= 1;
    }
    cout << endl;
}

int bit(int u) {
    int cnt =0;
    while (u) {
        cnt += 1;
        u >>= 1;
    }
    return cnt;
}

int count_num(int u, int nu) {
    int cnt = 0;
    while (u) {
        if ((u&1) == nu) cnt += 1;
        u >>= 1;
    }
    return cnt;
}

signed main() {

    for (int b = 1; b <= 8; b++) {
        int a = 8 - b;
        int mx = 0;
        bool flag = false;
        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= 1000; j++) {
                if (bit(i) == bit(j) && bit(i) == 8 && i > j && count_num(i, 1) == count_num(j, 1) && count_num(i, 1) == b) {
                    // show(i);
                    // show(j);
                    // show(i - j);
                    mx = max(count_num(i - j, 1), mx);
                    if (mx == 5 && flag == false) {

                        flag = true;
                                            show(i);
                    show(j);
                    show(i - j);
                    }
                }
            }
        }
        cout << mx << endl;
    }
}


/*

0
00000011
10000001
111111
6
01000011
11000001
111111
6
01100011
11100001
111111
6
01110011
11110001
111111
6
01111011
11111001
111111
6
01111111
11111101
111111
6
0


*/