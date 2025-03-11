#include <iostream>
#include <algorithm>
using namespace std;

int main() {
      int n, k, x;
      int T;
      cin >> T;
      while (T--) {
            cin >> n >> k >> x;
            if (x != 1) {
                  cout << "YES" << endl;
                  cout << n << endl;
                  for (int i = 0; i < n; i++)
                        cout << 1 << " ";
                  cout << endl;
            } else {
                  if (k == 1) {
                        cout << "NO" << endl;
                  } else if (k == 2) {
                        if (n % 2 == 0) {
                              cout << "YES" << endl;
                              cout << n / 2 << endl;
                              for (int i = 0; i < n / 2; i++)
                                    cout << 2 << " ";
                              cout << endl;
                        } else {
                              cout << "NO" << endl;
                        }
                  } else {
                        if (n % 2 == 0) {
                              cout << "YES" << endl;
                              cout << n / 2 << endl;
                              for (int i = 0; i < n / 2; i++)
                                    cout << 2 << " ";
                              cout << endl;
                        } else {
                              cout << "YES" << endl;
                              cout << 1 + (n - 3) / 2 << endl;
                              cout << 3 << " ";
                              for (int i = 0; i < (n - 3) / 2; i++)
                                    cout << 2 << " ";
                              cout << endl;
                        }
                  }
            }
      }
}