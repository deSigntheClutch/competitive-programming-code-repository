#include <bits/stdc++.h>
using namespace std;
 
#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right
 
typedef long long ll;
 
const int N = 11;
const int M = 1e5 + 10;
 
int n, m, q;
 
struct Node {
    int cnt;
    vector<int> fa_l, fa_r;
    Node() {
        cnt = 0;
        fa_l = vector<int> (n, 0);
        fa_r = vector<int> (n, 0);
    }
    void print() {
        for (int x : fa_l) {
            cout << x << " ";
        }
        cout << endl;
        for (int x : fa_r) {
            cout << x << " ";
        }
        cout << endl;
    }
};
 
Node t[M << 2];
int length = 0;
int board[N][M], fa[M], ss[M];
 
int get(int x) {
    if (fa[x] != x) return fa[x] = get(fa[x]); 
    return fa[x];
}
 
Node merge(Node xa, Node xb, int md) {
    Node res;
    // init_union_set
    bool flag = true;
    if (xb.cnt ==  1) flag = false;
    for (int i = 0; i < n; i++) {
        fa[i] = xa.fa_l[i];
        fa[i + n] = xa.fa_r[i];
    }
    for (int i = 0; i < n; i++) {
        fa[2 * n + i] = xb.fa_l[i] + 2 * n;
        fa[3 * n + i] = xb.fa_r[i] + 2 * n;
    }
    int total = xa.cnt + xb.cnt;
    for (int i = 0; i < n; i++) {
        if (board[i + 1][md] == board[i + 1][md + 1]) {
            int u = get(n + i), v = get(2 * n + i);
            if (u != v) {
                if (u > v) swap(u, v);
                fa[v] = u;
                total -= 1;
            }
        }
    }
    res.cnt = total;
    for (int i = 0; i < 4 * n; i++) ss[i] = 0;
    for (int i = 0; i < n; i++) {
        int u = get(fa[i]);
        if (ss[u] == 0) {
            ss[u] = i + 1;
        }
        res.fa_l[i] = ss[u] - 1;
    }
    for (int i = 0; i < n; i++) {
        int u = get(fa[3 * n + i]);
        if (ss[u] == 0) {
            ss[u] = n + i + 1;
        }
        res.fa_r[i] = ss[u] - 1;
    }
    return res;
}
 
void build(int rt, int left, int right) {
    t[rt] = Node();
    if (left == right) {
        t[rt].cnt = n;
        for (int i = 0; i < n; i++) {
            if (i > 0 && board[i + 1][left] == board[i][left]) {
                t[rt].fa_l[i] = t[rt].fa_l[i - 1];
                t[rt].cnt -= 1;
                continue;
            }
            t[rt].fa_l[i] = i;
        }
        for (int i = 0; i < n; i++) {
            t[rt].fa_r[i] = t[rt].fa_l[i];
        }
        return ;    
    }
    build(lson), build(rson);
    t[rt] = merge(t[rt << 1], t[rt << 1 | 1], mid);
}
 
Node query(int rt, int left, int right, int l, int r) {
  if (left == l && r == right) return t[rt];
  if (mid >= r) return query(lson, l, r);
  else if (mid < l) return query(rson, l, r);
  else return merge(query(lson, l, mid), query(rson, mid + 1, r), mid);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    build(1, 1, m);
    map<pair<int, int>, int> answer;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        if (answer[{l, r}] != 0) {
            cout << answer[{l, r}] << endl;
        } else {
            int ans = query(1, 1, m, l, r).cnt;
            cout << ans << endl;
            answer[{l, r}] = ans;
        }
    }
    return 0;
}