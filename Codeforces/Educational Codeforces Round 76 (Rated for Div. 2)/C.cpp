#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n;
int a[N];
vector<int> app[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        bool flag = false;
        for (int i = 0; i < N; i++) {
            app[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            app[a[i]].push_back(i);
            if (app[a[i]].size() > 1) {
                flag = true;
            }
        }    

        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        int min_v = N + 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < app[i].size(); j++) {
                if (j + 1 >= app[i].size()) continue;
                min_v = min(app[i][j + 1] - app[i][j] + 1, min_v);
            }
        }
        cout << min_v << endl;
    }
    return 0;
}