#include<bits/stdc++.h>
using namespace std;
#define for0(i,j) for(int i=0;i<j;++i)
string rest[16];
struct Box;
vector<Box>valids[3][3];
struct Box{
    int x,y,v[3][3];
    void solve(int i,int j){
        if(i==3){
            valids[x][y].push_back(*this);
            return;
        }
        for(int t = 1; t<=9; t++) {
            v[i][j] = t;

        }
    }

}box[3][3];
int main(){
    for(int i=0;i<15;++i){
        cin>>rest[i];
    }
    for0(i,3) for0(j,3){
        box[i][j].x=i;
        box[i][j].y=j;
        box[i][j].solve(0,0);
    }

}