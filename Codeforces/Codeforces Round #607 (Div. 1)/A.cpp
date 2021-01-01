#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int x;
string str, command;
long long f[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> x;
        cin >> str;
        f[0] = str.length();
        command = str;

        for (int i = 1; i <= x; i++) {
            f[i] = (f[i - 1] + (long long)(command[i - 1] - '0' - 1) * ((f[i - 1] - i + MOD) % MOD) % MOD) % MOD;
            int len = command.length();
            bool flag = false;
            if (len >= x) continue;
            for (int j = 0; j < (command[i - 1] - '0' - 1); j++) {
                if (flag == true) {     
                    break;
                }
                for (int k = i; k < len; k++) {
                    if (command.length() == x) {
                        flag = true;
                        break;
                    }
                    command += command[k];
                    if (command.length() == x) {
                        flag = true;
                        break;
                    }
                }
            }
            //cout << i << " " << command << " " << f[i] << endl;
        }
        cout << f[x] << endl;
    }
    return 0;
}