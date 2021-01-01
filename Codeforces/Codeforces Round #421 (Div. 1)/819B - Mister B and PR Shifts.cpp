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

const int N = 1e6 + 10;

int n, p[N], zero[N], pos[N], neg[N];

void update(int *s, int l, int r) {
    if (l > r) return ;
    s[r + 1]++, s[l]--;
}

int main() {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
        ans += abs(p[i] - i);
        int v = p[i] - i;
        if (v < 0) {
            update(neg, 0, n - i);
            zero[n + v + 1]++;
            update(pos, n - i + 1, n + v - 1);
            update(neg, n + v + 1, n - 1);
        } else {
            update(pos, 0, v - 1);
            update(neg, v + 1, n - i);
            zero[v + 1]++;
            update(pos, n - i + 1, n - 1);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        pos[i] += pos[i + 1];
        neg[i] += neg[i + 1];
    }
    int k = 0;
    long long cur = ans;
    for (int i = 1; i < n; i++) {
        cur += zero[i];
        cur += neg[i] - pos[i];
        cur--;
        cur -= abs(p[n - i + 1] - n);
        cur += abs(p[n - i + 1] - 1);
        if (cur < ans) {
            ans = cur;
            k = i;
        }
    }
    printf("%I64d %d\n", ans, k);
    return 0;
}

/*

3
2 3 1


*/

