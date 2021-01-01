#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int N = 1e5 + 10;

string t;
string s;
map<char, char> m;

string trans(string c) {
    string res = "";
    for(int i = 0; i < c.length(); i++) {
        if(c[i] >= '0' && c[i] <= '9') res += c[i];
        else res += m[c[i]];
    }
    return res;
}

int main() {
    cin >> t;
    cin >> s;
    for(int i = 0; i < 26; i++) {
        m[t[i]] = s[i];
        m[(char)('A' + t[i] - 'a')] = (char)('A' + s[i] - 'a');
    }
    string c;
    cin >> c;
    cout << trans(c) << endl;
    return 0;
}

