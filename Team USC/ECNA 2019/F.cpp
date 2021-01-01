#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);


    int n; cin>>n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
    }

    vector<int> alive(n);
    int pos = 0;
    for(int cnt = 0; cnt < n-1; cnt++){
        int rem = n - cnt;
        assert(alive[pos] == 0);
        int times = a[pos]%(rem);
        for(int i = 0; i < times; ){
            if(alive[pos] == 1){
                pos++;
                if(pos == n) pos = 0;
            }else{
                pos++;
                if(pos == n) pos = 0;

                i++;
            }
        }
        while(alive[pos] == 1){
            pos = (pos + 1)%n;
        }
        //cout<<"KIL:LED "<<pos+1<<endl;
        alive[pos] = 1;
        while(alive[pos] == 1){
            pos = (pos + 1)%n;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(alive[i] == 0) ans = i;
    }
    cout<<ans+1<<endl;
    
}