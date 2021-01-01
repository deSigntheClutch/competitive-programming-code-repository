#include <bits/stdc++.h>
using namespace std;

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

const double eps = 1e-9;
const double pi = acos(-1.0);

const int N = 1e5 + 10;

int main() {
    long long x, y;
    cin >> x >> y;
    long long n = x / y, md = x % y;
    if(n&1) cout << "YES";
    else cout << "NO";
    return 0;
}
