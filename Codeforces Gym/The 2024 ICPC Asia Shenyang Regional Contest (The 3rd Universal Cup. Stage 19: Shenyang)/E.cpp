#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 1e9 + 1;

int T, m, cost[4];
vector<int> newCost;
string r1, r2;
int f[1 << 17][1 << 4];
int g[1 << 17];

struct State {
  int stateMask;
  int curMatrixMask;
  int c;
  bool operator < (struct State s) const {
    return c > s.c;
  }
};

int operationMask[9] = {
    1,
    2,
    4,
    8,
    3,
    12,
    5,
    10,
    15,
};

void init() {
  newCost = vector<int>({cost[0], cost[0], cost[0], cost[0], cost[1], cost[1], cost[2], cost[2], cost[3]});

  fill(&f[0][0], &f[0][0] + (1 << 17) * (1 << 4), INF);
  f[0][0] = 0;

  priority_queue<State> Q;
  Q.push((State) {
    0, 0, 0
  });

  while(!Q.empty()) {
    int curMatrixMask = Q.top().curMatrixMask;
    int stateMask = Q.top().stateMask;
    int c = Q.top().c;
    Q.pop();

    for (int i = 0; i < 9; i++) {
      int op = operationMask[i];
      int newMatrixMask = curMatrixMask ^ op;
      int newStateMask = stateMask | (1 << (newMatrixMask ^ 15));
      if (f[newStateMask][newMatrixMask] > c + newCost[i]) {
        f[newStateMask][newMatrixMask] = c + newCost[i];
        Q.push((State) {
            newStateMask, newMatrixMask, f[newStateMask][newMatrixMask]
        });
      }
    }
  }

  for (int i = 0; i < (1 << 16); i++) {
    g[i] = *min_element(f[i], f[i] + 16);
  }
}

// 7:00 12-1 2024
int main() {
  cin >> T;
  for (int i = 0; i < 4; i++) {
    cin >> cost[i];
  }
  init();
  while (T--) {
    cin >> m;

    int possible_grid_msk = 0;
    for (int i = 0; i < m; i++) {
      cin >> r1 >> r2;
      int msk = 0;
      if (r1[0] == '1') msk |= 1;
      if (r1[1] == '1') msk |= 2;
      if (r2[0] == '1') msk |= 4;
      if (r2[1] == '1') msk |= 8;
      possible_grid_msk |= (1 << msk);
    }
    int ans = INF;
    for (int i = 0; i < (1 << 16); i++) {
      if ((i & possible_grid_msk) == possible_grid_msk)
        ans = min(ans, g[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
