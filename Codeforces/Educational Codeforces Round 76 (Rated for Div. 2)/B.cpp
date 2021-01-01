#include <bits/stdc++.h>
using namespace std;

long long x, y;

int main() {
    
    int T;
    cin >> T;
    while(T--) {
        cin >> x >> y;
        if (x > 3) cout << "yes" << endl;
        else {
            if ((x == 1 && y <= 1) || (x == 2 && y <= 3) || (x == 3 && y <= 3)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } 
    }
    return 0;
}