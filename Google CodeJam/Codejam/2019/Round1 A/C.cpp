#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int to[N][28];
int dp[N];
int num[N], n;
int root = 1, cnt = 1;

void trie_add(int rt, string s) {
    num[rt]++;
    for (int i = 0; i < s.length(); i++) {
        if (to[rt][s[i] - 'A'] == 0) {
            cnt++;
            to[rt][s[i] - 'A'] = cnt;
            rt = cnt;
            num[rt]++;
        } else {
            rt = to[rt][s[i] - 'A'];
            num[rt]++;
        }
    }
}

int dfs(int r) {
    int sum = 0;
    for (int i = 0; i < 28; i++) {
        int nxt = to[r][i];
        if (nxt == 0) continue;
        printf("@%d %d\n", r, to[r][i]);
        sum += dfs(nxt);
    }
    if (r == 1) {
        dp[r] = sum;
        return sum;
    }
    printf("%d: %d %d %d\n", r, sum, dp[r], num[r]);
    dp[r] = (sum + (num[r] - 2 * sum >= 2));
    return dp[r];
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        memset(num, 0, sizeof num);
        memset(dp, 0, sizeof dp);
        memset(to, 0, sizeof to);
        cnt = 1; root = 1;
        cout << "Case #" << cs << ": ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            reverse(str.begin(), str.end());
            trie_add(root, str);
        }

        int x = dfs(1);
        cout << 2 * x << endl;
    }
    return 0;
}

/*
4
2
TARPOL
PROL
3
TARPOR
PROL
TARPRO
6
CODEJAM
JAM
HAM
NALAM
HUM
NOLOM
4
PI
HI
WI
FI

*/
