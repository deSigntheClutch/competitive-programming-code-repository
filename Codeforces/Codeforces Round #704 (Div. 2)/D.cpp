#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;

int T;
int a, b, k;
string p, q;

signed main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> k;

    for (int i = 0; i < a + b; i++) {
        p += 'x';
        q += 'x';
    }
    if (b == 1 || a == 0 || k == 0) {
        if (k == 0) {
            cout << "Yes" << endl;
            for (int i = 1; i <= b; i++) {
                cout << "1";
            }
            for (int i = 1; i <= a; i++) {
                cout << "0";
            }
            cout << endl;
            for (int i = 1; i <= b; i++) {
                cout << "1";
            }
            for (int i = 1; i <= a; i++) {
                cout << "0";
            }
            cout << endl;
        }   
        else {
            cout << "No" << endl;
        }
        return 0;
    }
    if (a + b - 2  >= k) {
        cout << "Yes" << endl;
        int mx = a + b - 2;



        int n = a + b;
        int same = mx - k;
        p[0] = '1'; p[n - 1] = '0'; p[same + 1] = '1';
        q[0] = '1'; q[n - 1] = '1'; q[same + 1] = '0';
        a -= 1, b -= 2;
        for (int i = 0;  i < n; i++) {
            if (a > 0 && p[i] == 'x') {
                p[i] = '0';
                q[i] = '0';
                a -= 1;
            } else if (b > 0 && p[i] == 'x') {
                p[i] = '1';
                q[i] = '1';
                b -= 1;
            }
        }
        cout << p << endl << q << endl;
    } else {
        cout << "No" << endl;
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