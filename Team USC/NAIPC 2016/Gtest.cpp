#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const double pi = acos(-1.0);
const int N = 1e3 + 4;
const double eps = 1e-7;
 
struct Point2 {
    double x, y;
    bool operator < (Point2 b) const {
        if (fabs(x - b.x) < 1e-7) return y - b.y < -1e-7;
        return x - b.x < -1e-7;
    }
    bool operator == (struct Point2 b) const {
        return (fabs(x - b.x) < 1e-7) && (fabs(y - b.y) < 1e-7);
    }
};
 
struct Point {
    int x, y;
    void read(){
        cin >> x >> y;
    }
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    inline bool operator < (Point b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
    Point operator * (int d) const {
        return Point(d * x, d * y);
    }
    bool operator == (struct Point b) const {
        return x == b.x && y == b.y;
    }
    Point operator - (struct Point c) const {
        return Point(x - c.x, y - c.y);
    }
    Point operator + (struct Point c) const {
        return Point(x + c.x, y + c.y);
    }
    double sqr_norm() {
        return x*x + y*y;
    }
    double norm() {
        return sqrt(sqr_norm());
    }
    double dot(struct Point a, struct Point b) const {
        return a.x * b.x + a.y * b.y;
    }
    double cross(struct Point a, struct Point b) {
        return a.x * b.y - a.y * b.x;
    }
    // counter-clockwise
    // [cos,  sin]   [x]
    // [-sin, cos]   [y]
    void rotate(double theta) {
        double tx = x * cos(theta) - y * sin(theta);
        double ty = x * sin(theta) + y * cos(theta);
        x = tx, y = ty;
    }
};
 
typedef Point Vector;
 
int res;
int n;
Point p[N];
map<pair<int, int>, bool> used;
set<Point2> gen;
 
void calSymmetryPoint() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cx = (p[i].x + p[j].x);
            int cy = (p[i].y + p[j].y);
            int cnt = 0;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                if (2 * cx == p[k].x && 2 * cy == p[k].y) continue;
                pair<int, int> opposite_point = make_pair(cx - p[k].x, cy - p[k].y);
                if (used[opposite_point] == false) cnt += 1;
                if (cnt == res) break;
            }
            res = min(res, cnt);
        }
    }
}
 
void calSymmetryLine() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int A = 2 * (p[i].x - p[j].x);
            int B = 2 * (p[i].y - p[j].y);
            int C = -((p[i].x * p[i].x - p[j].x * p[j].x) + (p[i].y * p[i].y - p[j].y * p[j].y));
            int cnt = 0;
 
            if (A < 0) A = -A, B = -B, C = -C;
            else if (A == 0 && B < 0) B = -B, C = -C;
 
            long long base = (long long)A * A + (long long)B * B;
            int vx = p[i].x - p[j].x;
            int vy = p[i].y - p[j].y;
            long long len = (long long)vx * vx + (long long)vy * vy;
 
            if (vx < 0) vx = -vx, vy = -vy;
            else if (vx == 0 && vy < 0) vy = -vy;
 
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                long long up = (long long)A * p[k].x + (long long)B * p[k].y + C;
                double rate = 2.0 * abs(up) / sqrt(1.0 * base * len);
                if (up > 0) {
                    if (gen.find((Point2){p[k].x - vx * rate, p[k].y - vy * rate}) == gen.end()) cnt += 1;
                }
                else if (up < 0) {
                    if (gen.find((Point2){p[k].x + vx * rate, p[k].y + vy * rate}) == gen.end()) cnt += 1;
                }
                if (cnt == res) break;
            }
            res = min(res, cnt);
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i].read();
        used[make_pair(p[i].x, p[i].y)] = true;
        gen.insert((Point2){1.0 * p[i].x, 1.0 * p[i].y});
    }       
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }             
    res = n;
    calSymmetryPoint();
    calSymmetryLine();
    cout << res << endl;
    return 0;
}
 
/*
 
5
0 0
0 100
0 400
100 0
400 0
 
*/