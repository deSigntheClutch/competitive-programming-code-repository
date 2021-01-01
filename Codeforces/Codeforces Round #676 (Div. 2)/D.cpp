#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 2e3 + 1;

int x[6] = {1, 0, -1, -1, 0, 1};
int y[6] = {0, -1, -1, 0, 1, 1};
int c[6];
int cc[6];
int tx, ty;

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
       cin >> tx >> ty;
       cin >> c[5] >> c[4] >> c[3] >> c[2] >> c[1] >> c[0];
       for (int  cs  = 0; cs < 1000; cs++) {
        for (int i = 0; i < 6; i++) {
            cc[(i + 1) % 6] = min(c[(i + 1) % 6], c[i] + c[(i + 2) % 6]);
        }
        for (int i = 0; i < 6; i++) {
            c[i] = cc[i];
        }
       }

       if (tx == 0) {
           if (ty > 0) {
               cout << c[4] * ty << endl;
           } else {
                cout << c[1] * abs(ty) << endl;
           }
       } else if (ty == 0){
           if (tx > 0) {
               cout << c[0] * tx << endl;
           } else {
                cout << c[3] * abs(tx) << endl;
           }
       } else {
           if (tx > 0 && ty > 0) {
               if (tx > ty) {
                   cout << ty * c[5] + c[0] * (tx - ty) << endl;
               } else {
                   cout << tx * c[5] + c[4] * (ty - tx) << endl;
               }
           } if (tx > 0 && ty < 0) {
            cout << tx * c[0] + abs(ty) * c[1] << endl;
           } if (tx < 0 && ty < 0) {
               if (tx < ty) {
                   cout << abs(ty) * c[2] + c[3] * (abs(tx) - abs(ty)) << endl;
               } else {
                   cout << abs(tx) * c[2] + c[1] * (abs(ty) - abs(tx)) << endl;
               }
           } if (tx < 0 && ty > 0) {
               cout << abs(tx) * c[3] + ty * c[4] << endl;
           }
       }
    }
    return 0;
}
