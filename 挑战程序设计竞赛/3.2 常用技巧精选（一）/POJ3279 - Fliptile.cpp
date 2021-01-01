#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<complex>
#include<utility>
#include<queue>
#include<map>

using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define im imag()
#define re real()
#define r(I, N) for(int I=0;I<N;I++)
#define f(I, A, B) for(int I=A;I<B;I++)
#define fd(I, A, B) for(int I=A;I>=B;I--)
#define ite(x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define sz(x) ((int)(x).size())
#define clr(x) memset(x, 0, sizeof(x))
#define _ << " " <<
#define nl cout << endl;
#define in(x, l, r) (l <= x && x <= r)

int n, m, a[20][20], b[20][20], mark[20][20], ans[20][20], dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

int main()
{
      ios::sync_with_stdio(false);
      int minimum = 10000;
      cin >> n >> m;
      r(i, n) r(j, m) cin >> a[i][j];
      r(i, 1 << m)
      {
            memset(mark, 0, sizeof mark);
            int cnt = 0;
            r(j, n) r(k, m) b[j][k] = a[j][k];
            r(j, m) if(i >> j & 1)
            {
                  cnt++;
                  mark[0][j] = 1;
            }
            r(j, m) if(mark[0][j])
            {
                  b[0][j] ^= 1;
                  r(k, 4)
                  {
                        int tx = 0 + dx[k], ty = j + dy[k];
                        if(in(tx, 0, n - 1) && in(ty, 0, m - 1)) b[tx][ty] ^= 1;
                  }
            }
            r(j, n - 1)
            {
                  r(k, m)
                  {
                        if(b[j][k] == 1)
                        {
                              mark[j + 1][k] = 1;
                              cnt++;
                              b[j + 1][k] ^= 1;
                              r(v, 4)
                              {
                                    int tx = j + 1 + dx[v], ty = k + dy[v];
                                    if(in(tx, 0, n - 1) && in(ty, 0, m - 1)) b[tx][ty] ^= 1;
                              }
                        }
                  }
            }
            bool flag = true;
            r(j, m) if(b[n - 1][j] == 1) flag = false;
            if(flag == false) continue;
            if(cnt < minimum)
            {
                  minimum = cnt;
                  r(j, n) r(k, m) ans[j][k] = mark[j][k];
            }
      }
      if(minimum == 10000) puts("IMPOSSIBLE");
      else r(i, n) r(j, m) printf("%d%c", ans[i][j], j == m - 1 ? '\n' : ' ');
      return 0;
}
