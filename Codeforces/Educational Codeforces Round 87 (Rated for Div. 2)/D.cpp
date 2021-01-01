#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right
const int N = 1e6 + 1;

multiset<int> s;
int n, q;
int t[4 * N];

void add(int rt, int left, int right, int idx, int val) {
    if (left == right) {
        t[rt] += val;
        return;
    }
    if (mid >= idx) add(lson, idx, val);
    else add(rson, idx, val);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}

int get(int rt, int left, int right, int val) {
    if (left == right) {
        return left;
    }
    int sm = t[rt << 1];
    //cout << left << " " << right << " " << sm <<  " " << val << endl;
    if (t[rt << 1] >= val) return get(lson, val);
    else return get(rson, val - sm);
}

int main() {
    ios::sync_with_stdio(false);
    set<int> s;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
        add(1, 1, n, t, 1);
    }
    for (int i = 0; i < q; i++) {
        int qq;
        cin >> qq;
        if (qq < 0) {
             int idx = get(1, 1, n, -qq);
             //cout << idx << endl;
             s.erase(s.lower_bound(idx));
             add(1,1,n,idx, -1);
        } else {
            s.insert(qq);
            add(1,1,n,qq, 1);
        }
    }
    if (s.size() == 0) cout << 0 << endl;
    else cout << *s.begin() << endl;
    return 0;
}
