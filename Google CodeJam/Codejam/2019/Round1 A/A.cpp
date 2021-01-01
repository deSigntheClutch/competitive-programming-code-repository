#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void print(int x, int y, bool sig) {
    if (sig == false) cout << y << " " << x << endl;
    else cout << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": ";
        int r, c;
        cin >> r >> c;
        bool ff = true;
        if (r > c) {
            swap(r, c);
            ff = false;
        }
        if (c >= 5) {
        
            cout << "POSSIBLE" << endl; 
            if (r % 2 == 0) {
                if (c & 1) {
                    for (int i = 1; i <= r; i += 2) {
                        for (int j = 1; j <= c; j++) {
                            if (j <= c / 2) {
                                print(i, j, ff);
                                print(i+1, (c+1) / 2 + j, ff);
                            } else {
                                print(i, j, ff);
                                print(i+1,  j - c / 2, ff);
                            }
                        }
                    }
                } else {
                    for (int i = 1; i <= r; i += 2) {
                        for (int j = 1; j <= c; j++) {
                            if (j <= c / 2) {
                                print(i, j, ff);
                                print(i + 1, c / 2 + j,ff);
                            } else {
                                print(i, j, ff);
                                print(i + 1, j - c / 2, ff);
                            }
                        }
                    }
                }
            } else {
                if (c & 1) {
                    for (int i = 1; i <= r; i += 2) {
                        if (i + 2 == r) {
                            for (int j = 1; j <= c; j++) {
                                if (j <= c / 2) {
                                  print(i, j, ff);
                                print(i+1, (c+1) / 2 + j, ff);
                                    print(i + 2, j, ff);
                                } else {
                                         print(i, j, ff);
                                print(i+1,  j - c / 2, ff);
                                    print(i + 2, j, ff);
                                }
                            }
                            break;
                        }
                        for (int j = 1; j <= c; j++) {
                            if (j <= c / 2) {
                                  print(i, j, ff);
                                print(i+1, (c+1) / 2 + j, ff);
                            } else {
                                print(i, j, ff);
                                print(i+1,  j - c / 2, ff);
                            }
                        }
                    }
                } else {
                    for (int i = 1; i <= r; i += 2) {
                        if (i + 2 == r) {
                            for (int j = 1; j <= c; j++) {
                                if (j <= c / 2) {
                                    print(i, j, ff);
                                    print(i + 1, c / 2 + j, ff);
                                    print(i + 2, j, ff);
                                } else {
                                    print(i, j, ff);
                                    print(i + 1, j - c / 2, ff);
                                    print(i + 2, j, ff);
                                }
                            }
                            break;
                        }
                        for (int j = 1; j <= c; j++) {
                            if (j <= c / 2) {
                                    print(i, j, ff);
                                    print(i + 1, c / 2 + j, ff);
                            } else {
                                    print(i, j, ff);
                                    print(i + 1, j - c / 2, ff);
                            }
                        }
                    }
                }
            }
        }
        else if(c == 4) {
            if (r == 3) {
                cout << "POSSIBLE" << endl;
                print(2, 2, ff);
                print(1, 4, ff);
                print(3, 1, ff);
                print(2, 3, ff);
                print(1, 1, ff);
                print(3, 2, ff);
                print(2, 4, ff);
                print(1, 2, ff);
                print(3, 3, ff);
                print(2, 1, ff);
                print(1, 3, ff);
                print(3, 4, ff);
            } else if(r == 4) {
                cout << "POSSIBLE" << endl;
                print(1, 1, ff);
                print(2, 3, ff);
                print(4, 2, ff);
                print(3, 4, ff);
                print(1, 3, ff);
                print(2, 1, ff);
                print(4, 4, ff);
                print(3, 2, ff);
                print(2, 4, ff);
                print(4, 3, ff);
                print(1, 4, ff);
                print(2, 2, ff);
                print(4, 1, ff);
                print(3, 3, ff);
                print(1, 2, ff);
                print(3, 1, ff);
            } else {
                cout << "IMPOSSIBLE" << endl;
            }
        } else if (c <= 3) {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}

/*







16
2 2
2 3
2 4 
2 5
3 2
3 3
3 4 
3 5
4 2
4 3
4 4 
4 5
5 2
5 3
5 4 
5 5


*/