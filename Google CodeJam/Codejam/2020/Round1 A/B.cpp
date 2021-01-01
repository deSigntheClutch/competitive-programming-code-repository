#include <bits/stdc++.h>
using namespace std;

int T;
int n;

void down(int& x, int &y) {
    if (x == y) {
        x += 1;
        y += 1;
    } else {
        x += 1;
    }
}

void print(int x, int y) {
    cout << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": " << endl;
        cin >> n;
        int x = 1, y = 1;
        if (n < 400) {
            print(x, y);
            for (int i = 0; i < n - 1; i++) {
                down(x, y);
                print(x, y);
            }
            continue;
        }
        int offset = 40;
        int tmp = n - 40;
        if (tmp % 2 == 0) {
            tmp += 1;
            offset -= 1;
        }
        print(x, y);
        int cnt = 1;
        int biggest = -1;
        for (int i = 1; i < 30; i++) {
            if (tmp >> i & 1) {
                biggest = i + 1;
                cnt += 1;
                if (x < i + 1) {
                    //cout << i + 1 << " - " << x << " " << (i + 1) - x << endl;
                    int diff = (i + 1) - x;
                    for (int j = 0; j < diff; j++) {
                        down(x, y);
                        print(x, y);
                    }
                }
                if (x == y) {
                    for (int yy = x - 1; yy >= 1; yy--) {
                        print(x, yy);
                    }
                    y = 1;
                } else {
                    for (int yy = 2; yy <= x; yy++) {
                        print(x, yy);
                    }
                    y = x;
                }
            }
        }
        int more = biggest - cnt;
        // cout << more << endl;
        for (int i = 1; i <= offset - more; i++) {
            down(x, y);
            print(x, y);
        }
    }
    return 0;
}