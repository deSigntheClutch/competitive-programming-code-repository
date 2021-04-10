#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

char dig[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string convert(int x) {
    string res = "";
    while (x) {
        res += dig[x % 16];
        x /= 16;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool check(int x) {
    if (x == 1) return false;
    while (x % 16 == 0) x /= 16;
    return x == 1;
}

string s;
int a[N], b[N], c[N], len;
int n;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> s) {
        len = 0;
        n = s.length();

        for (int i = 0; i < n; i++) {
            int pt = i;
            while (pt < n && s[i] == s[pt]) pt += 1;
            a[len] = s[i];
            b[len++] = pt - i;
            i = pt - 1;
        }

        for (int i = 0; i < len; i++) {
            if (check(b[i]) == true || b[i] == 2)
                c[i] = 1;
            else if (b[i] == 1)
                c[i] = 2;
            else
                c[i] = 0;
        }

        int delete_index = 0;
        for (int i = 0; i < len; i++) {
            if (1 == c[i]) {
                delete_index = i;
            } if (((i < len && a[i] > a[1 + i]) || (i == len - 1)) && 2 == c[i]) {
                delete_index = i;
                break;
            }
        }
        b[delete_index] -= 1;
        
        string res = "";
        for (int i = 0; i < len; i++) {
            if (b[i] == 0) continue;
            res += a[i];
            if (b[i] > 1) res += convert(b[i]);
        }
        cout << res << endl;
    }
    return 0;
}