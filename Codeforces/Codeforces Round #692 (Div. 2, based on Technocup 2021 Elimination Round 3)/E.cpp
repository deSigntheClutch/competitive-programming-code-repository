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

const int N = 30;

int n, T;
int pow2[N];
string s;

signed main() {
    ios::sync_with_stdio(false);
    pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    cin >> n >> T >> s;
    int sum = 0;
    vector<int> a;
    for (int i = 0; i < n - 2; i++) {
        sum += pow2[s[i] - 'a'];
        a.push_back(-(pow2[s[i] - 'a']));
    }
    T -= (pow2[s[n - 1] - 'a'] - pow2[s[n - 2] - 'a']);
    if ((sum - T) % 2 == 1 || sum < T) {
        cout << "No" << endl;
        return 0;
    }
    sum = (sum - T) / 2;
    sort(a.begin(), a.end());
    for (int x : a) {
        //cout << x << " ";
        if (sum + x >= 0) {
            sum += x;
        }
    }
    //cout << endl;
    cout << ((sum == 0) ? "Yes" : "No") << endl;
}