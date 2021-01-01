#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;

struct Line {
    int left, right;
    bool operator < (struct Line l) const {
        if (left == l.left) return right < l.right;
        return left < l.left;
    }
};
Line l[N];
vector<int> a[N];
vector<Line> lines;

int fwt[2][N];

void add(int kk, int id) {
    while (id < N) {
        fwt[kk][id] += 1;
        id += id & -id;
    }
}

int get(int kk, int id) {
    int sum = 0;
    while (id) {
        sum += fwt[kk][id];
        id -= id & -id;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j< m;j++){
            int v;
            cin >> v;
            v += 1;
            a[i].push_back(v);
        }
        l[i].left = a[i][0];
        l[i].right = a[i][a[i].size() - 1];
        swap(l[i].left, l[i].right);
        bool flag = true;
        for (int j = 0; j< m - 1;j++){
            if (a[i][j] < a[i][j + 1]) flag = false;
        }
        if (flag) lines.push_back(l[i]);
    }
    long long ans = 0;
    for (auto l : lines) {
        add(0, l.left);
        add(1, l.right);
    }
    for (auto l : lines) {
        ans += get(0, N - 1) - get(0, l.right - 1);
        ans += get(1, l.left);
    }
    cout << (long long) n * n - ans / 2 << endl;
    return 0;
}