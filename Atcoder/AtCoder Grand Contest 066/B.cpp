#include <iostream>

using namespace std;

const int N = 20;

int T, m, cost[4];
int avail_map[1 << 10], cost_map[1 << 10]; // 2^9 operation cost
string r1, r2;

int get_grid_msk(int ope_msk) {
  int res = 0;
  for (int i = 0; i < 9; i++) {
    int bit = (ope_msk >> i) & 1;
    if (bit & 1) {
      if (i >= 0 && i < 4) {
        res ^= (1 << i);
      }
      if (i >= 4 && i < 6) {
        if (i == 4) {
          res ^= 1;
          res ^= 2;
        } else {
          res ^= 4;
          res ^= 8;
        }
      }
      if (i >= 6 && i < 8) {
        if (i == 6) {
          res ^= 1;
          res ^= 4;
        } else {
          res ^= 2;
          res ^= 8;
        }
      }
      if (i >= 8 && i < 9) {
        res ^= ((1 << 4) - 1);
      }
    }
  }
  return res;
}

void init() {
  for (int msk = 0; msk < (1 << 9); msk++) {
    avail_map[msk] = 0;
  }

  for (int msk = 0; msk < (1 << 9); msk++) {
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
      int bit = (msk >> i) & 1;
      if (bit & 1) {
        if (i >= 0 && i < 4) cnt += cost[0];
        if (i >= 4 && i < 6) cnt += cost[1];
        if (i >= 6 && i < 8) cnt += cost[2];
        if (i >= 8 && i < 9) cnt += cost[3];
      }
    }
    cost_map[msk] = cnt;
  }

  for (int msk = 0; msk < (1 << 9); msk++) {
    int grid_msk = get_grid_msk(msk);
    avail_map[msk] |= (1 << grid_msk);

    cout << std::bitset<16>(avail_map[msk]).to_string() << endl;
  }
}

// 7:00 12-1 2024
int main() {
  init();

  cin >> T;
  for (int i = 0; i < 4; i++) {
    cin >> cost[i];
  }
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
    int ans = 1e9 + 10;

    cout << std::bitset<16>(possible_grid_msk).to_string() << endl;

    for (int i = 0; i < (1 << 9); i++) {

      if ((avail_map[i] & possible_grid_msk) == possible_grid_msk) {
        cout << std::bitset<16>(avail_map[i]).to_string() << endl;
        ans = min(ans, cost_map[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
