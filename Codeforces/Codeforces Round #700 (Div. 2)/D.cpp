#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
int n;
int a[N];
bool used[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> s1, s2;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s1.empty() || s1.top() != a[i]) {
            s1.push(a[i]);
            cnt += 1;
        } else {
            if (s2.size() > 0 && s2.top() == a[i]) cnt -= 1;
            s2.push(a[i]);
            cnt += 1;
        }
    }
    cout << cnt << endl;
}