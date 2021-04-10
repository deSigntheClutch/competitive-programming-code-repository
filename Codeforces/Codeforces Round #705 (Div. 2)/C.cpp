#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T;
int n, k;
string s;
string res;
int rem[N];

void init() {
    for (int i = 'a'; i <= 'z'; i++) {
        rem[i] = 0;
    }
    res = "";
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> k >> s;
        init();
        if (n % k) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            rem[s[i]] = (rem[s[i]] + 1) % k;
        }
        bool flag = true;
        for (int i = 'a'; i <= 'z'; i++) {
            if (rem[i] != 0) flag = false;
        }
        if (flag) {
            cout << s << endl;
            continue;
        }

        int free_num = -1;
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            free_num += 1;

            rem[c] = (rem[c] - 1 + k) % k;

            for (int ch = c + 1; ch <= 'z'; ch++) {
                rem[ch] = (rem[ch] + 1) % k;
                int cnt = 0;
                for (int j = 'a'; j <= 'z'; j++) {
                    cnt += (k - rem[j]) % k;
                }
                if (cnt <= free_num) {
                    flag = true;
                    for (int j = 0; j < i; j++) {
                        res += s[j];
                    }
                    res += (char)(ch);
                    for (int j = 0; j < free_num - cnt; j++) {
                        res += 'a';
                    }
                    for (int j = 'a'; j <= 'z'; j++) {
                        int num = (k - rem[j]) % k;
                        for (int u = 0; u < num; u++) {
                            res += (char)j;
                        }
                    }
                    break;
                } 
                rem[ch] = (rem[ch] - 1 + k) % k;
            }
            if (flag) break;
        }

        if (flag) {
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}