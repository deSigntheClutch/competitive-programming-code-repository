#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 3e5 + 5;
string s;
int n;
int le[N], ri[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        le[i] = i - 1;
        ri[i] = i + 1;
        if (le[i] >= 0 && ri[i] < n) {
            if (s[i] == 'o' && s[le[i]] == 'f' && s[ri[i]] == 'x') {
                q.push(i);
            }
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt += 1;
        int l = le[le[x]];
        int r = ri[ri[x]];
        if (l >= 0 && l < n) ri[l] = r;
        if (r >= 0 && r < n) le[r] = l;
        if (l >= 0 && l < n && s[l] == 'o' && (le[l] >= 0 && s[le[l]] == 'f') && (ri[l] < n && s[ri[l]] == 'x')) {
            q.push(l);
        }
        if (r >= 0 && r < n && s[r] == 'o' && (le[r] >= 0 && s[le[r]] == 'f') && (ri[r] < n && s[ri[r]] == 'x')) {
            q.push(r);
        }
    }
    cout << n - 3 * cnt << endl;
    return 0;
}