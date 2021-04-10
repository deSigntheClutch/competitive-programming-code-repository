#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 6;

int T;
int n;
int p[N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        set<int> s;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            s.insert(p[i]);
        }

        int target = n;
        for (int i = n; i >= 1; i--) {
            int ptr = i;
            while (ptr >= 1 && p[ptr] != target) {
                s.erase(p[ptr]);
                ptr -= 1;
            }
            for (int j = ptr; j <= i; j++){
                //cout << "cao " << p[j] << endl;
                ans.push_back(p[j]);
            }
            s.erase(target);
            if (s.size() > 0) {
                target = *(--s.end());
            }
            
            i = ptr;
            //cout << "------" << " " << target << endl;
        }
        for (int x : ans) cout << x << " ";
        cout << endl;
    }
}