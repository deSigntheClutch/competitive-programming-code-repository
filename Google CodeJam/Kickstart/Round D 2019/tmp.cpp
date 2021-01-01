#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first
#define mp make_pair

typedef long long int64;

const int N = 1e5 + 9;



int main() {
    ios::sync_with_stdio(false);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    v.push_back(5);

    v.push_back(6);
    cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;

    return 0;
}