#include<cstdio>
#include<cstring>
#include<complex>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
#define re real()
#define im imag()

const double eps = 1e-10;
const double pi = acos(-1.0);
typedef complex<double> Point;
typedef complex<double> Vector;

Point p[333];
int n;

struct Angle
{
    double theta;
    int type;
    bool operator < (struct Angle u) const
    {
        return theta < u.theta;
    }
} ag[1111];
int lag;

void _rotate(double &x, double &y, double theta)
{
    double tx = x, ty = y;
    x = cos(theta) * tx - sin(theta) * ty;
    y = sin(theta) * tx + cos(theta) * ty;
}

int sgn(double u)
{
    if(u > eps) return 1;
    else if(u < -eps) return -1;
    else return 0;
}

int get(int a)
{
    int res = 0;
    lag = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == a) continue;
        Vector ab = p[i] - p[a], am, an;
        am = ab, an = ab;
        if(sgn(sqrt(norm(ab)) - 2.0) > eps) continue;
        double l_ab = sqrt(norm(ab)), theta = acos(l_ab * 0.5), l, r;
        double lq = atan2(ab.im, ab.re);
        l = -theta + lq;
        r = theta + lq;
        if(sgn(r - l) < 0) swap(l, r);
        ag[lag++] = (Angle) { l, 1 };
        ag[lag++] = (Angle) { r, -1 };
    }

    sort(ag, ag + lag);
    int tmp = 0;
    for(int i = 0; i < lag ; i++)
    {
        if(ag[i].type == 1) tmp++;
        else if(ag[i].type == -1) tmp--;
        res = max(res, tmp);
    }
    return res + 1;
}

int main()
{
    while(~scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            cin >> p[i].re >> p[i].im;

        int ans = 1;
        for(int i = 0; i < n; i++)
            ans = max(ans, get(i));

        printf("%d\n", ans);
    }
    return 0;
}
/*

6
0 0
1 0
1 1
0 1
2 2
3 3


*/
