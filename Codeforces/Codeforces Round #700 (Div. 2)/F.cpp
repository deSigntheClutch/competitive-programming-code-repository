#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int origin[N];

void ask(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
}

void read(int x) {
    cin >> a[x];
}

void answer(int x) {
    cout << "! " << x << endl;
    fflush(stdout);
}

int main() {

    ios::sync_with_stdio(false);
    cin >> n;  
    a[n + 1] = 99999999;
    a[0] = 99999999;  
    ask(1);
    read(1);
    if (n == 1 || a[1] == 1) {
        answer(a[1]);
        return 0;
    }
    int l = 2, r = a[1], md;
    for (int i = 0; i < 20; i++) {
        if (r - l <= 50) {
            for (int j = l - 5; j <= r + 5; j++) {
                if (j >= 1 && j <= n && a[j] == 0){
                    ask(j);
                    read(j);
                }
            }
            for(int j = l - 3; j <= r + 3; j++) {
                if ((j >= 0 && j <= n + 1) && a[j] != 0 && a[j - 1] != 0 && a[j + 1] != 0) {
                    if (a[j] < a[j - 1] && a[j] < a[j + 1]) {
                        answer(j);
                        return 0;
                    }
                }
            }
            return 0;
        }
        if (l == r - 1) {
            ask(l);
            read(l);
            ask(r);
            read(r);
            break;
        }
        md = (l + r) >> 1;
        if (a[md] != 0) break;
        ask(md);
        read(md);
        if (a[1] - a[md] >= md - 1) {
            l = md;
        } else {
            r = md;
        }
    }
}