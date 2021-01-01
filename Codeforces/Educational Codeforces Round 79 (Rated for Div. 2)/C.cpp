//g++ -std=c++14 C.cpp -o c && ./c
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];
bool used[N];
bool order[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        memset(used, 0, sizeof used);
        memset(order, 0, sizeof order);
        int pt = 1;
        long long cnt = 0;
        int died = 0;
        for (int i = 1; i <= m; i++) {
            int prev = pt;
            if (order[b[i]] == true) {
                cnt += 1;
                died += 1;
                continue;
            }
            for (int j = pt; j <= n; j++) {
                if (a[j] == b[i]) {
                    pt = j + 1;
                    used[b[i]] = true;
                    cnt += j - 1 - died + 1 + j - 1 - died;
                    died += 1;
                    break;
                } else {
                    order[a[j]] = true;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


/*

3
3 3
3 1 2
3 2 1
7 2
2 1 7 3 4 5 6
3 1
5 5 
1 2 3 4 5
5 4 3 2 1
*/
