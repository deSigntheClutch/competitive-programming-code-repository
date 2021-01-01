#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node {
    int f;
    int l, r;
    int val, cnt, sum;
} t[N];

int Q, root, cnt;

void pushup(int x) {
    if (x == -1) return;
    t[x].sum = t[x].cnt;
    if (t[x].l != -1) t[x].sum += t[t[x].l].sum;
    if (t[x].r != -1) t[x].sum += t[t[x].r].sum;
}

void create(int v, int fa) {
    if (t[fa].val > v) t[fa].l = cnt;
    else t[fa].r = cnt;
    t[cnt].l = t[cnt].r = -1;
    t[cnt].val = v, t[cnt].cnt = t[cnt].sum = 1;
    t[cnt++].f = fa;
}

void rightRotate(int x) {
    int y = t[x].f, z = t[y].f;
    t[y].l = t[x].r;
    if (t[x].r != -1) t[t[x].r].f = y;
    t[x].f = z;
    if (z != -1) {
        if (t[z].l == y) t[z].l = x;
        else t[z].r = x;
    }
    t[x].r = y, t[y].f = x;
    pushup(y), pushup(x);
}

void leftRotate(int x) {
    int y = t[x].f, z = t[y].f;
    t[y].r = t[x].l;
    if (t[x].l != -1) t[t[x].l].f = y;
    t[x].f = z;
    if (z != -1) {
        if (t[z].l == y) t[z].l = x;
        else t[z].r = x;
    }
    t[x].l = y, t[y].f = x;
    pushup(y), pushup(x);
}

void splay(int x) {
    while (t[x].f != -1) {
        int y = t[x].f, z = t[y].f;
        if (z == -1) {
            if (t[y].l == x) rightRotate(x);
            else leftRotate(x);
        } else {
            if (t[z].l == y && t[y].l == x) rightRotate(y), rightRotate(x);
            else if (t[z].l == y && t[y].r == x) leftRotate(x), rightRotate(x);
            else if (t[z].r == y && t[y].r == x) leftRotate(y), leftRotate(x);
            else rightRotate(x), leftRotate(x);
        }
    }
    root = x;
}

int find(int x) {
    int c = root;
    while(c != -1) {
        if(t[c].val == x) return t[c].cnt;
        else if(t[c].val > x) c = t[c].l;
        else c = t[c].r;
    }
    return 0;
}

void ins(int x) {
    if (root == -1) {
        create(x, -1);
        root = cnt - 1;
        return ;
    }
    int c = root;
    while (true) {
        if (t[c].val == x) {
            t[c].cnt++, t[c].sum++;
            splay(c);
            return;
        } else if (t[c].val > x) {
            if (t[c].l == -1) {
                create(x, c);
                break;
            } else c = t[c].l;
        } else {
            if (t[c].r == -1) {
                create(x, c);
                break;
            } else c = t[c].r;
        }
    }
    splay(cnt - 1);
}

void del(int c, int v) {
    if (t[c].val == v) {
        t[c].cnt--, t[c].sum--;
        return ;
    } else if (t[c].val > v) del(t[c].l, v);
    else del(t[c].r, v);
    pushup(c);
}

int Qrank(int x) {
    int c = root, res = 0;
    while (c != -1) {
        int vl = t[t[c].l].sum;
        if (t[c].l == -1) vl = 0;
        if (t[c].val == x) {
            return res + vl + 1;
        } else if (t[c].val > x) c = t[c].l;
        else res += vl + t[c].cnt, c = t[c].r;
    }
    return res + 1;
}

int Qx(int x) {
    int c = root;
    while (c != -1) {
        int vl = t[t[c].l].sum;
        if (t[c].l == -1) vl = 0;
        if (vl >= x) c = t[c].l;
        else if (x > vl + t[c].cnt) x -= vl + t[c].cnt, c = t[c].r;
        else return t[c].val;
    }
}

int Qfront(int x) {
    int u = Qrank(x);
    return Qx(u - 1);
}

int Qback(int x) {
    int u = Qrank(x);
    int v = Qx(u);
    if(v == x) return Qx(u + find(v));
    else return v;
}

int main() {
    root = -1, cnt = 0; //init
    scanf("%d", &Q);
    while (Q--) {
        int op, num;
        scanf("%d%d", &op, &num);
        if (op == 1) ins(num);
        else if (op == 2) del(root, num);
        else if (op == 3) printf("%d\n", Qrank(num));
        else if (op == 4) printf("%d\n", Qx(num));
        else if (op == 5) printf("%d\n", Qfront(num));
        else printf("%d\n", Qback(num));

    }
    return 0;
}