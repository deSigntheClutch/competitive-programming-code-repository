#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string ok;

        while (ss >> ok) {
             cout << ok << endl;
        }
        cout <<"YES" << endl;
    }
    return 0;
}