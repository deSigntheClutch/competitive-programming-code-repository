#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int pa[N];
int last[N];
int to[N];

int find(int x) {
    if (pa[x] != x) return pa[x] = find(pa[x]);
    return pa[x];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pa[i] = i;
        to[i] = -1;
        last[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        int x = find(a);
        int y = find(b);
        if (x > y) {
            pa[x] = y;
            to[last[y]] = x;
            last[y] = last[x];
        } else {
            pa[y] = x;
            to[last[x]] = y;
            last[x] = last[y];
        }
        // cout << "-------" << endl;
        // for (int j = 1; j <= n; j++) {
        //     cout << pa[j] << " " << to[j] << endl;
        // }
    }
    int cur = 1;
    cout << 1;
    while (cur != -1) {
        cur = to[cur];
        if (cur == -1) break;
        cout << " " << cur; 
    }
    cout << endl;
    return 0;
}