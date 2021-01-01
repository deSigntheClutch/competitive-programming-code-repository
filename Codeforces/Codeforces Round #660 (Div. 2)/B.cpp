#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, x;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int num = (n - 1) / 4 + 1;
        string str = "";
        for (int i = 0; i < num; i++) {
            str += "8";
        }
        for (int i = 0; i < n - num; i++) {
            str += '9';
        }
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}