#include <bits/stdc++.h>
using namespace std;

int T;
int h, m;
string time_str;
int tran[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

bool check(string s) {
    // number valid
    bool flag = true;
    string res = "";
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            res += ':';
            continue;
        }
        // cout << i << " " << s[i] << endl;
        if (tran[s[i] - '0'] == -1) return false;
        res += (char)(tran[s[i] - '0'] + '0');
    }
    reverse(res.begin(), res.end());

    // cout << res << endl;
    int hh = res[1] - '0' + (res[0] - '0') * 10;
    if (hh >= h) return false;
    int mm = res[4] - '0' + (res[3] - '0') * 10;
    if (mm >= m) return false;

    return true;
}

string convert(int hh, int mm) {
    string res = "";
    int h1 = hh / 10;
    int h2 = hh % 10;
    res += (char)(h1 + '0');
    res += (char)(h2 + '0');
    res += ':';
    int m1 = mm / 10;
    int m2 = mm % 10;
    res += (char)(m1 + '0');
    res += (char)(m2 + '0');
    return res;
}

string dec(string s) {
    int hh = s[1] - '0' + (s[0] - '0') * 10;
    int mm = s[4] - '0' + (s[3] - '0') * 10;
    if (mm == 0 && hh == 0) {
        hh = h - 1;
        mm = m - 1;
    } else if (mm == 0) {
        mm = m - 1;
        hh -= 1;
    } else {
        mm -= 1;
    }
    return convert(hh, mm);
}

string inc(string s) {
    int hh = s[1] - '0' + (s[0] - '0') * 10;
    int mm = s[4] - '0' + (s[3] - '0') * 10;
    mm += 1;
    // cout << hh << " " << mm << endl;
    if (mm == m) {
        hh += 1;
        mm = 0;
    }
    if (hh == h) {
        hh = 0;
    }
    return convert(hh, mm);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> h >> m;
        cin >> time_str;
        string cpy = time_str;
        for (int diff = 0; diff <= 10000; diff++) {
            // if (check(cpy)) {
            //     cout << cpy << endl;
            //     break;
            // }
            if (check(time_str)) {
                cout << time_str << endl;
                break;
            }
            // cout << "1";
            // cpy = dec(cpy);
            // cout << "2";
            time_str = inc(time_str);
            // cout << cpy << " " << time_str << endl;
        }
    }
    return 0;
}