#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, k;
int a[N];
int l[N], r[N];
int val[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        bool flag = false, noPerm = false;
        cin >> n;
        vector<bool> used(n + 2, false);
        vector<int> x;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]] += 1;
            used[a[i]] = true;
            flag |= (cnt[a[i]] > 1);
            if (x.size() == 0 || x[x.size() - 1] > a[i]) {
                x.push_back(a[i]);
            }
        }
        int temp = *max_element(a + 1, a + 1 + n);
        for (int i = 1; i <= temp; i++) {
            if (used[i] == false) {
                noPerm = true;
            }
        }
        if (noPerm) {
            for (int i = 0; i < n; i++) {
                cout << "0";
            }
            cout << endl;
            continue;
        }

        stack<int> s;
        for (int i = 1; i <= n; i++) {
            while (s.size() >= 1 && a[s.top()] >= a[i]) s.pop();
            if (s.size() == 0)
                l[i] = 0;
            else
                l[i] = s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n; i >= 1; i--) {
            while (s.size() >= 1 && a[s.top()] >= a[i]) s.pop();
            if (s.size() == 0)
                r[i] = n + 1;
            else
                r[i] = s.top();
            s.push(i);
        }

        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int lef = i - l[i] - 1;
            int rig = r[i] - i - 1;
            if (lef > 0 && rig > 0) {
                cout << i << " " << lef << " " << rig << endl;
                ans = max(ans, lef + rig);
            }
        }
        if (flag == false)
            cout << 1;
        else
            cout << 0;

        for (int i = 1; i < ans; i++) {
            cout << "0";
        }
        for (int i = ans; i < n; i++) {
            cout << "1";
        }
        cout << endl;
    }
    return 0;
}
/*

gg D.cpp && run


*/
