#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<bitset>
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt<<1|1, mid+1, right

using namespace std;

const int MAXN = 4 * 1111;
const int MAXT = 55555;

int sum[MAXN][MAXN];
int n, q, tsum;
int X1[MAXT], X2[MAXT], Y1[MAXT], Y2[MAXT];
char OP[MAXT][2];

bitset<MAXN> node[MAXN];

void query_y(int rt, int left, int right, int rrt, int y1)
{
    if(node[rrt][rt]) tsum++;
    if(left == right && left == y1) return ;
    if(mid >= y1) return query_y(lson, rrt, y1);
    else if(mid < y1) return query_y(rson, rrt, y1);
}

void query_x(int rt, int left, int right, int x1, int y1)
{
    if(left == right && left == x1)
    {
        query_y(1, 1, n, rt, y1);
        return ;
    }
    query_y(1, 1, n, rt, y1);
    if(mid >= x1) return query_x(lson, x1, y1);
    else if(mid < x1) return query_x(rson, x1, y1);
}

void update_y(int rt, int left, int right, int rrt, int y1, int y2)
{
    if(left == y1 && y2 == right)
    {
        node[rrt][rt].flip();
        return ;
    }
    if(mid >= y2) update_y(lson, rrt, y1, y2);
    else if(mid < y1) update_y(rson, rrt, y1, y2);
    else
    {
        update_y(lson, rrt, y1, mid);
        update_y(rson, rrt, mid + 1, y2);
    }
}

void update_x(int rt, int left, int right, int x1, int x2, int y1, int y2)
{
    if(left == x1 && x2 == right)
    {
        update_y(1, 1, n, rt, y1, y2);
        return ;
    }
    if(mid >= x2) update_x(lson, x1, x2, y1, y2);
    else if(mid < x1) update_x(rson, x1, x2, y1, y2);
    else
    {
        update_x(lson, x1, mid, y1, y2);
        update_x(rson, mid + 1, x2, y1, y2);
    }
}

void solve_segment_tree()
{
    for(int i = 0; i <= (n << 2); i++)
        node[i].reset();

    for(int i = 1; i <= q; i++)
    {
        if(OP[i][0] == 'Q')
        {
            tsum = 0;
            query_x(1, 1, n, X1[i], Y1[i]);
            if(tsum & 1) puts("1");
            else puts("0");
        }
        else
            update_x(1, 1, n, X1[i], X2[i], Y1[i], Y2[i]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        if(Case > 1) puts("");
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= q; i++)
        {
            scanf("%s", OP[i]);
            if(OP[i][0] == 'Q')
                scanf("%d%d", &X1[i], &Y1[i]);
            else
                scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
        }
        solve_segment_tree();
    }
    return 0;
}
/*

1
2 7
C 2 1 2 2
C 2 1 2 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
C 1 1 2 1
Q 2 1

*/
