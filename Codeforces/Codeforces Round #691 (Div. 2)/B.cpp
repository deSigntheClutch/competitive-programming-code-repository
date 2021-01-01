#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define int long long

using namespace std;

const int N = 3300 + 5;
const int B = 1455 + 5;

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool used[N][N][4];
bool cnt[N][N];

struct S {
    int x, y;
    int len;
    int prev;
};

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int a = n / 2, b = n - n / 2;
    if (n & 1) cout << (a + 1) * (b + 1) * 2 << endl;
    else cout << (a + 1) * (a + 1) << endl;
    return 0;
}