#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int n, k;
int fact[N];


void check(vector<vector<int>> s) {
      int sum = 0;
      for (int i = 0; i < n; i++) {
            int cur = 0;
            for (auto x : s) {
                  cur += x[i];
            }

            if (sum == 0) {
                  sum = cur;
            } else {
                  if (sum != cur) {
                        cout << " WRONG" << endl;
                        break;
                  }
            }
      }
}


int main() {
      fact[0] = 1;
      fact[1] = 1;

      for (int i = 2; i <= 10; i++) {
            fact[i] = i * fact[i-1];
      }
      int T;
      cin >> T;
      while (T--) {
            cin >> n >> k;

            if (k == 1) {
                  if (n == 1) {
                        cout << "YES" << endl;
                        cout << 1 << endl;
                  } else {
                        cout << "NO" << endl;
                  }
                  continue;
            }

            if (n <= 10 && k > fact[n]) {
                  cout << "NO" << endl;
                  continue;
            }

            if (k % 2 == 0) {
                  vector<vector<int>> ans;
                  vector<int> p(n);

                  for (int i = 1; i <= n; i++) {
                        p[i - 1] = i;
                  }

                  do {
                        vector<int> revP = [&p]() {
                              vector<int> res;
                              for (int x : p) {
                                    res.push_back(n - x + 1);
                              }
                              return res;
                        }();

                        ans.push_back(p);
                        ans.push_back(revP);

                        if (ans.size() == k) {
                              break;
                        }
                  } while(next_permutation(p.begin(), p.end()));

                  cout << "YES" << endl;
                  for (auto vv : ans) {
                        for (int x : vv) {
                              cout << x << " ";
                        }
                        cout << endl;
                  }
            } else {
                  if (n % 2 == 0) { // n * (n + 1) / 2 * k / n
                        cout << "NO" << endl;
                  } else if (n <= 10 && fact[n] - 1 == k) {
                        cout << "NO" << endl;
                  } else {
                              vector<vector<int>> ans;
                              vector<int> p(n), p0(n), p1(n);

                              for (int i = 1; i <= n; i++) {
                                    p[i - 1] = i;
                              }

                              for (int i = 1; 2 * i <= n + 1; i++) {
                                    p0[2 * i - 2] = (n + 1) / 2 - i + 1;
                                    p1[2 * i - 2] = n - i + 1;
                                    if (i <= n) {
                                          p0[2 * i - 1] = n - i + 1;
                                          p1[2 * i - 1] = (n + 1) / 2 - i;
                                    }
                              }

                              ans.push_back(p);
                              ans.push_back(p0);
                              ans.push_back(p1);

                              map<vector<int>, bool> used;

                              for (auto vv : ans) {
                                    used[vv] = true;
                              }

                              do {
                                    if (ans.size() == k) {
                                          break;
                                    }

                                    vector<int> revP = [&p]() {
                                          vector<int> res;
                                          for (int x : p) {
                                                res.push_back(n - x + 1);
                                          }
                                          return res;
                                    }();

                                    if (!used[p] && !used[revP]) {
                                          ans.push_back(p);
                                          ans.push_back(revP);
                                    }
                              } while(next_permutation(p.begin(), p.end()));

                              if (ans.size() != k) {
                                    cout << "NO" << endl;
                              } else {
                                    cout << "YES" << endl;
                                    for (auto vv: ans) {
                                          for (int x: vv) {
                                                cout << x << " ";
                                          }
                                          cout << endl;
                                    }
                              }
                        }
                  }
            }

      return 0;
}
