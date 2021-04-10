#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int BOSS = 2e6 + 10;

int T;
unordered_map<int, vector<pair<int, int>>> cnt;
int n;
pair<int, int> a[N];
int main() {
    ios::sync_with_stdio(false);
    cnt.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    int threshold = 4 * BOSS / n + 50;
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        for (int dec = 1; dec <= threshold; dec++) {
            if (i - dec == 0) break;
            if (cnt[a[i].first - a[i - dec].first].size() == 0)
                cnt[a[i].first - a[i - dec].first].push_back({a[i - dec].second, a[i].second});
            else {
                auto x = cnt[a[i].first - a[i - dec].first][0];
                if (a[i - dec].second == x.first || a[i - dec].second == x.second || a[i].second == x.second || a[i].second == x.first) continue;
                cout << "YES" << endl;
                cout << a[i - dec].second << " " << x.second << " " << x.first << " " << a[i].second << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}