#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int a[N];

int main() {
    string str;
    cin >> str;
    long long sum = 0;
    int keep = 0;
    int n = str.length() + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = keep;
        if (str[i - 1] == '<') keep += 1;
        else keep = 0;
    }
    keep = 0;
    for (int i = n; i >= 1; i--) {
        a[i] = max(keep, a[i]);
        if (str[i - 2] == '>') keep += 1;
        else keep = 0;
    }
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << endl;
    cout << accumulate(a+1, a+1+n, (long long)0) << endl;
    return 0;
}