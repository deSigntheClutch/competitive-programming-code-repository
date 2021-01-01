#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[12],b[12],vis[12];
int len,l1,l2;
int ans;

void convert(int s,int e,int &res)
{
    res = 0;
    int cnt = 1;
    for(int i=e; i>=s; i--)
    {
        if(b[i]==-1) break;
        res += cnt*b[i];
        cnt *= 10;
    }
}

void dfs(int s,int e)
{

    if(s == e)
    {
        int t1,t2;
        convert(0,l1-1,t1),convert(l1,len-1,t2);
        //printf("%d %d\n",t1,t2);
        ans = min(ans,(int)fabs((double)t1-t2));
        return;
    }

    for(int i=0; i<len; i++)
    {
        if(!vis[i])
        {
            if(a[i]==0)
            {
                if(s != 0 && s!= l1)
                    b[s] = a[i];
            }
            else
                b[s] = a[i];
            if(b[s]!= -1)
            {

                vis[i] = 1;
                dfs(s+1,e);
                vis[i] = 0;
                b[s] = -1;
            }

        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char op;
        len = 0;
        while(~scanf("%d%c",&a[len++],&op)) if(op=='\n') break;

        sort(a,a+len);
        if(len==10)
            printf("247\n");
        else if(len == 2)
            printf("%d\n",a[1]-a[0]);
        else
        {

            if(len%2)
            {
                if(a[0] == 0) swap(a[0],a[1]);
                int l1 = 0, tmp = 1;
                for(int i=len/2; i>=0; i--)
                    l1 += tmp*a[i], tmp *= 10;
                int l2 = 0;
                tmp = 1;
                for(int i=len/2+1; i<len; i++)
                    l2 += tmp*a[i], tmp *= 10;
                printf("%d\n",l1-l2);
            }
            else
            {
                memset(b,-1,sizeof(b));
                memset(vis,0,sizeof(vis));
                l1 = len/2, l2 = len - len/2;
                ans = 99999999;
                dfs(0,len);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
/*#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[12],b[12],vis[12];
int len,l1,l2;
int ans;

void convert(int s,int e,int &res)
{
    res = 0;
    int cnt = 1;
    for(int i=e; i>=s; i--)
    {
        if(b[i]==-1) break;
        res += cnt*b[i];
        cnt *= 10;
    }
}

void dfs(int s,int e)
{

    if(s == e)
    {
        int t1,t2;
        convert(0,l1-1,t1),convert(l1,len-1,t2);
        //printf("%d %d\n",t1,t2);
        ans = min(ans,(int)fabs((double)t1-t2));
        return;
    }

    for(int i=0; i<len; i++)
    {
        if(!vis[i])
        {
            if(a[i]==0)
            {
                if(s != 0 && s!= l1)
                    b[s] = a[i];
            }
            else
                b[s] = a[i];
            if(b[s]!= -1)
            {

                vis[i] = 1;
                dfs(s+1,e);
                vis[i] = 0;
                b[s] = -1;
            }

        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char op;
        len = 0;
        while(~scanf("%d%c",&a[len++],&op)) if(op=='\n') break;
        memset(b,-1,sizeof(b));
        memset(vis,0,sizeof(vis));
        l1 = len/2, l2 = len - len/2;
        ans = 99999999;
        dfs(0,len);
        printf("%d\n",ans);
    }
    return 0;
}
*/

