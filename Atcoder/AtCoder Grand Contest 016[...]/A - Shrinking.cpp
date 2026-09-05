#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

string s;
int n;
int cnt[N];


int main() {
    cin >> s;
    n = s.length();

    for (int i = 0; i < s.length(); i++) {
        cnt[s[i]]++;
    }

    char mx;
    int res = 0;

    for (int i = 'a'; i <= 'z'; i++) {
        if (res < cnt[i]) {
            mx = i;
        }
    }



    return 0;
}