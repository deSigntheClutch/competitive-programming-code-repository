#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const double eps = 1e-7;
namespace DEBUG{

}
int a[N], v[N], dir[N];
int n, s;

bool check(double x) {
    int l = 0, r = (int)1e6 + 10;
    for (int i = 1; i <= n; i++) {
        double resR = 0.0;
        if (dir[i] == 1) {
            double L = 1.0 * (v[i] + s) * (a[i] - (v[i] + s) * x) / v[i];
            double R = 1.0 * (v[i] - s) * (a[i] - (v[i] + s) * x) / v[i];

        } else {
            double R = 1.0 * (v[i] + s) * ((int)(1e6 - a[i]) - (v[i] + s) * x) / v[i];
            double L = 1.0 * (v[i] - s) * ((int)(1e6 - a[i]) - (v[i] + s) * x) / v[i];
        }
        l = max(a[i])
    }
    return fabs(r - l - 1) > -eps;
}

int main() {
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i], &v[i], &dir[i]);
    }
    double l = 0, r = 1e9, md;
    for (int i = 0; i < 50; i++) {
        md = (l + r) * .5;
        if (check(md)) r = md;
        else l = md;
    }
    printf("%.9f\n", md);
    return 0;
}
