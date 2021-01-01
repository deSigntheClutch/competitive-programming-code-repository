#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m,l,cnt,mx,my;
char a[1009][1009];
int vis[1009][1009];
pair<int,int> p[10],st;
int mov[4][2] = {1,0,0,-1,-1,0,0,1};
struct status
{
    int x,y;
    int ord;
    int fx;
    status(int a=0,int b=0,int c=0,int s=0)
    {
        x = a, y = b, ord = c, fx = s;
    }
    bool operator < (struct status t) const
    {
        if(ord != t.ord) return ord > t.ord;
        else return fx > t.fx;
    }
}tt[4];

void bfs(int x,int y,int color)
{
    queue <struct status> q;
    struct status temp(x,y,0,fabs(x-p[color].first) + fabs(y - p[color].second));
    q.push(temp);
    int flag = 0;
    while(!q.empty())
    {
        struct status nw = q.front();
        q.pop();
        if(nw.x == p[color].first && nw.y == p[color].second)
        {
            cnt += nw.ord;
            break;
        }
        vis[nw.x][nw.y] = 1;
        int cct = 0;
        for(int i=0;i<4;i++)
        {
            int tx = mov[i][0] + nw.x, ty = nw.y + mov[i][1];
            if(tx>=0 && tx< n && ty>=0 && ty< m && !vis[tx][ty] && a[tx][ty] != 'X')
            {
                struct status tmp(tx,ty,nw.ord+1,fabs(tx-p[color].first) + fabs(ty - p[color].second));
                tt[cct++] = tmp;
                vis[tx][ty] = 1;
            }
        }
        sort(tt,tt+cct);
        for(int i=0;i<cct;i++) q.push(tt[i]);
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&l))
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&a[i][j]);
                if(a[i][j]>='0' && a[i][j]<='9')
                    p[a[i][j]-'0'].first = i, p[a[i][j]-'0'].second = j;
                if(a[i][j] == 'S') st.first = i, st.second = j;
            }
            getchar();
        }

        int sx = st.first, sy = st.second;
        cnt = 0;
        for(int i=1;i<=l;i++)
        {
            memset(vis,0,sizeof(vis));
            bfs(sx,sy,i);
            sx = p[i].first, sy = p[i].second;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*


入力例 1
3 3 1
S..
...
..1

出力例 1
4


入力例 2
4 5 2
.X..1
....X
.XX.S
.2.X.

出力例 2
12


入力例 2
10 10 9
.X...X.S.X
6..5X..X1X
...XXXX..X
X..9X...X.
8.X2X..X3X
...XX.X4..
XX....7X..
X..X..XX..
X...X.XX..
..X.......

出力例 2
91

*/
