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

const int N = 2e5 + 10;

int sum[N], cnt[N];
int n, k, q;

int main() {
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        cnt[r]++;
        cnt[l - 1]--;
    }
    for (int i = N - 2; i >= 1; i--) {
        cnt[i] += cnt[i + 1];
        if (cnt[i] >= k) sum[i]++;
    }
    for (int i = 1; i < N; i++) {
        sum[i] += sum[i - 1];
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}


