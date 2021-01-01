#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    long long sum = 0;

    for (int i = 1; i <= n; i++) {
         cin >> a[i];         
    }

    sort(a + 1, a + 1 + n);
    bool flag = false;
    int cnt_same = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1] && a[i] == 0) cnt_same += 2;
        else if (a[i] == a[i + 1]) cnt_same += 1;
    }
    if (cnt_same >= 2) cout << "cslnb" << endl;
    else if (cnt_same == 1) {
        int fd = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i + 1]) {
                fd = i;
                break;
            }
        }
        a[fd]--;
        if (fd == 1 || a[fd - 1] != a[fd]) {
            for (int i = 1; i <= n; i++) {
                sum += a[i] - (i - 1);
            }   
            if (sum & 1) cout << "cslnb" << endl;
            else cout << "sjfnb" << endl;

        } else cout << "cslnb" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            sum += a[i] - (i - 1);
        }   
        if (sum & 1) cout << "sjfnb" << endl;
        else cout << "cslnb" << endl;
    }

    return 0;
}