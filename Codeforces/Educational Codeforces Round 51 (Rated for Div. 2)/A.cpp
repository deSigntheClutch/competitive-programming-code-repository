#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
    int cnt = 0;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') cnt |= 1;
        if (c >= 'A' && c <= 'Z') cnt |= 2;
        if (c >= '0' && c <= '9') cnt |= 4;
    }
    return cnt == 7;
}

vector<string> g[2];

int main() {
    g[0].push_back("0"), g[0].push_back("A"), g[0].push_back("a");
    g[1].push_back("0a"), g[1].push_back("0A"), g[1].push_back("aA");
    g[1].push_back("a0"), g[1].push_back("A0"), g[1].push_back("Aa");
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        if (check(s))
            cout << s << endl;
        else {
            bool flag = false;
            for (int i = 1; i <= 2; i++) {
                for (int j = 0; i + j - 1 < s.length(); j++) {
                    string tmp = s;
                    for (auto str : g[i - 1]) {
                        for (int k = 0; k < i; k++) {
                            tmp[j + k] = str[k];
                        }
                        if (check(tmp)) {
                            flag = true;
                            cout << tmp << endl;
                            break;
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
        }
    }
    return 0;
}
