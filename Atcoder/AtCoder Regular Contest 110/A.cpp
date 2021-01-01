#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define int long long

using namespace std;

const int N = 1e5 + 5;

signed main() {
    ios::sync_with_stdio(false);
    int n;
    int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    cin >> n;
    int ans = 1;
    for (int i = 0; i < 10; i++) {
        int tmp = n;
        int num = 0, cur = 1;
        while (cur <= tmp) {
            cur *= prime[i];
            num += 1;
        }
        num -= 1;
        //cout << num << " " << prime[i] << endl;
        while (num--) ans *= prime[i];
    }
    ans += 1;
    cout << ans << endl;
    return 0;
}