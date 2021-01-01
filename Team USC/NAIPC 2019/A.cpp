#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt<<1, left, mid
#define rson rt<<1|1, mid + 1, right

const int N = 3e3 + 4;
const double OFFSET = 20.0;

int n, k;
double x[N], y[N];

double cross(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

double get_area() {
    double area = 0;   // Accumulates area 
    int j = n - 1; 
    for (int i = 0; i < n; i++) { 
        area +=  (x[j] + x[i]) * (y[j] - y[i]); 
        j = i;  //j is previous vertex to i
    }
  return area / 2;
}

int gcd(int a, int b) {
    return (b > 0)? gcd(b, a % b) : a;
}

int main() {
    cout << gcd(3451, 1243) << endl;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double sum = fabs(get_area());
    cout << sum;
    return 0;
}