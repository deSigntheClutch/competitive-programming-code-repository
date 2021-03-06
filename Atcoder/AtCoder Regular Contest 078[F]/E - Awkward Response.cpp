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

string answer;

bool check(int x) {
    cout << "? ";
    cout << x << endl;
    fflush(stdout);
    cin >> answer;
    if (answer == "N") return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(false);
    long long x = 1;
    long long l, r;
    while (x <= (int)1e9) {
        cout << "? ";
        cout << x << endl;
        fflush(stdout);
        cin >> answer;
        if (answer == "N") {
            l = x / 10;
            r = x - 1;
            break;
        }
        x *= 10;
    }
    if (x == (int)1e10) {
        cout << "! 1000000000" << endl;
        return 0;
    } else if (l == 1) {
        for (int i = 1; i <= 9; i++) {
            cout << "? ";
            cout << x << endl;
            fflush(stdout);
            cin >> answer;
            if (answer == "N") {
            }
            return 0;
        }
        int md;
        for (int i = 0; i < 35; i++) {
            md = (l + r) >> 1;
            if (check(md)) l = md + 1;
            else r = md;
        }
        cout << "! " << md << endl;
        return 0;
    }

