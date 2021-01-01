#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

bool used[N];

int main() {
    ios::sync_with_stdio(false);
    set<int> s;
    for (int i = 1; i < N; i++) s.insert(i);
    for (int cs = 0; cs < 100; cs++) {
        int a = *s.begin();
        s.erase(s.begin());
        auto ptr = s.begin();
        while (s.find(a ^ (*ptr)) == s.end()){
            ptr++;
        }
        int b = *ptr;
        int c = a ^ b;
        s.erase(b);
        s.erase(c);
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}