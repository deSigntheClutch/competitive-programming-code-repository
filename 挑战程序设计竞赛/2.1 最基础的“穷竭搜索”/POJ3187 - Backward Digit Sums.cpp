#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[12];
int tmp[12];
int n,tar;

int cal()
{
    for(int i=1; i<=n; i++) tmp[i] = a[i];
    for(int i=0; i<n-1; i++)
    {

        for(int j=1; j<n-i; j++)
        {
            tmp[j] = tmp[j] + tmp[j+1];
           // printf("%d ",tmp[j]);
        }
        //printf("\n");
    }
    return tmp[1];
}

int main()
{
    while(~scanf("%d%d",&n,&tar))
    {
        for(int i=1; i<=n; i++) a[i] = i;
        while(cal() != tar)
            next_permutation(a+1,a+n+1);
        for(int i=1;i<n;i++) printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
