#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
int n;
 
vector<string> res[123][123];
 
void ask(int id, int l, int r) {
    cout << "? " << l << " " << r << endl; 
    fflush(stdout);
    string str;
    for (int i = 0; i < (r - l + 1) * (r - l + 2) / 2; i++) {
        cin >> str;
        int len = str.length();
        sort(str.begin(), str.end());
        res[id][len].push_back(str);
    }
}
 
string ans;
 
int main() {
    cin >> n;
    if (n == 1) {
        ask(1, 1, 1);
        cout << "! " << res[1][1][0] << endl;
        fflush(stdout);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        ans += '.';
    }
    ask(1, 1, n);
    ask(2, 1, n - 1);
    for (int len = 1; len <= n - 1; len++) {
        sort(res[2][len].begin(), res[2][len].end());
    }
    for (int len = 1; len <= n; len++) {
        sort(res[1][len].begin(), res[1][len].end());
    }
    vector<string> suffix;
    for (int len = 1; len <= n - 1; len++) {
        string tmp = "";
        for (int i = 0; i < res[2][len].size(); i++) {
            if (res[1][len][i] != res[2][len][i]) {
                tmp = res[1][len][i];
                break;
            }
        }
        if (tmp == "") tmp = res[1][len][res[1][len].size() - 1];
        suffix.push_back(tmp);
    }
    vector<char> deleted;
    for (int i = 0; i < n - 1; i++) {
        string tmp = suffix[i];
        int cnt[30];
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < tmp.length(); j++) {
            cnt[tmp[j] - 'a'] += 1;
        }
        for (char c : deleted) {
            cnt[c - 'a'] -= 1;
        }
        for (int j = 0; j < 26; j++) {
            if (cnt[j] == 1) {
                ans[n - 1 - i] = (char)('a' + j);
                deleted.push_back((char)('a' + j));
                break;
            }
        }
    }
    ask(3, 1, 1);
    ans[0] = res[3][1][0][0];
    cout << "! " << ans << endl;
    return 0;
}

/*
 
c  
b
ca
bc
a
acb
.
 
ca
a
c
.
 
a
.
 
a
.
 
 
*/