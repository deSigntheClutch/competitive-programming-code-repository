#include <bits/stdc++.h>
using namespace std;

int check(int u) {
    int res = 0;
    while (u) {
        res += u % 10;
        u /= 10;
    }
    return res;
}

int main() {
    int n, cnt = 0;
    vector<int> v;
    cin >> n;
    for (int i = 1000; i >= 1; i--) {
        if(n < i) continue;
        if (check(n - i) == i) cnt++, v.push_back(n - i);
    }
    cout << cnt << endl;
    for (int x : v) {
        cout << x << endl;
    }
    return 0;
}
