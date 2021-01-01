#include<bits/stdc++.h>

using namespace std;

double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    double x, y, x1, x2, y1, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(3);
    if (x1 <= x && x <= x2 && y >= y2) {
        cout << max(dis(x, y, x1, y2), dis(x, y, x2, y2)) << endl;
    } else if (x1 <= x && x <= x2 && y <= y1) {
        cout << max(dis(x, y, x1, y1), dis(x, y, x2, y1)) << endl;
    } else if (y1 <= y && y <= y2 && x <= x1) {
        cout << max(dis(x, y, x1, y2), dis(x, y, x, y2)) << endl;
    } else if (y1 <= y && y <= y2 && x >= x2) {
        
    } else if (x >= x2 && y >= y2){
    } else if (x <= x1 && y >= y1){
    } else if (x <= x1 && y >= y2){
    } else if (x >= x2 && y <= y1){
    }
    return 0;
}