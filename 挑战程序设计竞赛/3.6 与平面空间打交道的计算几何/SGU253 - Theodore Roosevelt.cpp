#include<bits/stdc++.h>
using namespace std;
#define re real()
#define im imag()
#define pb push_back
#define mp make_pair

const double eps = 1e-9;
typedef complex<double> Point;
typedef Point Vector;
typedef vector<Point> Polygon;

vector<Point> qs;
int n, m, k , kk, len;
Point p[123456], bottom, v[123456];

int sgn(double u)
{
    if(u > eps) return 1;
    else if(u < -eps) return -1;
    else return 0;
}
double dot(Point a, Point b)
{
    return (conj(a) * b).re;
}

bool cmp(Point a, Point b)
{
    if(fabs(a.re - b.re) < eps) return a.im < b.im;
    else return a.re < b.re;
}

double cross(Point a, Point b)
{
    return (conj(a) * b).im;
}
bool cmp1(Point a, Point b)
{
    return sgn(cross(a, b)) > 0;
}

int ccw(Point a, Point b, Point c)
{
    Point t1 = b - a, t2 = c - a;
    if (cross(t1, t2) > 0)   return +1;       // counter clockwise
    if (cross(t1, t2) < 0)   return -1;       // clockwise
    if (dot(t1, t2) < 0)     return +2;       // c--a--b on line
    if (norm(t1) < norm(t2)) return -2;       // a--b--c on line
    return 0;
}
bool isintersaction(pair <Point, Point> a, pair <Point, Point> b)
{
    return (ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second) <= 0 && ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second) <= 0);
}

void convex_hull()
{
    k = 0;
    for(int i = 0; i < n; i++)
    {
        while(k > 1 && cross(qs[k - 1] - qs[k - 2], p[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = p[i];
    }
    for(int i = n - 2, t = k; i >= 0; i--)
    {
        while(k > t && cross(qs[k - 1] - qs[k - 2], p[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = p[i];
    }
}

bool check(Point u)
{
    Point t = u - bottom;
    if(u == bottom) return true;
    if(sgn(cross(t, v[0])) > 0) return false;
    if(sgn(cross(t, v[0])) == 0)
    {
        if(sgn(norm(v[0]) - norm(t)) >= 0 && sgn(dot(t, v[0])) >= 0) return true;
        else return false;
    }
    if(sgn(cross(t, v[len - 1])) < 0) return false;
    if(sgn(cross(t, v[len - 1])) == 0)
    {
        if(sgn(norm(v[len - 1]) - norm(t)) >= 0 && sgn(dot(t, v[len - 1])) >= 0) return true;
        else return false;
    }
    int l = 0, r = len - 1;
    int mid = (l + r) >> 1;

    for(int i = 0; i < 80; i++)
    {
        if(cmp1(t, v[mid])) r = mid;
        else l = 1 + mid;
        mid = (l + r) >> 1;
    }
    Point a[3];
    a[0] = bottom, a[1] = v[mid] + bottom, a[2] = v[mid - 1] + bottom;
    if(!(isintersaction(mp(a[1], a[2]), mp(a[0], u)))) return true;
    else
    {
        if(dot(u - a[1], a[2] - a[1]) >= 0 && cross(a[1] - u, a[2] - u) == 0) return true;
        else if(u == bottom) return true;
        else return false;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &kk);

    bottom = Point(0, 1e12);
    int se;

    for(int i = 0; i < n; i++)
    {
        Point t;
        scanf("%lf%lf", &t.re, &t.im);
        p[i] = t;
    }

    sort(p, p + n, cmp);
    qs.resize(2 * n);
    convex_hull();
    qs.resize(k - 1);

    for(int i = 0; i < qs.size(); i++)
    {
        Point t = qs[i];
        if(sgn(bottom.im - t.im) > 0 || (sgn(bottom.im - t.im) == 0 && sgn(bottom.re - t.re) > 0))
        {
            bottom = t;
            se = i;
        }
    }

    len = 0;
    for(int i = 0; i < qs.size(); i++)
    {
        if(qs[i] == bottom) continue;
        v[len++] = qs[i] - bottom;
    }

    sort(v, v + len, cmp1);

    int cnt = 0;

    for(int i = 0; i < m; i++)
    {
        Point t;
        scanf("%lf%lf", &t.re, &t.im);
        if(check(t)) cnt++;
    }
    if(cnt >= kk) puts("YES");
    else puts("NO");
    return 0;
}

/*

5 1 2
1 -1
1 2
0 4
-1 2
-1 -1
1 -4




*/
