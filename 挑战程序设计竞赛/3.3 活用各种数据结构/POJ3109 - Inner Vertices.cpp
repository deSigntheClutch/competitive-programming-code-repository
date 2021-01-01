#include<bits/stdc++.h>
using namespace std;
#define re real()
#define im imag()
#define pb push_back
#define mp make_pair

typedef complex<double> Point;
typedef Point Vector;
typedef vector<Point> Polygon;

int n, m, k;
Polygon po;

struct Poly
{
    Point ver;
    int id;
    double theta;
    bool operator < (struct Poly u) const
    {
        return theta < u.theta;
    }
} p[123456];

double qtheta[123456];

double cross(Point a, Point b)
{
    return (conj(a) * b).im;
}

bool check(Point u)
{
    int flag = 0;
    double th = atan2(u.im - p[0].ver.im, u.re - p[0].ver.re);
    int w = lower_bound(qtheta + 1, qtheta + n, atan2(u.im - p[0].ver.im, u.re - p[0].ver.re)) - qtheta;
    if(w == 0) return cross(u - p[0].ver, p[w].ver - p[0].ver) == 0;
    if(w == n) return 0;
    int v = w - 1;
    Point a = p[v].ver, b = p[w].ver, c = p[0].ver;

    if(cross(a - b, u - b) >= 0 && cross(c - a, u - a) >= 0 && cross(b - c, u - c) >= 0) return true;
    return false;
}

int main()
{
    printf("%.4f\n", cross(Point(-1, 0), Point(-1, -1)));
}

/*

8 6 3

-2 -2
2 2
-2 2
2 -2
2 0
0 -2
0 2
-2 0

2 0
3 0
1 0
-1 0
0 0
0.5 0.5



*/
