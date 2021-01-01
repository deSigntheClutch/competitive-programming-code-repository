#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
int main() {
    int p,x,t;
    sd(p);
    while(p--){
        sd(t);sd(x);
        printf("%d %lld\n",t,(long long)x*(x+1)/2+x);
    }
    return 0;
}