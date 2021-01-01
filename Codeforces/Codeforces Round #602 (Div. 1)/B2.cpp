#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid+1, right

const int N = 2e5 + 5;
pair<int, int> b[N];
int a[N];
int n, m;
vector<pair<pair<int, int>, int>> Q;
int tr[N << 2];
int ans[N];

void push_up(int rt) {
    tr[rt] = tr[rt << 1] + tr[rt << 1|1];
}

int query(int rt, int left, int right, int val) {
    if (left == right) {
        return left;
    }
    if (tr[rt << 1] >= val) return query(lson, val);
    else return query(rson, val - tr[rt << 1]);
}

void update(int rt, int left, int right, int id) {
    if (right == left && id == right) {
        tr[rt] += 1;
        return ;
    }
    if (mid >= id)  update(lson, id);
    else update(rson, id);
    push_up(rt);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(-a[i], i);
    }
    sort(b + 1, b + 1 + n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int k, pos;
        cin >> k >> pos;
        Q.push_back(make_pair(make_pair(k, pos), i));
    }
    sort(Q.begin(), Q.end());
    int pt = 0;
    for (auto x : Q) {
        pair<int, int> y = x.first;
        int id = x.second;
        while (pt != y.first) {
            pt++;
        
            update(1, 1, n, b[pt].second);
        }
        ans[id] = a[query(1, 1, n, y.second)];
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
    return 0;
}

/*

3
10 20 10
6
3 3
*/