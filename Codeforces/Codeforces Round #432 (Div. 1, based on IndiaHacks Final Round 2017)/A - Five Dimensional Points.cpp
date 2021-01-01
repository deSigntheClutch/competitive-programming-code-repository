#include<bits/stdc++.h>
using namespace std;

int n;
int x[1234][5];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> x[i][j];
        }
    }
    if (n > 99) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) continue;
                int a[5], b[5];
                int sum = 0;
                for (int f = 0; f < 5; f++) {
                    a[f] = x[j][f] - x[i][f];
                    b[f] = x[k][f] - x[i][f];
                    sum += a[f] * b[f];
                }
                if (sum > 0) flag = false;
            }
        }
        if (flag) v.push_back(i + 1);
    }
    cout << (int)v.size() << endl;
    for (int u : v) cout << u << " ";
    cout << endl;
    return 0;
}
