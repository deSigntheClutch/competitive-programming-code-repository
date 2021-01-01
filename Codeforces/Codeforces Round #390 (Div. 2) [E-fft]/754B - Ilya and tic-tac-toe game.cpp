#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const int N = 5;

char s[N][N];

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check() {
  for(int i = 1; i <= 4; i++) {
    for(int j = 1; j <= 4; j++) {
      for(int dir = 0; dir < 8; dir++) {
        bool flag = true;
        for(int mov = 0; mov < 3; mov++) {
          int tx = i + mov * dx[dir], ty = j + mov * dy[dir];
          if(!(tx >= 1 && tx <= 4 && ty >= 1 && ty <= 4 && s[tx][ty] == 'x')) {
            flag = false;
          }
        }
        if(flag == true) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  for(int i = 1; i <= 4; i++) {
    scanf("%s", s[i] + 1);
  }
  for(int i = 1; i <= 4; i++) {
    for(int j = 1; j <= 4; j++) {
      if(s[i][j] == '.') {
        s[i][j] = 'x';
        if(check()) {
          printf("YES\n");
          return 0;
        }
        s[i][j] = '.';
      }
    }
  }
  printf("NO\n");
  return 0;
}
