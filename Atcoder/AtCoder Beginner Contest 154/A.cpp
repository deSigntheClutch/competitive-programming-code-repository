#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string s1, s2;
int n, m;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    cin >> n >> m;
    cin >> s;
    if (s == s1) {
        cout << n - 1 << " " << m << endl;
    } else if (s == s2){
        cout << n << " " << m - 1<< endl;
    }
    return 0;
}