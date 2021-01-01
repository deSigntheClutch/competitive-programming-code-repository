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

const int N = 1 + 10;

string ord;

int pointer1 = 0, pointer2 = 0;

int main() {
    cin >> ord;
    for (char c : ord) {
        if (c == '0') {
            cout << 1 << " " << pointer1 + 1 << endl;
            pointer1 += 1;
            if (pointer1 == 4) pointer1 = 0;
        } else {
            cout << 4 << " " << pointer2 + 1 << endl;
            pointer2 += 2;
            if (pointer2 == 4) pointer2 = 0;
        }
    }
    return 0;
}

