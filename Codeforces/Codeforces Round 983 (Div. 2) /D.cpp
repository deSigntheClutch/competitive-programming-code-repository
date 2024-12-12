#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
const int INF = 1e9 + 10;

int T, n, cntASK;
int p[N];
int chainChild[N];

int ask(int x, int y) {
        cout << "? " <<  x  << " " << y << endl;
        fflush(stdout);
        cntASK += 1;
        int result;
        cin >> result;
        return result;
}


int main() {
      cin >> T;
      while (T--) {
        cin >> n;
        fill(p, p + n + 1, 0);
        fill(chainChild, chainChild + n + 1, 0);

        int cur = 2;
        int numOfChain = 1;

        while (true) {
              if (cur == n) break;
              int res = ask(1, cur);
              if (res == 1) {
                    p[cur++] = 0;
                    numOfChain += 1;
              } else {
                    p[cur++] = 1;
                    break;
              }
        }
        queue<int> Q;

        chainChild[1] = cur - 1;
        for (int i = 2; i <= numOfChain; i++) {
              chainChild[i] = i;
              Q.push(i);
        }
        Q.push(1);

        // now cur is next unknown node
        while (cur < n) {
              int chainId = Q.front();
              int res = ask(chainId, cur);

              Q.pop();
              if (res) {
                    continue;
              } else {
                    p[cur++] = chainChild[chainId];
                    Q.push(chainId);
                    chainChild[chainId] = cur - 1;
              }
        }

        cout << "! ";
        for (int i = 1; i < n; i++) {
              cout << p[i] << " ";
        }
  }
      cout << endl;
      fflush(stdout);
      return 0;
}
//  2 n - 6