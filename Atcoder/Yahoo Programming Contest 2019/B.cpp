#include <bits/stdc++.h>
using namespace std;

const int N = 5;
vector<int> G[N];
int deg[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 3; i++) {
        int a, b;
        cin >> a >> b;
        deg[a] += 1;
        deg[b] += 1;
    }
    for (int i = 1; i <= 4; i++) {
        cnt[deg[i]] += 1;
    }
    if (cnt[1] == 2 && cnt[2] == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}