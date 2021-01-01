
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;


int n;
int a[N];


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
           
        }
        vector<int> ans;
        ans.push_back(a[1]);
        for (int i = 1; i <= n; i++) {
            if (i == n - 1) {
                if (ans[ans.size() - 1] != a[n]) ans.push_back(a[n]);
                break;
            }
            bool increasing = (a[i + 1] > a[i]);
            int ptr = i + 1;
            if (increasing == true) {
                while (ptr <= n && a[ptr] > a[ptr - 1]) {
                    ptr += 1;
                }
                ans.push_back(a[ptr - 1]);
                if (ptr - 1 == n) break; 
            } else {
                while (ptr <= n && a[ptr] < a[ptr - 1]) {
                    ptr += 1;
                }
                ans.push_back(a[ptr - 1]);
                if (ptr - 1 == n) break; 
            }
            i = ptr - 2;
        }
        cout << ans.size() << endl;
        for (int x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}
