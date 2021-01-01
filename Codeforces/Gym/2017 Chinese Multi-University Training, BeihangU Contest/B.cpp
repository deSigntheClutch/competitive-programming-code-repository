#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;

struct Base {
    vector<int> cnt;
    bool leading;
    Base() {
        cnt = vector<int>(N, 0);
        leading = false;
    }
    bool operator < (struct Base x) const {
        for (int i = cnt.size() - 1; i >= 0 ; i--) {
            if (cnt[i] == x.cnt[i]) continue;
            return cnt[i] < x.cnt[i];
        }
        return false;
    }
    void proc() {
        for (int i = 0; i < cnt.size() - 1; i++) {
            int pr = cnt[i] / 26;
            cnt[i] = cnt[i] % 26;
            cnt[i + 1] += pr;
        }
    }
};

long long base26[N];

int main() {
    int tcase = 0;
    base26[0] = 1;
    for (int i = 1; i < N; i++) {
        base26[i] = base26[i - 1] * 26ll % MOD; 
    }
    ios::sync_with_stdio(false);
    while (cin >> n) {
        Base a[30];
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            reverse(str.begin(), str.end());
            for (int j = 0; j < str.length(); j++) {
                a[str[j] - 'a'].cnt[j] += 1;
                if (j == str.length() - 1 && str.length() > 1) {
                    a[str[j] - 'a'].leading = true;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            a[i].proc();
        }
        long long sum = 0;
        sort(a, a + 26);
        long long max_val = 25;
        if (a[0].leading == true) {
            int idx = 0;
            for (idx = 0; ; idx++) {
                if (a[idx].leading == false) {
                    break;
                }
            }
            for (int i = idx; i > 0; i--) {
                swap(a[i - 1], a[i]);
            }
        }
        for (int x = 25; x >= 0; x--) {
            bool flag = false;
            for (int i = 0; i < a[x].cnt.size(); i++) {
                if (a[x].cnt[i] != 0) {
                    flag = true;
                }
                if (flag) sum = (sum + (long long)max_val * a[x].cnt[i] % MOD * base26[i] % MOD) % MOD;
            }
            if (flag) max_val -= 1;
        }
        cout << "Case #" << ++tcase << ": " << sum << endl;
    }
    return 0;
}
