#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

int n;

int pow_mod(int u, int x) {
      int res = 1;
      while (x) {
            if (x & 1) res = (long long)res * u % MOD;
            x >>= 1;
            u = (long long)u * u % MOD;
      }
      return res;
}

int main() {

      int a[41] = {1, 2, 4, 6, 12, 24, 36,
                   48, 60, 120, 180, 240, 360,
                   720, 840, 1260, 1680, 2520,
                   5040, 7560, 10080, 15120, 20160,
                   25200, 27720, 45360, 50400, 55440,
                   83160, 110880, 166320, 221760, 277200,
                   332640, 498960, 554400, 665280, 720720,
                   1081080, 1441440, 2162160};

      cin >> n;
      cout << (pow_mod(2, a[n - 1]) + MOD - 1) % MOD << endl;
      return 0;
}
