#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) {
    if (y < x) x = y;
}
template<typename T, typename U> static void rmax(T &x, U y) {
    if (x < y) x = y;
}

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const double eps = 1e-9;
const int N = 40 + 5;

inline int sgn(double x) {
    return fabs(x) < eps ? 0 : x > 0 ? 1 : -1;
}

inline int cmp(double x, double y) {
    return sgn(x - y);
}

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) {
        x = _x, y = _y;
    }
    Point operator + (const Point &b) const {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    Point operator * (const double &b) const {
        return Point(x * b, y * b);
    }
    Point operator / (const double &b) const {
        return Point(x / b, y / b);
    }
    double operator * (const Point &b) const {
        return x * b.x + y * b.y;
    }
    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
    bool operator == (const Point &b) const {
        return !cmp(x, b.x) && !cmp(y, b.y);
    }
    bool operator != (const Point &b) const {
        return cmp(x, b.x) || cmp(y, b.y);
    }
    inline double len() {
        return x * x + y * y;
    }
};

inline double dis(Point x, Point y) {
    return sqrt((x - y).len());
}

inline pair<Point, Point> Get(Point a, Point b) {
    Point c = (a + b) / 2, d = b - a;
    return mp(c, Point(c.x - d.y, c.y + d.x));
}

bool Check_Intersect(Point l1, Point r1, Point l2, Point r2) {
    return cmp((l2 - l1) ^ (r2 - l1), (l2 - r1) ^ (r2 - r1));
}

Point Get_Intersect(Point l1, Point r1, Point l2, Point r2) {
    double w1 = (l1 - l2) ^ (r2 - l2), w2 = (r2 - l2) ^ (r1 - l2);
    return (l1 * w2 + r1 * w1) / (w1 + w2);
}

int n;
Point p[N];

int main() {
    return 0;
}
