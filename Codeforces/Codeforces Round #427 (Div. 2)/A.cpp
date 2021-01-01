#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int s1 = a * b + d + d;
    int s2 = a * c + e + e;
    if (s1 > s2) cout << "Second" << endl;
    else if (s1 < s2) cout << "First" << endl;
    else cout << "Friendship" << endl;
    return 0;
}