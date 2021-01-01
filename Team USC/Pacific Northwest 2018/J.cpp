#include<bits/stdc++.h>
using namespace std;
int slow,n,s,tmp;
int main(){
    scanf("%d%d",&n,&s);
    while(n--){
        scanf("%d",&tmp);
        slow=max(slow,tmp);
    }
    slow*=s;
    printf("%d\n",slow/1000+!!(slow%1000));
}