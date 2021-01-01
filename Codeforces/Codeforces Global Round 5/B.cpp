#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int T;
int n;
int a[N];
int b[N];
bool used[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    int ptr = 1;
    for (int i = 1; i <= n; i++) {
        if (ptr > n) break;
        if (used[a[i]]) continue;
        int prev_ptr = ptr;
        while (b[ptr] != a[i] && ptr <= n) ptr += 1;
        for (int j = prev_ptr; j < ptr; j++) {
            used[b[j]] = true;
            cnt += 1;
        }
        used[b[ptr]] = true;
        ptr += 1;

    }
    cout << cnt << endl;
    return 0;
}