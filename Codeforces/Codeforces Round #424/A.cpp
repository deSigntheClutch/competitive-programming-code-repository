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

int n;
int a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int signal = 1;
    for(int i = 1; i < n; i++) {
        int cur = 0;
        if(a[i] > a[i + 1]) cur = -1;
        else if(a[i] == a[i + 1]) cur = 0;
        else cur = 1;
        if(cur > signal) {
            printf("NO\n");
            return 0;
        }
        signal = cur;
    }
    printf("YES\n");
    return 0;
}

