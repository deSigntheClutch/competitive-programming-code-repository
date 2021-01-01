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

bool has;
int good[N];
char str[N], t[N], tmp[N];
int n, len;

bool check() {
    int l = strlen(t);
    int length_of_star = max(0, l - len + 1);
    int pt = 0;
    if(!has && len != l) return false;
    if(has && l + 1 < len) return false;
    bool flag = true;
    for (int i = 1; i <= len; i++) {
        if (str[i] == '*') {
            while (length_of_star--) {
                if (good[t[pt]]) flag = false;
                pt++;
            }
        } else {
            if (str[i] == '?') {
                if (!good[t[pt]]) flag = false;
            } else {
                if (str[i] != t[pt]) flag = false;
            }
            pt++;
        }
    }
    return flag;
}

int main() {
    scanf("%s", tmp);
    scanf("%s", str + 1);
    len = strlen(tmp);
    for (int i = 0; i < len; i++) {
        good[tmp[i]] = 1;
    }
    len = strlen(str + 1);
    for (int i = 1; i <= len; i++) {
        if (str[i] == '*') has = true;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", t);
        bool flag = check();
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
