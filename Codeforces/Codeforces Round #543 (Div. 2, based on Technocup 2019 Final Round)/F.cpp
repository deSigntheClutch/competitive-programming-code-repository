#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int INF = 1e9 + 5;

int n, a, b;
string s;
int f[N], nxt[N];

int cal(int idx) 
    string t = "";
    for (int i = idx - 1; i >= 0; i--) {
        t += s[i];
    }
    memset(nxt, 0, sizeof nxt);
    nxt[0] = nxt[1] = 0;
    int res = 0;
    //cout << t << endl;
    for (int i = 2; i <= t.length(); i++) {
        int tmp = i - 1;
        while(nxt[tmp] != 0 && t[nxt[tmp]] != t[i - 1]) {
            tmp = nxt[tmp];
        }
        if (t[nxt[tmp]] == t[i - 1]) {
            nxt[i] = nxt[tmp] + 1;
        }
        res = max(res, min(i / 2, nxt[i]));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    cin >> s;
    int len = s.length();
    fill(f, f + N, INF);
    f[0] = 0;
    f[1] = a;

    for (int i = 2; i <= len; i++) {
        f[i] = min(f[i - 1] + a, f[i]);
        f[i] = min(f[i], f[i - cal(i)] + b);
    }
    cout << f[len] << endl;
    return 0;
}