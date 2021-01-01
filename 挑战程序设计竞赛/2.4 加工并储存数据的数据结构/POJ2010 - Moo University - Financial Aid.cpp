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

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ld> Point;
typedef Point Vector;

const double pi = acos(-1.0);
const double eps = 1e-12;

inline int sgn(double u) {
  if(u > eps) return 1;
  else if(u < -eps) return -1;
  else return 0;
}

struct Pair {
  int s, f;
  bool operator < (struct Pair u) const {
    if(s != u.s) return s < u.s;
    else return f > u.f;
  }
} p[100000 + 10];

int n, c;
ll f;

struct cmp {
  bool operator() (Pair a, Pair b) {
    if(a.f != b.f) return a.f < b.f;
    else return a.s > b.s;
  }
};

priority_queue<Pair, vector<Pair>, cmp> heap;
ll prefix[100000 + 10], suffix[100000 + 10];

int main() {

  ios::sync_with_stdio(false);
  cin >> n >> c >> f;
  f(i, 1, 1 + c) cin >> p[i].s >> p[i].f;
  sort(p + 1, p + 1 + c);
  n /= 2;

  if(n == 0) {
    ll mx = -1;
    for(int i = 1; i <= c; i++) {
      if(p[i].f <= f) {
        if(mx < p[i].s) {
          mx = p[i].s;
        }
      }
    }
    cout << mx << endl;
    return 0;
  }

  ll cost = 0;
  for(int i = c; i >= 1; i--) {
    if(heap.size() == n) {
      if(heap.top().f > p[i].f) {
        cost -= (heap.top().f - p[i].f);
        heap.pop();
        heap.push(p[i]);
      }
    } else heap.push(p[i]), cost += p[i].f;
    suffix[i] = cost;
  }

  while(!heap.empty()) heap.pop();
  cost = 0;

  for(int i = 1; i <= c; i++) {
    if(heap.size() == n) {
      if(heap.top().f > p[i].f) {
        cost -= (heap.top().f - p[i].f);
        heap.pop();
        heap.push(p[i]);
      }
    } else heap.push(p[i]), cost += p[i].f;
    prefix[i] = cost;
  }
  ll mx = -1;
  for(int i = 1 + n; i <= c - n; i++) {
    ll tmp = prefix[i - 1] + suffix[i + 1] + p[i].f;
    if(tmp <= f) {
      if(mx < p[i].s) {
        mx = p[i].s;
      }
    }
  }
  cout << mx << endl;
  return 0;
}

/*

1 5 70
30 25
50 21
20 20
5 18
35 30

*/


