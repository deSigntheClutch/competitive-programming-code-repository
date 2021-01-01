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

const int N = 1e5 + 10;

int n, k;
int a[N];
int mod[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] % 4 == 3) {
            mod[1]++;
            mod[2]++;
        } else mod[a[i] % 4]++;
        cnt += a[i] / 4;
    }
    for (int i = 0; i <= mod[2]; i++) {
        for (int j = 0; j <= mod[1]; j++) {
            int seat2 = 2 * n, seat4 = n;
            int mod2 = mod[2], mod1 = mod[1];
            if (i + j > seat2) continue;
            seat2 -= i + j;
            mod1 -= j, mod2 -= i;
            int maxcouple = min(mod1, mod2);
            if (maxcouple <= seat4) {
                mod1 -= maxcouple;
                mod2 -= maxcouple;
                seat4 -= maxcouple;
            } else continue;
            if (mod1 == 0) {
                seat4 -= ceil(2.0 * mod2 / 3);
            } else {
                seat4 -= ceil(1.0 * mod1 / 2);
            }
            if (seat4 < 0) continue;
            if (seat2 * 2 + seat4 * 4 >= cnt * 4) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

