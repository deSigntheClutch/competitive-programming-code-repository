#include <bits/stdc++.h>
using namespace std;

const int N = 11;

char rowc[N][N+1];
char colc[N][N+1];

int ans[N][N];
int a[N][N];

bool finish = false;
bool row[N][N];
bool col[N][N];
bool range[3][3][N];

vector<pair<int, int>> order;

void dfs(int idx) {
    if (finish == true) return;
    if (idx >= (int)order.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) 
            {
                ans[i][j] = a[i][j];
            }
        }
        finish = true;
        return;
    }
    int x = order[idx].first;
    int y = order[idx].second;

    for (int i = 1; i <= 9; i++) {
        if (row[x][i] == true) continue;
        if (col[y][i] == true) continue;
        if (range[x / 3][y / 3][i] == true) continue;
        if (rowc[x][y] == '<'){
            if(i + a[x][y-1] >= 10) continue;   
        }
        else if (rowc[x][y] == '='){
            if(i + a[x][y-1] != 10) continue;   
        }
        else if (rowc[x][y] == '>'){
            if(i + a[x][y-1] <= 10) continue;   
        }

        if (colc[x][y] == '<'){
            if(i + a[x-1][y] >= 10) continue;   
        }
        else if (colc[x][y] == '='){
            if(i + a[x-1][y] != 10) continue;   
        }
        else if (colc[x][y] == '>'){
            if(i + a[x-1][y] <= 10) continue;   
        }


        a[x][y] = i;
        row[x][i] = true;
        col[y][i] = true;
        range[x / 3][y / 3][i] = true;
        dfs(idx + 1);
        row[x][i] = false;
        col[y][i] = false;
        range[x / 3][y / 3][i] = false;
        a[x][y] = 0;
    }
} 

int main() {
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            rowc[i][j] = 'A';
            colc[i][j] = 'A';
        }
    }

    for(int i = 0; i < 3; i++){
        string a, b, c, d, e; cin>>a>>b>>c>>d>>e;
        int cnt = 0;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                rowc[i*3][j*3 + k+1] = a[cnt++];
            }
        }

        cnt = 0;
        for(int k = 0; k < 9; k++){
            colc[i*3+1][k] = b[cnt++];
        }

        cnt = 0;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                rowc[i*3+1][j*3 + k+1] = c[cnt++];
            }
        }

        cnt = 0;
        for(int k = 0; k < 9; k++){
            colc[i*3+2][k] = d[cnt++];
        }

        cnt = 0;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                rowc[i*3+2][j*3 + k+1] = e[cnt++];
            }
        }
    }

    // for(int i = 0; i < 9; i++){
    //     for(int j = 0; j < 9; j++){
    //         cout<<rowc[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0; i < 9; i++){
    //     for(int j = 0; j < 9; j++){
    //         cout<<colc[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }




    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    order.push_back(make_pair(i * 3 + row, j * 3 + col));
                }
            }
        }
    }
    dfs(0);
    //cout << finish << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << ans[i][j] << " ";   
        }
        cout<<endl;
    }
    return 0;
}