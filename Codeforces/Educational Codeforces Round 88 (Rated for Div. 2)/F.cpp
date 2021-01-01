#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int n;

void rotate(double &x, double &y, double theta) {
    double tx = x * cos(theta) - y * sin(theta);
    double ty = x * sin(theta) + y * cos(theta);
    x = tx, y = ty;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        n <<= 1;
        double theta = 2.0 * pi / n; 
        double default_x = 0.0, default_y = .5 * tan(theta / 2);

        double max_x = default_x, max_y = default_y;
        double min_x = default_x, min_y = default_y;

        for (int i = 0; i < n; i++) {
            
            max_x = max(max_x, default_x);
            max_y = max(max_y, default_y);
            min_x = max(min_x, default_x);
            min_y = max(min_y, default_y);
        }
    }
    return 0;
}
