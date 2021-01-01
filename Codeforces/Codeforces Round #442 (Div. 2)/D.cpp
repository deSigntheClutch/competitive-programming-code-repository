#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) {
    if (y < x) x = y;
}
template<typename T, typename U> static void rmax(T &x, U y) {
    if (x < y) x = y;
}

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;

const int N = 1e3 + 10;
int n, m, k;
int vis[N][N], d[N][N];
char s[N][N];
int x1, y2, x2, y1;
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    queue<pii> q;
    q.push(mp(x1, y1));
    vis[x1][y1] = 1;
    memset(d, -1, sizeof d);
    d[x1][y1] = 0;
    while (!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        bool flag = false;
        if(x == 3 && y == 2) flag = true;
        else flag = false;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (ty >= 1 && ty <= m && tx >= 1 && tx <= n && s[tx][ty] != '#') {
                for (int j = 0; j < k; j++, tx += dx[i], ty += dy[i]) {

                    if (s[tx][ty] == '#' || ty < 1 || ty > m || tx < 1 || tx > n) break;
                    if (vis[tx][ty] == 1) continue;
                    /*if(flag == true) {
                        cout << tx << " " << ty << endl;
                    }*/
                    vis[tx][ty] = 1;
                    d[tx][ty] = d[x][y] + 1;
                    q.push(mp(tx, ty));
                }
            }
        }
    }
    /*for(int i = 1; i <= n; i++){
        for(int j=1;j<=m;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }*/
    printf("%d\n", d[x2][y2]);
    return 0;
}
/*

5 5 3
..#..
.....
.....
.....
.....
3 3 1 2

*/

