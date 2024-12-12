#include <iostream>

using namespace std;

const int N = 20;

int T, m, cost[4];
int avail_map[1 << 10], cost_map[1 << 10]; // 2^9 operation cost
string r1, r2;

// 11:55 12-2 2024
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
