#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

char grid[N][N];
int r, c;

bool check(int type, int id) {
    if (type == 0) {
        for (int i = 1; i <= c; i++) {
            if (grid[id][i] == 'P') {
                return false;
            }
        }
        return true;
    } else {
        for (int i = 1; i <= r; i++) {
            if (grid[i][id] == 'P') {
                return false;
            }
        }   
        return true;
    }
}

bool check0() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == 'P')
                return false;
        }
    }
    return true;
}

bool checkm() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (grid[i][j] == 'A')
                return false;
        }
    }
    return true;
}

bool check1() {
    if (check(0, 1) || check(0, r) || check(1, 1) || check(1, c)) return true;
    else return false;
}

bool check2() {
    for (int i = 2; i < r; i++) {
        if (check(0, i)) 
            return true;
    }
    for (int i = 2; i < c; i++) {
        if (check(1, i)) 
            return true;
    }
    if (grid[1][1] == 'A' || grid[1][c] == 'A' || grid[r][1] == 'A' || grid[r][c] == 'A') return true;
    return false;
}

bool check4() {
    for (int i = 1; i <= c; i++) {
        if (grid[r][i] == 'A' || grid[1][i] == 'A') return false;
    }
    for (int i = 1; i <= r; i++) {
        if (grid[i][1] == 'A' || grid[i][c] == 'A') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            cin >> (grid[i] + 1);
        }
        // 0
        if (check0()) cout << 0 << endl;
        // Mortal
        else if (checkm()) cout << "MORTAL" << endl;
        // 1
        else if (check1()) cout << 1 << endl;
        // 2
        else if (check2()) cout << 2 << endl;
        // 4
        else if (check4()) cout << 4 << endl;
        // 3    
        else cout << 3 << endl;
    }
    return 0;
}