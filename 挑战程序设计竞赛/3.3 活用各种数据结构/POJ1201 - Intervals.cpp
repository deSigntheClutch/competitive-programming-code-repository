#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

struct intervals
{
    int l, r;
    int c;
    bool operator < (struct intervals u) const
    {
        return r < u.r;
    }
} inv[51111];

int vis[51111];
int node[51111 << 2];
int lazy[51111 << 2];
int n;

void pushup(int rt)
{
    node[rt] = node[rt << 1] + node[rt << 1 | 1];
}

void pushdown(int rt, int len)
{
    if(lazy[rt])
    {
        lazy[rt] = 0;
        lazy[rt << 1] = 1, lazy[rt << 1 | 1] = 1;
        node[rt << 1] = len - len / 2;
        node[rt << 1 | 1] = len / 2;
    }
}

void build(int rt, int left, int right)
{
    lazy[rt] = 0;
    if(left == right)
    {
        node[rt] = 0;
        return ;
    }
    build(lson);
    build(rson);
    pushup(rt);
}

int query(int rt, int left, int right, int l, int r)
{
    if(l == left && r == right)
    {
        return node[rt];
    }
    pushdown(rt, right - left + 1);
    if(r <= mid) return query(lson, l, r);
    else if(l > mid) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid + 1, r);
}

void update(int rt, int left, int right, int l, int r)
{
    if(l == left && r == right)
    {
        node[rt] = r - l + 1;
        lazy[rt] = 1;
        return ;
    }
    pushdown(rt, right - left + 1);
    if(r <= mid)  update(lson, l, r);
    else if(l > mid)  update(rson, l, r);
    else
    {
        update(lson, l, mid);
        update(rson, mid + 1, r);
    }
    pushup(rt);
}

int main()
{
    scanf("%d", &n);

    int L = 6666666, R = -1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &inv[i].l, &inv[i].r, &inv[i].c);
        inv[i].l++, inv[i].r++;
        L = min(L, inv[i].l);
        R = max(R, inv[i].r);
    }

    sort(inv + 1, inv + n + 1);
    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int l, r, v , md;
        r = inv[i].r;
        l = inv[i].l;
        v = inv[i].c - query(1, 1, R, l, r);
        if(v <= 0) continue;
        for(int j = 0; j < 20; j++)
        {
            md = (l + r) >> 1;
            if(inv[i].r - md + 1 - query(1, 1, R, md, inv[i].r) > v)
                l = md + 1;
            else
                r = md;
        }
        ans += v;
        update(1, 1, R, r, inv[i].r);
    }
    printf("%d\n", ans);

    return 0;
}

