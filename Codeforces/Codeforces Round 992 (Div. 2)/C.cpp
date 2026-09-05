#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n;
long long k;
int T;
long long pw2[60];

int cal(vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            int min_val = INT_MAX;
            for (int k = i; k <= j; k++) {
                min_val = min(min_val, v[k]);
            }
            sum += min_val;
        }
    }
    return sum;
}

void print(int x) {
    vector<int> v;
    for (int i = 0; i < x; i++) {
        v.push_back(i + 1);
    }

    int max_v = 0;
    map<int, int> mp;
    mp.clear();
    do {
        mp[cal(v)] += 1;
        if (cal(v) > max_v) {
            max_v = cal(v);
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << x << " " << mp[max_v] << endl;
    cout << "--------" << endl;

    vector<int> w;
    for (int i = 0; i < x; i++) {
        w.push_back(i + 1);
    }
    int cnt = 0;
    do {
        if (cal(w) == max_v) {
            cout << cnt << " : ";
            for (int xx : w) {
                cout << xx << " ";
            }
            cout << endl;
            cnt += 1;
        }
    } while (next_permutation(w.begin(), w.end()));
}

int main() {
//    for (int i = 1; i < 7; i++) {
//        print(i);
//    }
    pw2[0] = 1;
    for (int i = 1; i < 60; i++) {
        pw2[i] = pw2[i - 1] * 2ll;
    }

    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (n - 1 < 60 && k > pw2[n - 1]) {
            cout << -1 << endl;
            continue;
        }
        vector<int> v;
        map<int, int> mp;

        k--;
        for (int i = 0; i < 59; i++) {
            if (k >> i & 1) {
                mp[n - i - 1] = 1;
                v.push_back(n - i - 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (mp[i]) continue;
            cout << i << " ";
        }
        for (int x : v)
            cout << x << " ";

        cout << endl;
    }
    return 0;
}