#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define mp make_pair

typedef long long int64;

const int N = 1e5 + 9;

int u[N], v[N];
int n, m;
int pa[N];

int find(int u) {
    if (pa[u] != u) return pa[u] = find(pa[u]);
    else return pa[u]; 
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": ";
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> u[i] >> v[i];
        }
        for (int i = 1; i <= n; i++) {
            pa[i] = i;
        }
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            int x = find(u[i]);
            int y = find(v[i]);
            if (x != y) {
                pa[x] = y;
                cnt++;
            } 
        }
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(find(i));
        }
        cout << cnt + 2 * ((int)s.size() - 1) << endl;
    }
    return 0;
}
