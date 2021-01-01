#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
 
int n, k;
string s;
bool vis[N];
 
int rate(int id) {
    if (id - 1 >= 0 && id + 1 < n && s[id - 1] == 'W' && s[id + 1] == 'W') return 4;
    else if (id - 1 >= 0 && id + 1 < n && ((s[id - 1] == 'W' && s[id + 1] == 'L') || (s[id - 1] == 'L' && s[id + 1] == 'W'))) return 3;
    else if ((id == 0 && s[id + 1] == 'W') || (id == n - 1 && s[id - 1] == 'W')) return 2;
    else return 1;
}
 
int get_points() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (s[i] == s[i - 1] && s[i - 1] == 'W') res += 2;
            else if (s[i] == 'W') res += 1;
        }
        else {
            if (s[i] == 'W') res += 1;
        }
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        priority_queue<pair<int, int>> heap;
        cin >> n >> k >> s;
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'W') continue;
            int val = rate(i);
            heap.push({val, i});
        }
        int sum = get_points();
        while (!heap.empty() && k) {
            auto p = heap.top();
            if (vis[p.second] == 1) {
                heap.pop();
                continue;
            }
            //cout << p.first << " " << p.second << endl;
            if (p.first == 4) sum += 3;
            else if (p.first == 3 || p.first == 2) sum += 2;
            else sum += 1;
            s[p.second] = 'W';
            k--;
            if (!k) break;
            vis[p.second] = 1;
            heap.pop();
            if (p.second - 1 >= 0 && s[p.second - 1] == 'L') heap.push({rate(p.second - 1), p.second - 1});
            if (p.second + 1 < n && s[p.second + 1] == 'L') heap.push({rate(p.second + 1), p.second + 1});
        }
        cout << sum << endl;
    }
    return 0;
}
