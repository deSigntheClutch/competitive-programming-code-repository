#include <bits/stdc++.h>
using namespace std;

int cross(int x, int y, int u, int w) {
    return x*w - y*u;
}

struct Point {
    int x, y;
    Point() {
        x=0, y=0;
    }
    Point (int a, int b) {
        x=a, y=b;
    }
    bool operator < (Point z) const {
        return cross(x, y, z.x, z.y) > 0;
    }
};

bool cmp(Point x, Point y) {
    return cross(x.x, x.y, y.x, y.y) > 0;
}

Point p[123];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    sort(p, p + n, cmp);
    int id = lower_bound(p, p + n, Point(-10001, 8)) - p;
    cout << id << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].x << " " << p[i].y << endl;
    }
    return 0;
}

/*
6
-1 1
-4 0
3 3
0 1
1 -9
-4 -1


*/
















