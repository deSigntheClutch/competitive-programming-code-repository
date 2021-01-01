#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1  1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int N = 1e5 + 10;

int el[N], st[N];

int n, m, a, b, v, q;

int query(int x, int y, int u, int w) {
    if (x > u) {
        swap(x, u);
        swap(y, w);
    } 
    if (y == w) return (u - x);
    int ans = 1e9;
    int choice;
    if (b > 0) {
        // ele <    
        choice = lower_bound(el, el + b, x) - el;
        if (choice > 0) ans = min(ans, (abs(y - w) + v - 1) / v + x + u - 2 * el[choice - 1]);
        // ele | 
        choice = lower_bound(el, el + b, x) - el;
        if (choice < b && el[choice] < u) ans = min(ans, (abs(y - w) + v - 1) / v + u - x);

        // ele >
        choice = lower_bound(el, el + b, u) - el;
        if (choice < b) ans = min(ans, (abs(y - w) + v - 1) / v + 2 * el[choice] - u - x);
    }
    if (a > 0) { 
        // str <
        choice = lower_bound(st, st + a, x) - st;
        if (choice > 0) ans = min(ans, abs(y - w) + x + u - 2 * st[choice - 1]);
        // str >
        choice = lower_bound(st, st + a, u) - st;
        if (choice < a) ans = min(ans, abs(y - w) + 2 * st[choice] - u - x);
        // str |
        choice = lower_bound(st, st + a, x) - st;
        if (choice < a && st[choice] < u) ans = min(ans, abs(y - w) + u - x);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> a >> b >> v;
    for (int i = 0; i < a; i++) {
        cin >> st[i];
    }
    for (int i = 0; i < b; i++)  {
        cin >> el[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(y1, x1, y2, x2) << endl;
    }
    return 0;
}

