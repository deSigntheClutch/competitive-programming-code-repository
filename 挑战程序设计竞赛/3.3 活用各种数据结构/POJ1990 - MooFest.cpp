#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>
#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid+1, right
#define mp make_pair

using namespace std;

typedef long long ll;
ll sum[23456 << 2];
int node[23456 << 2];
int n;

struct wej
{
    int voi;
    int x;
    bool operator < (struct wej u) const
    {
        return voi < u.voi;
    }
} m[23456];

void pushup(int rt)
{
    node[rt] = node[rt << 1 | 1] + node[rt << 1];
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void Insert(int rt, int left, int right, int id)
{
    if(left == right && right == m[id].x)
    {
        sum[rt] += (ll)m[id].x;
        node[rt]++;
        return ;
    }
    if(m[id].x <= mid) Insert(lson, id);
    else if(m[id].x > mid) Insert(rson, id);
    pushup(rt);
}

pair<ll, int> query(int rt, int left, int right, int l, int r)
{
    if(l == left && r == right)
        return mp(sum[rt], node[rt]);
    if(r <= mid) return query(lson, l, r);
    else if(l > mid) return query(rson, l, r);
    else
    {
        pair<ll, int> t1, t2;
        t1 = query(lson, l, mid);
        t2 = query(rson, mid + 1, r);
        return mp(t1.first + t2.first, t1.second + t2.second);
    }
}

int main()
{
    scanf("%d", &n);
    int R = -1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &m[i].voi, &m[i].x);
        R = max(R, m[i].x);
    }
    sort(m + 1, m + 1 + n);
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        pair<ll, int> t1 = mp(0, 0), t2 = mp(0, 0);
        if(m[i].x - 1 >= 1) t1 = query(1, 1, R, 1, m[i].x - 1);
        if(m[i].x + 1 <= R) t2 = query(1, 1, R, m[i].x + 1, R);
        sum += (ll)m[i].voi * ( ((ll)t1.second * (ll)m[i].x - t1.first) + (t2.first - (ll)t2.second * (ll)m[i].x) );
        Insert(1, 1, R, i);
    }
    printf("%I64d\n", sum);
    return 0;
}
