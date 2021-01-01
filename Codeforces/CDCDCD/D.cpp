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
#define fls fflush(stdout)

int pointer1 = 0, pointer2 = 0;

void query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    fls;
}

void answer(int a) {
    cout << "!" << " " << a << endl;
    fls;
}

int main() {
    string in;
    while (cin >> in) {
        if (in[0] == 'e') return 0;
        int l = 1, r = 1e9 + 1;
        


    }
    return 0;
}

