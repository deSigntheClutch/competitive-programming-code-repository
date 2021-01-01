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

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ld> Point;
typedef Point Vector;

const double pi = acos(-1.0);
const double eps = 1e-12;

inline int sgn(double u)
{
      if(u > eps) return 1;
      else if(u < -eps) return -1;
      else return 0;
}

int a[5000 + 10], n, sum[5000 + 10];

int main()
{
      int ans = 0;
      scanf("%d", &n);
      f(i, 1, 1 + n)
      {
            char cha;
            scanf(" %c", &cha);
            if(cha == 'B') a[i] = 1, ans++;
            else a[i] = 0;
      }
      int Min = ans, mx = 1;
      f(i, 2, n + 1)
      {
            clr(sum);
            int cnt = 0;
            f(j, 1, n - i + 2)
            {
                  if(((sum[j - 1] - sum[max(0, j - i)]) & 1) ^ a[j] == 1)
                  {
                        sum[j]++;
                        cnt++;
                  }
                  sum[j] += sum[j - 1];
            }
            bool flag = true;
            f(j, n - i + 2, n + 1)
            {
                  if(((sum[j - 1] - sum[max(0, j - i)]) & 1) ^ a[j] == 1) flag = false;
                  sum[j] += sum[j - 1];
            }
            if(flag == false) continue;
            if(cnt < Min)
            {
                  Min = cnt;
                  mx = i;
            }
      }
      cout << mx _ Min << endl;
      return 0;
}



/*
10
F
F
F
F
F
F
F
F
F
B





*/
