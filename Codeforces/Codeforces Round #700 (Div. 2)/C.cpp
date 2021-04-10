#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

void ask(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
}

void read(int x) { cin >> a[x]; }

void answer(int x) {
    cout << "! " << x << endl;
    fflush(stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a[n + 1] = 99999999;
    a[0] = 99999999;
    int l = 1, r = n, md;
    for (int i = 0; i < 23; i++) {
        md = (l + r >> 1);
        ask(md), read(md);
        if (md - 1 >= 1 && a[md - 1] == 0) {
            ask(md - 1), read(md - 1);
        }
        if (md + 1 <= n && a[md + 1] == 0) {
            ask(md + 1), read(md + 1);
        }
        if (a[md] < a[md - 1] && a[md] < a[md + 1]) {
            //cout << a[md - 1] << " " << a[md] << " " << a[md + 1] << endl;
            answer(md);
            return 0;
        } else if (a[md] > a[md - 1]) {
            r = md;
        } else {
            l = md;
        }
    }
    if (l == r - 1) answer(r);
}