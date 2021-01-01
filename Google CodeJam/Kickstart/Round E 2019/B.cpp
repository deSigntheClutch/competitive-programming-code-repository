#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first

typedef long long int64;

const int N = 1e5 + 9;

struct P {
    int x;
    int y;
    bool operator < (struct P p) const {
        return x * p.y < p.x * y;
    }
};

P p[N];
int D, S;
int X[N], Y[N];

char solve(int v, int c) {
    int l = 1, r = S, md;
    for (int x = 0; x < 23; x++) {
        md = (l + r) >> 1;
        if (Y[md] < c) l = md + 1;
        else r = md;
    }
    if (min(1.0 * p[md].x, 1.0 * (Y[md] - c) / p[md].y * p[md].x) + (X[S] - X[md]) >= v) return 'Y';
    else return 'N';
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": ";
        cin >> D >> S;
        for (int i = 1; i <= S; i++) {
            cin >> p[i].x >> p[i].y;
        }
        sort(p + 1, p + 1 + S);
        for (int i = 1; i <= S; i++) {
            X[i] = X[i - 1] + p[i].x;
            Y[i] = Y[i - 1] + p[i].y;
        }
        for (int i = 1; i <= D; i++) {
            int a, b;
            cin >> a >> b;
            cout << solve(a, b);
        }
        cout << endl;
    }
    return 0;
}
