#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int dp[N][N];
int n;
string AA, BB, BA, AB;

signed main() {
    ios::sync_with_stdio(false);
    srand(time(NULL));
    cout << 100 << endl;
    for (int i = 1; i <= 100; i++) {
        int a = rand() % 50 + 1, b = rand() % 50 + 1;
        cout << a << " " << b << endl;
    }
    return 0;
}