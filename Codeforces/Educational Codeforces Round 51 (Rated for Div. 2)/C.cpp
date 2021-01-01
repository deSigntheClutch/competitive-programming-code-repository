#include <bits/stdc++.h>
using namespace std;

int n;
int a[123];
int ans[123];

map<int, int> cnt;
map<int, int> id;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt_odd = 0, cnt_2 = 0, cnt_big = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second == 1) {
            cnt_odd += 1;
        } else if (it->second == 2) {
            cnt_2 += 1;
        } else {
            cnt_big += 1;
        }
    }
    if (cnt_odd % 2 == 0) {
        cout << "YES" << endl;
        int len = cnt_odd / 2;
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] == 1 && id[a[i]] == 0 && len) {
                id[a[i]] = 1;
                len--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (id[a[i]] == 0)
                cout << "A";
            else
                cout << "B";
        }
        cout << endl;
    } else if (cnt_odd % 2 == 1 && cnt_big >= 1) {
                cout << "YES" << endl;

        int len = cnt_odd / 2;
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] == 1 && id[a[i]] == 0 && len) {
                id[a[i]] = 1;
                len--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] > 2 && id[a[i]] == 0) {
                id[a[i]] = 2;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (id[a[i]] == 0)
                cout << "A";
            else if (id[a[i]] == 2) {
                cout << "B";
                id[a[i]] = 0;
            } else cout << "B";
        }
        cout << endl;
    } else
        cout << "NO" << endl;

    return 0;
}
