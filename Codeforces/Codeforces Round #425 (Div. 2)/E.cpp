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

const int N = 5e2 + 10;

int n, m;
int a[N][N];
char s[N][N];
bool isn[1234567];
int prime[7] = {2,3,5,7,11};

int main() {
    ios::sync_with_stdio(false);
    cin >> n ;
    int ans = 0;
    for(int i = 1; i < (1 << 5); i++) {
        int cnt = __builtin_popcount(i);
        int val = 1;
        for(int j = 0; j < 5; j++) {
            if(i >> j & 1) val *= prime[j];
        }
        if(cnt & 1) ans += n / val;
        else ans -= n / val;
    }
    int u = 0;
    for(int i = 2; i < 1000000; i++) {
        if(!((i % 2) || (i % 3) || (i % 5))) u++;
    }
    cout << u <<endl;
    return 0;
}

