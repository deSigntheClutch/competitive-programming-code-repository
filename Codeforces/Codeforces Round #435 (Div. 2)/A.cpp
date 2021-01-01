#include <bits/stdc++.h>
using namespace std;

int n, x;
int vis[123456];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vis[t] = 1;
    }
    int cnt = 0;
    for (int i = 0; i <= x; i++) {
        cnt += vis[i];
    }
    int flag = 0;
    if(vis[x] == 1) flag = -1;
    else flag = 1;
    cout << x + 1 - cnt - flag << endl;
    return 0;
}
