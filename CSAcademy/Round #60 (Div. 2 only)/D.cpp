#include <bits/stdc++.h>
using namespace std;
typedef bitset<20> BYTE;

int n;
int r[44], b[44];
unordered_map<long long, vector<BYTE>> cached;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> b[i];
    }
    for (int i = 0; i < (1 << (n / 2)); i++) {
        long long sumr = 0;
        long long sumb = 0;
        BYTE status = BYTE();
        for (int j = 0; j < n / 2; j++) {
            if (i >> j & 1) {
                sumr += r[j];
            } else {
                sumb += b[j];
                status.set(j);
            }
        }
        cached[sumr - sumb].push_back(status);
    }
    int mid = n / 2;
    int ans = n + 1;
    pair<string, string> anss;
    int lp = (n - n / 2);
    for (int i = 0; i < (1 << lp); i++) {
        long long sumr = 0;
        long long sumb = 0;
        int r1 = 0;
        BYTE status = BYTE();
        for (int j = 0; j < lp; j++) {
            if (i >> j & 1) {
                sumr += r[mid + j];
                r1 += 1;
            } else {
                sumb += b[mid + j];
                status.set(j);
            }
        }
        for (BYTE x : cached[sumb - sumr]) {
            int r0 = lp - x.count();
            int sb = abs(2 * (r0 + r1) - n);
            if (sb < ans) {
                ans = sb;
                anss = make_pair(x.to_string(), status.to_string());
            }
        }
        if ((ans == 0 && n % 2 == 0) || (ans == 1 && n % 2 == 1)) {
          break;
        }
    }
    if (ans == n + 1)
        cout << -1 << endl;
    else {
        string s1 = anss.first;
        reverse(s1.begin(), s1.end());
        string s2 = anss.second;
        reverse(s2.begin(), s2.end());
        cout << s1.substr(0, n / 2) << s2.substr(0, n - n / 2) << endl;
    }
    return 0;
}