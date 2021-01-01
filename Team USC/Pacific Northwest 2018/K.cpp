#include<bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
//first compute transtitions

//then compute probabilities
double dice[13];

void compDice(){
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            dice[i+j]++;
        }
    }
    for(int i = 0; i < 13; i++){
        dice[i] /= 36.00;
    }
}


vector<vector<int>> trans;

void compTrans(){
    trans.resize(13);
    for(int i = 1; i < (1<<9); i++){
        int sum = 0;
        for(int j = 0; j < 9; j++){
            if((1<<j)&i) sum += (j+1);
        }

        if(sum <= 12 && sum >= 1) trans[sum].push_back(i);
    }


    // for(int i = 1; i < 13; i++){
    //     cout<<"TR: "<<trans[i].size()<<endl;
    // }

}


double high[1<<9];
double low[1<<9];

int concat(int mask){
    int ret = 0;
    for(int i = 0; i < 9; i++){
        if((1<<i)&(mask)){
            ret = ret*10 + (i + 1);
        }
    }
    return ret;
}

double recHigh(int mask){
    if(high[mask] != -1) return high[mask];
    high[mask] = 0;
    //cout<<"COMP: "<<mask<<endl;
    for(int d = 1; d <= 12; d++){
        bool found = 0;
        double best = 0;
        for(int tr: trans[d]){
            if((mask|tr) != mask) continue;
            best = max(best, recHigh(mask & (~tr)));
            found = 1;
        }
        if(found)
            high[mask] += dice[d]*best;
        else high[mask] += dice[d]*concat(mask);
    }
    return high[mask];
}

double recLow(int mask){
    if(low[mask] != -1) return low[mask];
    low[mask] = 0;
    //cout<<"COMP: "<<mask<<endl;
    for(int d = 1; d <= 12; d++){
        bool found = 0;
        double best = 1e15;
        for(int tr: trans[d]){
            if((mask|tr) != mask) continue;
            best = min(best, recLow(mask & (~tr)));
            found = 1;
        }
        if(found)
            low[mask] += dice[d]*best;
        else low[mask] += dice[d]*concat(mask);
    }
    return low[mask];
}



signed main(){
    for(int i = 0; i < (1<<9); i++){
        high[i] = -1;
        low[i] = -1;
    }

    compDice();
    compTrans();

    string s; int a1, a2; cin>>s>>a1>>a2;
    int mask = 0;
    for(int i = 0; i < s.length(); i++){
        mask |= 1<<(s[i] - '1');
    }

    //cout<<mask<<endl;


    {
        int d = a1 + a2;
        double bestL = 1e15;
        int  bestLM = 0;
        bool found = 0;
        for(int tr: trans[d]){
            if((mask|tr) != mask) continue;
            //cout<<"TR: "<<tr<<endl;
            double temp = recHigh(mask & (~tr));
            if(temp < bestL){
                bestL = temp;
                bestLM = tr;
            }
            found = 1;
        }
        if(found == 0) bestL = concat(mask);

        if(found) cout<<(int)concat(bestLM)<<" ";

        else cout<<-1<<" ";
        cout<<fixed<<setprecision(5);
        
        cout<<bestL<<endl;

    }

    {
        int d = a1 + a2;
        double bestH = 0, bestL = 1e15;
        int bestHM = 0, bestLm = 0;
        bool foundH = 0;
        for(int tr: trans[d]){
            if((mask|tr) != mask) continue;
            //cout<<"TR: "<<tr<<endl;
            double temp = recHigh(mask & (~tr));
            if(temp > bestH){
                bestH = temp;
                bestHM = tr;
            }
            foundH = 1;
        }
        if(foundH == 0) bestH = concat(mask);

        cout<<fixed<<setprecision(0);
        if(foundH) cout<<(int)concat(bestHM)<<" ";
        else cout<<-1<<" ";
        cout<<fixed<<setprecision(5);
        cout<<bestH<<endl;

    }
    

}