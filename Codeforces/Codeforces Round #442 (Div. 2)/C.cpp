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
int n;
vector<int> v;

void solve(int base, int n) {
    if (n == 0)return;
    if (n == 1) {
        v.pb(base + 1);
        return;
    }
    /*if(n == 2) {
        v.pb(base + 1);
        v.pb(base + 2);
        v.pb(base + 1);
    }*/
    if (n & 1) {
        v.pb(base + n / 2 + 1);
        solve(base + 0, n / 2);
        solve(base + n / 2 + 1, n / 2);
        v.pb(base + n / 2 + 1);
    } else {
        v.pb(base + n / 2);
        solve(base + 0, n / 2 - 1);
        solve(base + n / 2, n / 2);
        v.pb(base + n / 2);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cout << n + n / 2 <<endl;
    for(int i = 2; i <= n; i += 2){
        cout << i << " ";
    }
    for(int i = 1; i <= n; i += 2){
        cout << i << " ";
    }
    for(int i = 2; i <= n; i += 2){
        cout << i << " ";
    }
    /*if (u == 2) {
        cout << 3 << endl << "2 1 2" << endl;
        return 0;
    }*/
    /*solve(0, u);
    cout << v.size() << endl;
    for(int i=1;i<=50;i++){
            v.clear();
        cout <<i <<": ";
        solve(0, i);
        cout << v.size()<<endl;
    }
    for (int x : v)cout << x << " ";
    cout << endl;*/
    return 0;
}


