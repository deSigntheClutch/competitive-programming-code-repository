#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 9;
const int N = 1e2 + 2;

int n;

void ask(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    fflush(stdout);
}

int receive() {
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int cur = 2;
    for (int i = 3; i <= n; i++) {
        ask(1, cur, i);
        int answer = receive();
        if (answer == 1) {
            cur = i;
        }
    }
    cout << "! " << cur << endl;
    return 0;
}