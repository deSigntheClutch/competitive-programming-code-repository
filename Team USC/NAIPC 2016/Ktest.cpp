#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;


typedef long long Long;

struct Line
{
      Long a, b;
      Long get(Long x) {
            return a * x + b;
      }
};

struct ConvexHull
{
      int size;
      Line *hull;

      ConvexHull(int maxSize) {
            hull = new Line[++maxSize], size = 0;
      }

      bool is_bad(Long curr, Long prev, Long next) {
            Line c = hull[curr], p = hull[prev], n = hull[next];
            return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
      }

      void add_line(Long a, Long b) {
            hull[size++] = (Line)
            {
                  a, b
            };
            while (size > 2 && is_bad(size - 2, size - 3, size - 1))
                  hull[size - 2] = hull[size - 1], size--;
      }

      Long query(Long x) {
            for (int i = 0;i  < size; i++) {
                cout << hull[i].get(x) << " ";
            }
            cout << endl;
            int l = -1, r = size - 1;
            while (r - l > 1)
            {
                  int m = (l + r) / 2;
                  if (hull[m].get(x) <= hull[m + 1].get(x))
                        l = m;
                  else
                        r = m;
            }
            return hull[r].get(x);
      }
};

/*

7 744414 8 1183721 9 2167719  
11 593670  
10 433559  
3 911703 4 1503018 5 1775399 6 2380478 2 1108888  

*/
int main() {
    ConvexHull* ch = new ConvexHull(1111);


    ch->add_line(-22, -4);

    ch->add_line(-20, -6);
            ch->add_line(-10, -3);
        ch->add_line(-3, -41);
        ch->add_line(-1, -40);



     cout << ch->query(5) << endl;
    return 0;
}

/*

11
19690 143 90426 999326 505 952649 113975 11575 997464 985650 280863 
7 1 744414
4 3 591315
11 1 593670
10 1 433559
3 1 911703
8 7 439307
2 3 197185
5 4 272381
6 4 877460
9 8 983998

*/