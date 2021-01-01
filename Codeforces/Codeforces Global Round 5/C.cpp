#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

const int N = 500000 + 5;

struct point {
    int x, y, z;
    int id;
    bool operator<(struct point p) const {
        if (x == p.x && y == p.y) return z < p.z;
        else if (x == p.x) return y < p.y;
        else return x < p.x;
    }
};

int n;
point p[N], q[N], r[N];
bool used[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i].x >> r[i].y >> r[i].z;
        r[i].id = i;
    }
    sort(r, r + n);
    for (int i = 0; i + 1 < n; i++) {
        if (!used[r[i].id] && !used[r[i + 1].id] && r[i].x == r[i + 1].x && r[i].y == r[i + 1].y) {
            cout << r[i].id + 1 << " " << r[i + 1].id + 1 << endl;
            used[r[i].id] = true;
            used[r[i + 1].id] = true;
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (!used[r[i].id]) {
            p[m++] = r[i];
        }
    }
    for (int i = 0; i + 1 < m; i++) {
        if (!used[p[i].id] && !used[p[i + 1].id] && p[i].x == p[i + 1].x) {
            used[p[i].id] = true;
            used[p[i + 1].id] = true;
            cout << p[i].id + 1 << " " << p[i + 1].id + 1 << endl;
        }
    }
    int len = 0;
    for (int i = 0; i < m; i++)
        if (!used[p[i].id])
            q[len++] = p[i];

    for (int i = 0; i < len; i += 2) {
        cout << q[i].id + 1 << " " << q[i + 1].id + 1 << endl;
    }
    return 0;
}