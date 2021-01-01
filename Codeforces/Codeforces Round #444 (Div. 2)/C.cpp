#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) {
    if (y < x) x = y;
}
template<typename T, typename U> static void rmax(T &x, U y) {
    if (x < y) x = y;
}

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
typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;

int cube[N];
int to[N];

bool check() {
    for (int i = 1; i < 4; i++) if (cube[0] != cube[i]) return false;
    for (int i = 5; i < 8; i++) if (cube[4] != cube[i]) return false;
    for (int i = 9; i < 12; i++) if (cube[8] != cube[i]) return false;
    for (int i = 13; i < 16; i++) if (cube[12] != cube[i]) return false;
    for (int i = 17; i < 20; i++) if (cube[16] != cube[i]) return false;
    for (int i = 21; i < 24; i++) if (cube[20] != cube[i]) return false;
    return true;
}

void rotate1() {
    for (int i = 0; i < 24; i++) {
        to[i] = cube[i];
    }
    to[4] = cube[12], to[5] = cube[13];
    to[16] = cube[4], to[17] = cube[5];
    to[20] = cube[16], to[21] = cube[17];
    to[12] = cube[20], to[13] = cube[21];
    for (int i = 0; i < 24; i++) {
        cube[i] = to[i];
    }
}

void rotate2() {
    for (int i = 0; i < 24; i++) {
        to[i] = cube[i];
    }
    to[6] = cube[14], to[7] = cube[15];
    to[18] = cube[6], to[19] = cube[7];
    to[22] = cube[18], to[23] = cube[19];
    to[14] = cube[22], to[15] = cube[23];
    for (int i = 0; i < 24; i++) {
        cube[i] = to[i];
    }
}

void rotate3() {
    for (int i = 0; i < 24; i++) {
        to[i] = cube[i];
    }
    to[4] = cube[0], to[6] = cube[2];
    to[8] = cube[4], to[10] = cube[6];
    to[23] = cube[8], to[21] = cube[10];
    to[0] = cube[23], to[2] = cube[21];
    for (int i = 0; i < 24; i++) {
        cube[i] = to[i];
    }
}

void rotate4() {
    for (int i = 0; i < 24; i++) {
        to[i] = cube[i];
    }
    to[5] = cube[1], to[7] = cube[3];
    to[9] = cube[5], to[11] = cube[7];
    to[22] = cube[9], to[20] = cube[11];
    to[1] = cube[22], to[3] = cube[20];
    for (int i = 0; i < 24; i++) {
        cube[i] = to[i];
    }
}

void rotate5() {
    for (int i = 0; i < 24; i++) {
        to[i] = cube[i];
    }
    to[17] = cube[0], to[19] = cube[1];
    to[11] = cube[17], to[10] = cube[19];
    to[14] = cube[11], to[12] = cube[10];
    to[0] = cube[14], to[1] = cube[12];
    for (int i = 0; i < 24; i++) {
        cube[i] = to[i];
    }
}
void rotate6() {
    for (int i = 0; i < 24; i++) {
        to[i] = cube[i];
    }
    to[16] = cube[2], to[18] = cube[3];
    to[9] = cube[16], to[8] = cube[18];
    to[15] = cube[9], to[13] = cube[8];
    to[2] = cube[15], to[3] = cube[13];
    for (int i = 0; i < 24; i++) {
        cube[i] = to[i];
    }
}


int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 24; i++) {
        cin >> cube[i];
    }
    for (int i = 0; i < 4; i++) {
        rotate1();
        if (i == 3 || i == 1) continue;
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        rotate2();
        if (i == 3 || i == 1) continue;
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        rotate3();
        if (i == 3 || i == 1) continue;
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        rotate4();
        if (i == 3 || i == 1) continue;
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        rotate5();
        if (i == 3 || i == 1) continue;
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        rotate6();
        if (i == 3 || i == 1) continue;
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

