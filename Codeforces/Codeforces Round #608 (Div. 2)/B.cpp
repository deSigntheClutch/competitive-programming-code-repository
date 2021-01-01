#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

struct edge {
    int to;
    ll v;
};

string s;

bool check() {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] != s[i + 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            cnt += 1;
        }
    }
    if (cnt % 2 == 1 && (n - cnt) % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    if (check()) {
        cout << (int)ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl; 
        return 0;
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'B') {
            ans.push_back(i + 1);
            s[i] = 'W';
            if (s[i + 1] == 'W') s[i + 1] = 'B';
            else s[i + 1] = 'W';
        }
    }
    if (check()) {
        cout << (int)ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl; 
        return 0;
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'W') {
            ans.push_back(i + 1);
            s[i] = 'B';
            if (s[i + 1] == 'B') s[i + 1] = 'W';
            else s[i + 1] = 'B';
        }
    }

    cout << (int)ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl; 
    return 0;
}