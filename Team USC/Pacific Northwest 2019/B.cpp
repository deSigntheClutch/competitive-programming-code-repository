#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

const int N = 2e5 + 5;

int n, k;
int a[N];
set<int> app[N];
bool used[N];

int main() {
    ios::sync_with_stdio(false);
    stack<int> ans;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        app[a[i]].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (used[a[i]] == 1) {
            app[a[i]].erase(i);
            continue;
        }
        else {
            while (ans.size() > 0 && a[i] < ans.top() && app[ans.top()].size() != 0) {
                used[ans.top()] = 0;
                ans.pop();
            }
            ans.push(a[i]);
            used[a[i]] = 1;
            app[a[i]].erase(i);
        }
    }
    vector<int> rev_ans;
    while (!ans.empty()) rev_ans.push_back(ans.top()), ans.pop();
    reverse(all(rev_ans));
    for (int x : rev_ans) cout << x << endl;
    return 0;
}