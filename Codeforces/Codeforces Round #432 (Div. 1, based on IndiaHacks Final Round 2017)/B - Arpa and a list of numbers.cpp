#include <bits/stdc++.h>
using namespace std;



int main() {
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    if(n == 1) {
        if(a[1] == 1) cout << min(x,y) << endl;
        else cout << 0 << endl;
        return 0;
    }
    return 0;
}
