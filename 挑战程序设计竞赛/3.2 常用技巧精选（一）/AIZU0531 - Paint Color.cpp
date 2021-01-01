#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef pair<int, int> Point;
typedef pair<Point, Point> Rect;

Rect rec[13234];
int X[13234];
int Y[13345];
bool s[10022][10222];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int w, h;
int n;
int Xcnt, Ycnt;

void bfs(int xx, int yy)
{
    s[xx][yy] = true;
    queue<Point> q;
    q.push(mp(xx, yy));
    while(!q.empty())
    {
        Point u = q.front();
        q.pop();
        int x = u.f, y = u.s;

        for(int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 0 && tx < w && ty >= 0 && ty < h && s[tx][ty] == false)
            {
                s[tx][ty] = true;
                q.push(mp(tx, ty));
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin >> w >> h >> n)
    {
        if(w == 0 && h == 0) break;
        Xcnt = 0, Ycnt = 0;
        memset(X, 0, sizeof X);
        memset(Y, 0, sizeof Y);

        X[Xcnt++] = w, Y[Ycnt++] = h;
        X[Xcnt++] = 0, Y[Ycnt++] = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &rec[i].f.f, &rec[i].f.s, &rec[i].s.f, &rec[i].s.s);
            X[Xcnt++] = rec[i].f.f, X[Xcnt++] = rec[i].s.f;
            Y[Ycnt++] = rec[i].f.s, Y[Ycnt++] = rec[i].s.s;
        }

        sort(X, X + Xcnt);
        Xcnt = unique(X, X + Xcnt) - X;
        sort(Y, Y + Ycnt);
        Ycnt = unique(Y, Y + Ycnt) - Y;

        w = lower_bound(X, X + Xcnt, w) - X;
        h = lower_bound(Y, Y + Ycnt, h) - Y;

        for(int i = 0; i < n; i++)
        {
            rec[i].f.f = lower_bound(X, X + Xcnt, rec[i].f.f) - X;
            rec[i].s.f = lower_bound(X, X + Xcnt, rec[i].s.f) - X;
            rec[i].f.s = lower_bound(Y, Y + Ycnt, rec[i].f.s) - Y;
            rec[i].s.s = lower_bound(Y, Y + Ycnt, rec[i].s.s) - Y;
        }


        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                s[i][j] = false;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = rec[i].f.f; j < rec[i].s.f; j++)
            {
                for(int k = rec[i].f.s; k < rec[i].s.s; k++)
                {
                    s[j][k] = true;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                if(s[i][j] == false)
                {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
