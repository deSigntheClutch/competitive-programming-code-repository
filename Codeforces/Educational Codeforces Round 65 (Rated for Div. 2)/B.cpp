#include <bits/stdc++.h>
using namespace std;

int n, m;
int answer[32];
int a[77];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 2; i <= 5; i++) {
        cout << "?"
             << " " << 1 << " " << i << endl;
        fflush(stdout);
        cin >> answer[i];
    }
    set<int> ss;
    ss.insert(4);
    ss.insert(8);
    ss.insert(16);
    ss.insert(15);
    ss.insert(42);
    ss.insert(23);

    map<int, int> cnt;
    for (int i = 2; i <= 5; i++) {
        if (answer[i] % 23 == 0) {
            cnt[23]++;
        } if (answer[i] % 7 == 0) {
            cnt[42]++;
        } if (answer[i] % 5 == 0) {
            cnt[15]++;
        } if (answer[i] % 4 == 0) {
            cnt[4]++;
        }
    }
    if (cnt[23] == 4) 
        a[1] = 23;
    else if (cnt[42] == 4)
        a[1] = 42;
    else if (cnt[15] == 4)
        a[1] = 15;
    else if (cnt[4] == 4) {
        for (int i = 2; i <= 5; i++) {
            if (answer[i] % 23 == 0) {
                a[1] = answer[i] / 23;
                break;
            } else if (answer[i] % 7 == 0) {
                a[1] = answer[i] / 42;
            } else if (answer[i] % 5 == 0) {
                a[1] = answer[i] / 15;
            } 
        }
    }
    ss.erase(ss.find(a[1]));
    for (int i = 2; i <= 5; i++) {
        a[i] = answer[i] / a[1];
        ss.erase(ss.find(a[i]));
    }
    for (int i = 1; i <= 6; i++) {
        if (a[i] == 0) {
            a[i] = *ss.begin();
        }
    }
    cout << "!";
    for (int i = 1; i <= 6; i++) {
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}