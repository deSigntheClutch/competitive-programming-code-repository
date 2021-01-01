#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int n, x;

void dfs(int bit, int num, int pref) {
    if (num == 1) {
        vec.push_back(pref);
        return ;
    }
    if (bit == -1) {
        flag = false;
        return ;
    }
    if (x >> bit & 1) {
        int u = num / 2, v = num - num / 2;
        if (u & 1) swap(u, v);
        if (num & 1) {
            dfs(bit - 1, u, pref);
            dfs(bit - 1, v, pref | (1 << bit));
        } else {
            dfs(bit - 1, u, pref | (1 << bit));
            dfs(bit - 1, v, pref);
        }
    } else {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> x;
    dfs(19, n, 0);
    for (int t : v) co
        return 0;
}
