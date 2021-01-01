#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
bool isprime[1000008];
bool isp[1000009];
int prime[1000008];
int real[1000008];
int l;
int ans[1000009];

void sieve()
{
      for(int i = 5; i <= 1000007; i += 4)
            isprime[i] = true;


      for(int i = 5; i <= 1000007; i += 4)
      {
            if(!isp[i])
            {
                  for(int j = 2 * i; j <= 1000007; j += i)
                  {
                        isp[j] = true;
                  }
            }
      }
      for(int i = 0; i <= 1000007; i++) if(isprime[i] && !isp[i]) prime[l++] = i;
      for(int i=0;i<l;i++)
      {
            for(int j=i;j<l;j++)
            {
                  if(1000007 / prime[i] < prime[j]) break;
                  int t = prime[i] * prime[j];
                  ans[t] = 1;
            }
      }
      for(int i = 1; i <= 1000007; i++) ans[i] += ans[i - 1];
}

int main()
{
      sieve();
      while(~scanf("%d", &n), n) printf("%d %d\n", n, ans[n]);
      return 0;
}
