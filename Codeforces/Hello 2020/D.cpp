#include <bits/stdc++.h>
using namespace std;

#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid+1, right

const int INF = 1e9 + 2;

struct ccc {
    int l, r, x, y;
    ccc (int a=0, int b=0, int c=0, int d=0) {
        l = a;
        r = b;
        x = c;
        y = d;
    }
    bool operator < (struct ccc c) const {
        if (l == c.l) return r < c.r;
        return l < c.l;
    }
};

const int N = 4e5 + 5;
const int M = 1e5 + 5;
ccc intv[M], intw[M];
int a[M], b[M], c[M], d[M];
int n;

int tr[2][N << 2];

void push_up(int whi, int rt) {
    // whi 0 left end
    if (whi == 0) tr[whi][rt] = max(tr[whi][rt << 1], tr[whi][rt << 1|1]);
    else tr[whi][rt] = min(tr[whi][rt << 1], tr[whi][rt << 1|1]);
}

int query(int s, int rt, int left, int right, int l, int r) {
    if (left == l && r == right) {
        return tr[s][rt];
    }
    if (mid >= r)  return query(s, lson, l, r);
    else if (mid < l) return query(s, rson, l, r);
    else {
        if (s == 0) return max(query(s, lson, l, mid), query(s, rson, mid + 1, r));
        else return min(query(s, lson, l, mid), query(s, rson, mid + 1, r));
    }
}

void update(int w, int rt, int left, int right, int id, int val) {
    if (right == left && id == right) {
        if (w == 0) tr[w][rt] = max(tr[w][rt], val);
        else tr[w][rt] = min(tr[w][rt], val);
        return ;
    }
    if (mid >= id)  update(w, lson, id, val);
    else update(w, rson, id, val);
    push_up(w, rt);
}

int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < (N << 2); i++) tr[0][i] = -INF, tr[1][i] = INF;

    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        vec.push_back(a[i]);
        vec.push_back(b[i]);
        vec.push_back(c[i]);
        vec.push_back(d[i]);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int m = vec.size() + 4;
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
        b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin() + 1;
        c[i] = lower_bound(vec.begin(), vec.end(), c[i]) - vec.begin() + 1;
        d[i] = lower_bound(vec.begin(), vec.end(), d[i]) - vec.begin() + 1;
        intv[i] = ccc(a[i], b[i], c[i], d[i]);
        intw[i] = ccc(c[i], d[i], a[i], b[i]);
    }

    sort(intv, intv + n);
    sort(intw, intw + n);
    for (int i = 0; i < n; i++) {
        int r_end_min = query(1, 1, 1, m, intv[i].l, m);
        int l_end_max = query(0, 1, 1, m, intv[i].l, m);
        if (r_end_min < intv[i].x) {
            cout << "NO" << endl;
            return 0;
        }
        if (l_end_max > intv[i].y) {
            cout << "NO" << endl;
            return 0;
        }
        update(0, 1, 1, m, intv[i].r, intv[i].x);
        update(1, 1, 1, m, intv[i].r, intv[i].y);
    }
    for (int i = 0; i < (N << 2); i++) tr[0][i] = -INF, tr[1][i] = INF;
    for (int i = 0; i < n; i++) {
        int r_end_min = query(1, 1, 1, m, intw[i].l, m);
        int l_end_max = query(0, 1, 1, m, intw[i].l, m);
        if (r_end_min < intw[i].x) {
            cout << "NO" << endl;
            return 0;
        }
        if (l_end_max > intw[i].y) {
            cout << "NO" << endl;
            return 0;
        }
        update(0, 1, 1, m, intw[i].r, intw[i].x);
        update(1, 1, 1, m, intw[i].r, intw[i].y);
    }
    cout << "YES" << endl;
    return 0;
}

/*
6
7 10 12 16
8 11 13 17
3 6 7 11
1 5 2 9
2 4 5 8
9 12 14 18


*/