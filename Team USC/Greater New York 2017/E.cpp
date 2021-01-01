#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n; 
int dp[N][N][2*N][N][N];
#define NINF -1

int rec(int r1, int r2, int t1, int t2, int t3){
    if(r1 < 0 || r2 < 0 || t1 < 0 || t2 < 0 || t3 < 0) return 0;
    int& v = dp[r1][r2][t1][t2][t3];
    if(v != NINF) return v;

    if(r1 == 0 && r2 == 0 && (t1 || t2 || t3)) return v = 0;

    //consider the top left point
    assert(abs(r1 - r2) <= 2);
    v = 0;


    //dot cases

    if(r1 >= r2){
        v += rec(r1-1, r2, t1-1, t2, t3);
    }

    if(r2 > r1){
        v += rec(r1, r2-1, t1-1, t2, t3);
    }

    //2x1 top hor
    if(r1 >= r2){
        v += rec(r1-2, r2, t1, t2-1, t3);
    }

    //2x1 bottom hor
    if(r2 > r1){
        v += rec(r1, r2-2, t1, t2-1, t3);
    }


    //vert 2x1
    if(r1 == r2){
        v += rec(r1-1, r2-1, t1, t2-1, t3);
    }

    if(r1 == r2){
        v += rec(r1-1, r2-2, t1, t2, t3-1);
    }

    //weird L
    if(r1 == r2){
        v += rec(r1-2, r2-2, t1-1, t2, t3-1);
    }

    if(r1 == r2+1){
        v += rec(r1-2, r2-1, t1, t2, t3-1);
    }

    if(r1 == r2){
        v += rec(r1-2, r2-1, t1, t2, t3-1);
    }

    if(r2 == r1 + 1){
        v += rec(r1-1, r2-2, t1, t2, t3-1);
    }
    return v;
}


int main() {
    cin>>n;
    assert(n <= N);

    memset(dp, NINF, sizeof(dp));
    dp[0][0][0][0][0] = 1;
    
    long long a0 = 0, a1 = 0, a2 =0, a3 = 0;

    for(int t1 = 0; t1 <= 2*n; t1++){
        for(int t2 = 0; t2 <= n; t2++){
            for(int t3 = 0; t3 <= n; t3++){
                int v = rec(n, n, t1, t2, t3);
                //cout<<"S: "<<t1<<" "<<t2<<" "<<t3<<" "<<v<<endl;
                a0 += v;
                a1 += v*t1;
                a2 += v*t2;
                a3 += v*t3;

            }
        }
    }

    cout<<a0<<" "<<a1<<" "<<a2<<" "<<a3<<endl;

}