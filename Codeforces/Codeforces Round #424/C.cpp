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

const int N = 2e3 + 10;
const int INF = 1e9 + 10;

int n, k;
int a[N], b[N];
int sum[N];
set<int> ans;

void Val() {
    int res = -INF;
    for (int i = 1; i <= k; i++) {
        vector<int> v;
        for (int j = 1; j < i; j++) {
            v.push_back(b[1] - (sum[i] - sum[j]));
        }
        v.push_back(b[1]);
        for (int j = i + 1; j <= k; j++) {
            v.push_back(b[1] + (sum[j] - sum[i]));
        }
        bool flag = true;
        map<int, int> app;
        for(int j = 1; j <= n; j++) {
            app[b[j]]++;
        }
        for (int j = 1; j <= k; j++) {
            app[v[j - 1]]--;
        }
         for(int j = 1; j <= n; j++) {
            if(app[b[j]] > 0) flag = false;
        }
        if (flag) ans.insert(v[0] - a[1]);
    }
}

int main() {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= k; i++) {
        scanf("%d", a + i);
        sum[i] = a[i] + sum[i - 1];
    }
    for (int j = 1; j <= n; j++) {
        scanf("%d", b + j);
    }
    Val();
    printf("%d\n", (int)ans.size());
    return 0;
}

