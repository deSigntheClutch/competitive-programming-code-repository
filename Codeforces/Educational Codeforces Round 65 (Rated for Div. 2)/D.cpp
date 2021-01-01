#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
string s;
int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    priority_queue<pair<int, int>> h;
    pair<int, int> a = {0, 1}, b = {0, 0};
    for (int i = 0; i < n; i++) {
        //cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
        if (s[i] == '(') {
            if (a > b) swap(a, b);
            a = {a.first + 1, a.second};
            ans[i] = '0' + a.second;
        } else {
            if (a < b) swap(a, b);
            a = {a.first - 1, a.second};
            ans[i] = '0' + a.second;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (char)ans[i];
    }
    cout << endl;
    return 0;
}