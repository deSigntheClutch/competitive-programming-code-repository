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
#include<iomanip>

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
#define mid ((left + right) >> 1)
#define lson rt<<1,left,mid
#define rson rt<<1|1,mid+1,right

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ld> Point;
typedef Point Vector;

const double pi = acos(-1.0);
const double eps = 1e-12;
const int N = 10000 + 10;

inline int sgn(double u)
{
      if(u > eps) return 1;
      else if(u < -eps) return -1;
      else return 0;
}

int n, c;
pair<double, double> a[(N << 2) + 10];
int thet[(N << 2) + 10];
int lazy[(N << 2) + 10];

void pushup(int rt)
{
      a[rt] = mp(a[rt << 1].fi + a[rt << 1 | 1].fi, a[rt << 1].se + a[rt << 1 | 1].se);
}

void init(int rt, int left, int right)
{
      if(left == right)
      {
            double tmp;
            cin >> tmp;
            a[rt] = mp(0, tmp);
            return;
      }
      init(lson);
      init(rson);
      pushup(rt);
}

void pushdown(int rt)
{
      if(lazy[rt])
      {
            int theta = lazy[rt];
            lazy[rt<<1] += theta;
            lazy[rt<<1|1] += theta;
            lazy[rt] = 0;
            double tx = a[rt<<1].fi*cos(pi * theta/180) + a[rt<<1].se*sin(pi * theta/180), ty = -a[rt<<1].fi*sin(pi * theta/180) + a[rt<<1].se*cos(pi * theta/180);
            a[rt<<1] = mp(tx, ty);
            tx = a[rt<<1|1].fi*cos(pi * theta/180) + a[rt<<1|1].se*sin(pi * theta/180), ty = -a[rt<<1|1].fi*sin(pi * theta/180) + a[rt<<1|1].se*cos(pi * theta/180);
            a[rt<<1|1] = mp(tx, ty);
      }
}

void rotate(int rt, int left, int right, int l, int r, int theta)
{
      if(l == left && right == r)
      {
            lazy[rt] += theta;
            double tx = a[rt].fi*cos(pi * theta/180) + a[rt].se*sin(pi * theta/180), ty = - a[rt].fi*sin(pi * theta/180) + a[rt].se*cos(pi * theta/180);
            a[rt] = mp(tx, ty);
            return;
      }
      pushdown(rt);
      if(mid >= r) rotate(lson, l, r, theta);
      else if(mid < l) rotate(rson, l, r, theta);
      else rotate(lson, l, mid, theta), rotate(rson, mid + 1, r, theta);
      pushup(rt);
}

int main()
{
      ios::sync_with_stdio(false);
      int tt = 0;
      while(cin >> n >> c)
      {
            memset(lazy, 0, sizeof lazy);
            r(i, n + 1) thet[i] = 180;
            if(tt++) nl
            init(1, 1, n);
            f(i, 1, 1 + c)
            {
                  int t, theta, temp;
                  cin >> t >> theta;
                  temp = theta;
                  theta = thet[t] - theta;
                  thet[t] = temp;
                  rotate(1, 1, n, t + 1, n, theta);
                  printf("%.2f %.2f\n", (sgn(a[1].fi) == 0 ? 0 : a[1].fi), (sgn(a[1].se) == 0 ? 0 : a[1].se));
            }
      }
      return 0;
}



