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

int x, y;

bool check(int x, int y) {
    int a1 = x / 10, a2 = x % 10;
    int b1 = y / 10, b2 = y % 10;
    return a1 == b2 && a2 == b1;
}

int main() {
    scanf("%d:%d", &x, &y);
    int cnt = 0;
    while(true) {
        if(check(x, y)) {
            printf("%d\n", cnt);
            return 0;
        } else {
            cnt++;
            if(y == 59) y = 0, x++;
            else y++;
            if(x == 24) x = 0;
        }
    }
    return 0;
}

