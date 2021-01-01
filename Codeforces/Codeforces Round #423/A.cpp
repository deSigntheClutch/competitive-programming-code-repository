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

int n, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    int ans = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 2) {
            if (b) b--;
            else ans += 2;
        } else {
            if (a) a--;
            else if(b) b--, c++;
            else if(c) c--;
            else ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

/*

4 1 2
1 1 2 1
4 1 2
1 1 1 2

*/
