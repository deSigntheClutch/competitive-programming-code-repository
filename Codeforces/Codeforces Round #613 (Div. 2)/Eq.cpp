//  g++ -std=c++14 E.cpp -o e && ./e
#include <bits/stdc++.h>
using namespace std;

#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right

const int N = 2e5 + 2;
const int INF = 1e9 + 10;

pair<int, int> intv[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> val;
        for (int i = 1; i <= n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            intv[i] = {t1, t2};
            val.push_back(t1), val.push_back(t2);
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        vector<pair<int, int>> event;
        for (int i = 1; i <= n; i++) {
            intv[i].first = lower_bound(val.begin(), val.end(), intv[i].first) - val.begin() + 1;
            intv[i].second = lower_bound(val.begin(), val.end(), intv[i].second) - val.begin() + 1;
            event.push_back({intv[i].first, -i});
            event.push_back({intv[i].second, i});
        }
        m = val.size();
        sort(event.begin(), event.end());
        set<int> s;
        int pre = -1, id = -1;
        bool is_connected = false;
        int total_ans = 0;

    }
    return 0;
}

/*

10000
4
2 4
3 7
4 5
1 6

3
4
1 4
2 3
3 6
5 7
3
5 5
5 5
5 5
6
3 3
1 1
5 5
1 5
2 2
4 4

*/