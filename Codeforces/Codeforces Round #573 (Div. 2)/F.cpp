#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct Point {
    int x, y;
    bool operator < (struct Point p) const {
        if (y == p.y) return x < p.x;
        return y > p.y;
    }
};

Point p[N];
vector<int> tmpx, tmpy;
int fwt[N];
int n;

void add(int x) {
    while (x < N) {
        fwt[x] += 1;
        x += x & -x;
    }
}

int get(int x) {
    int res = 0;
    while (x) {
        res += fwt[x];
        x -= x & -x;
    }
    return res;
}

long long comb(int x) {
    return (long long) x * (x - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        tmpx.push_back(a), tmpy.push_back(b);
        p[i].x = a, p[i].y = b;
    }
    // compress x&y into 1 - n
    sort(tmpx.begin(), tmpx.end());
    sort(tmpy.begin(), tmpy.end());
    tmpx.erase(unique(tmpx.begin(), tmpx.end()), tmpx.end());
    tmpy.erase(unique(tmpy.begin(), tmpy.end()), tmpy.end());
    for (int i = 1; i <= n; i++) {
        p[i].x = lower_bound(tmpx.begin(), tmpx.end(), p[i].x) - tmpx.begin() + 1;
        p[i].y = lower_bound(tmpy.begin(), tmpy.end(), p[i].y) - tmpy.begin() + 1;
    }
    // iterate from y (big to small) then x (small to big)
    sort(p + 1, p + 1 + n);
    int ptr = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        // deal with all points which has same 'y'
        while (p[i].y == p[ptr].y && ptr <= n) {
            // record distinct x-coordinates
            if (get(p[ptr].x) - get(p[ptr].x - 1) == 0) add(p[ptr].x);
            ptr += 1;
        }
        ans += comb(get(N - 1)) + ptr - i;
        int prev = 0;
        // subtract rectangle not passing through any point at this y-level.
        for (int j = i; j < ptr; j++) {
            ans -= comb(get(p[j].x - 1) - get(prev));
            prev = p[j].x;
        }
        ans -= comb(get(N - 1) - get(prev));
        i = ptr - 1;
    }
    cout << ans << endl;
    return 0;
}