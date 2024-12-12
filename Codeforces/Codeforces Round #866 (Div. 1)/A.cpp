#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

const int N = 2e5 + 5;

int a[N];
int n;

int getMex(vector<int> v) {
    map<int, int> mp;
    int mex = 0;
    for (auto x : v) {
        mp[x] = 1;
        while (mp[mex] == 1) {
            mex++;
        }
    }
    return mex;
}

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            if (a[1] == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
            continue;
        }

        int mex = getMex(vector<int>(a + 1, a + 1 + n));

        int left = 0, right = 0;
        for (int i = 1; i <= n; i++) {
            if (left == 0 && a[i] == mex + 1) left = i;
            if (a[i] == mex + 1) right = i;
        }

        if (left == right && left == 0) {
            if (mex == n) cout << "NO" << endl;
            else cout << "YES" << endl;
            continue;
        }

        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (i < left) v.push_back(a[i]);
            else if (i > right) v.push_back(a[i]);
        }
        int mex2 = getMex(v);
        if (mex2 == mex) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
