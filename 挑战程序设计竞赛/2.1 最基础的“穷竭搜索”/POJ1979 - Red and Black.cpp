#include<cstdio>
#include<cstring>

int count;
char map[100][100];
int vis[100][100];
int move[4][2]={1,0,0,-1,-1,0,0,1};

void dfs(int x,int y,int xm,int ym)
{
    int i,j;

    vis[y][x]=1;
    count ++;

    for(i=0;i<4;i++)
    {
        if(x+move[i][0]>=0 && x+move[i][0]<xm && y+move[i][1]>=0 && y+move[i][1]<ym && map[y+move[i][1]][x+move[i][0]]!='#'&&vis[y+move[i][1]][x+move[i][0]]==0)
            dfs(x+move[i][0],y+move[i][1],xm,ym);
    }
}

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b)&&a!=0&&b!=0)
    {
        int i,j;
        int sx,sy;

        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));

        getchar();

        for(i=0;i<b;i++)
        {
             for(j=0;j<a;j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='@')
                {
                    sx=j;
                    sy=i;
                }
            }
             getchar();
        }
        count = 0;
        dfs(sx,sy,a,b);
        printf("%d\n",count);
    }
    return 0;
}
