#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

int main() {
    ios::sync_with_stdio(false);
    int P;
    cin >> P;
    while (P--) {
        int cs;
        int val;
        long double d;
        using ld=long double;
        cin >> cs >> val >> d;
        cout << cs << " ";
        int a = -1, b = -1;
        long double error=9e9,diff = 9e9;
        int x = 0;
        for (long double i = 1; i <= val; i++) {
            
            while(abs(ld(1+x)/i-d)<abs(ld(x)/i-d)){
                ++x;
            }

            //cout<<x<<' '<<i<<' '<<error<<endl;
            if(abs(ld(x)/i-d)<error){
                
                a=x;b=i;error=abs(ld(x)/i-d);
            //cout<<x<<' '<<i<<' '<<error<<endl;
            }
        }
        cout << a << "/" << b << endl;
    }
    return 0;
}

/*
3
1 100000 0.141592653589793238
2 255 0.141592653589793238
3 15 0.141592653589793238


1


*/