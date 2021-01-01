#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
multiset<int> ms;
map<int, int> cur;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        multiset<int>::iterator it = ms.find(cur[a[i]]);
        if (it != ms.end()) ms.erase(it);

        cur[a[i]] += 1;
        ms.insert(cur[a[i]]);

        // -1 big
        auto big = --ms.end();
        int val = *big;
        ms.erase(big);
        if (val > 1) ms.insert(val - 1);
        if (ms.size() <= 1 || *ms.begin() == *(--ms.end())) ans = max(i, ans);
        if (ms.find(val - 1) != ms.end()) ms.erase(ms.find(val - 1));
        ms.insert(val);

        // -1 small
        auto small = ms.begin();
        val = *small;
        ms.erase(small);
        if (val > 1) ms.insert(val - 1);
        if (ms.size() <= 1 || *ms.begin() == *(--ms.end())) ans = max(i, ans);
        if (ms.find(val - 1) != ms.end()) ms.erase(ms.find(val - 1));
        ms.insert(val);
    }
    cout << ans << endl;
    return 0;
}

/*

13
1 1 1 2 2 2 3 3 3 4 4 4 5


*/