#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int B = 100579;

int n;
int w, h;
int type[N], p[N], t[N];
int who[N];

vector<int> s[210000];

bool cmp(int x, int y) {
    return p[x] < p[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) {
        who[i] = i;
        cin >> type[i] >> p[i] >> t[i];
        if(p[i] == 2) who[i] *= -1;
        if (type[i] == 1) s[B + p[i] - t[i]].push_back(i);
        else s[B + p[i] - t[i]].push_back(-i);
    }
    for (int i = 0; i < 210000; i++) {
        vector<int> hori, veti;
        for (int x : s[i]) {
            if (x < 0) hori.push_back(-x);
            else veti.push_back(x);
        }
        sort(hori.begin(), hori.end(), cmp);
        sort(veti.begin(), veti.end(), cmp);
        vector<int> total;
        for (int x : hori) {
            total.push_back(-x);
        }
        for (int j = (int)veti.size() - 1; j >= 0; j--) {
            total.push_back(veti[j]);
        }
        int len = 0;
        for (int j = (int)veti.size() - 1; j >= 0; j--) {
            who[veti[j]] = total[len++];
        }
        for (int x : hori) {
            who[x] = total[len++];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(who[i] < 0) {
            cout << w << " " << p[-who[i]] << endl;
        } else {
            cout << p[who[i]] << " " << h  << endl;
        }
    }
    return 0;
}
