#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    int cnt[4];
    for (int i = 0; i < 4; i++) cin >> cnt[i];
    if (cnt[0] != cnt[3]) cout << 0 << endl;
    else if (cnt[0] == 0 && cnt[2] >= 1) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
