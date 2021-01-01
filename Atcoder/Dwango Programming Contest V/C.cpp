#include<bits/stdc++.h>
using namespace std;

int n;
string str;
int q, k;

vector<int> vecM, vecD, vecC;
vector<int> DnextC;

void init() {
    for (int i = 0; i < n; i++) {
        if (str[i] == 'D') {
            vecD.push_back(i);
        } else if (str[i] == 'M'){
            vecM.push_back(i);
        } else if(str[i] == 'C') {
            vecC.push_back(i);
        }
    }
}

long long solve() {
    int ptr = 0;
    int cur = -1;
    Queue<int> Q;
    for (int i = 0; i < vecM.size(); i++) {
        
        cur = vecM[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    init();
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        DnextC.clear();
        int ptr = 0;
        for (int j = 0; j < vecD.size(); j++) {
            if (ptr < vecD[j]) ptr = vecD[j];
            while (ptr < n && str[ptr] != 'C') ptr += 1;
            DnextC[j] = ptr;
        }
        cout << solve() << endl;
    }

    return 0;
}