//  g++ -std=c++14 C.cpp -o c && ./c
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long ll;

int to[N * 33][2];
int total;
int n;
ll a[N];

void isrt(ll x) {
    int root = 1;
    for (int i = 30; i >= 0; i--) {
        if (x >> i & 1) {
            if (to[root][1] == 0) {
                to[root][1] = ++total;
                root = total;
            } else {
                root = to[root][1];
            }
        } else {
            if (to[root][0] == 0) {
                to[root][0] = ++total;
                root = total;
            } else {
                root = to[root][0];
            }
        }
    }
}

ll dfs(int x, int pos) {
    if (pos < 0) return 0;
    int left = to[x][0];
    int right = to[x][1];
    if (left == 0) return dfs(right, pos - 1);
    if (right == 0) return dfs(left, pos - 1);
    return (1ll << pos) + min(dfs(left, pos - 1), dfs(right, pos - 1));
}

int main() {
    ios::sync_with_stdio(false);
    total = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        isrt(a[i]);
    }
    cout << dfs(1, 30) << endl;
    return 0;
}