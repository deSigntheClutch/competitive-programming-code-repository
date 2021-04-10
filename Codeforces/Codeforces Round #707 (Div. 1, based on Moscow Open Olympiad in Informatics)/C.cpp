#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int T;
int n, k;
int a[3] = {1, 3, 2};
int b[8] = {1, 6, 4, 3, 5, 7, 2 ,8};

signed main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 48; i++) {
        if (a[i % 3] == b[i % 8]) {
            cout << i << " " << a[i % 3] << endl;
        }
    }
}