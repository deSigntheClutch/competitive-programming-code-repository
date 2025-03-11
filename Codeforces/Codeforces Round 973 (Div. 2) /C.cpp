#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 4;
const long long INF = 1e18 + 1;

int n, T, cnt = 0;
map<string, int> used;

int ask(string str) {

      if (used[str] > 0) {
            return used[str] - 1;
      }

      if (str.size() == 1) {
            if (used["0"] == 1 && str == "1") {
                  used["1"] = 2;
                  return 2 - 1;
            }
      }

      if (str.size() == n) {
            string tmp = str;
            tmp[0] = '0';
            if (used[tmp] == 1 && used[str] == 0 && str[0] == '1') {
                  used[str] = 2;
                  return 2 - 1;
            }
      }

      cnt += 1;
      if (cnt > 2 * n) {
            while (true) {
                  int a = 1;
            }
      }


      cout << "? " << str << endl;
      fflush(stdout);

      int response;
      cin >> response;

      used[str] = response + 1;
      return response;
}


int main() {
      cin >> T;
      while (T--) {
            used.clear();
            cnt = 0;

            cin >> n;
            string tmp = "";
            while (true) {
                  if (tmp.size() == n) break;

                  int res1 = ask(tmp + (char)('0'));

                  if (!res1) {
                        int res2 = ask(tmp + (char)('1'));

                        if (!res2) {
                              break;
                        } else {
                              tmp += '1';
                        }
                  } else {
                        tmp += '0';
                  }
            }

            fflush(stdout);

            while (true) {
                  if (tmp.size() == n) break;

                  int res1 = ask((char)('0') + tmp);

                  if (!res1) {
                        int res2 = ask((char)('1') + tmp);

                        if (!res2) {
                              break;
                        } else {
                              tmp = '1' + tmp;
                        }
                  } else {
                        tmp = '0' + tmp;
                  }
            }

            cout << "! " << tmp << endl;
            fflush(stdout);

      }
      return 0;
}
