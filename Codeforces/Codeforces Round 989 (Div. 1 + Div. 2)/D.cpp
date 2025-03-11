#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 6;

int n;
int a[N];
set<int> s[3];

bool check01() {
      bool flag = true;
      if (s[0].size() != 0) {
            if (*s[0].rbegin() > *s[1].begin())
                  flag = false;
      }
      return flag;
}

bool check12() {
      bool flag = true;

      if (s[2].size() != 0) {
            if (*s[2].begin() < *s[1].rbegin())
                  flag = false;
      }
      return flag;
}

bool check() {
      bool flag = true;

      if (!check01()) flag = false;
      if (!check12()) flag = false;

      return flag;
}


void print() {

      vector<int> p(n + 1);
      for (int i = 0; i < 3; i++) {
            for (int j : s[i]) {
                  p[j] = i;
            }
      }
      cout << "pp = ";
      for (int i = 1; i <= n; i++) {
            cout << p[i] << " ";
      }
      cout << endl;
}

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n;
            s[0].clear();
            s[1].clear();
            s[2].clear();
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  s[a[i]].insert(i);
            }


            vector<pair<int, int>> ans;

            while (check() == false) {
                  if (!check01()) {
                        //cout << "01!" << endl;
                        int end0 = *s[0].rbegin();
                        s[0].erase(end0);
                        int left1 = *s[1].begin();
                        s[1].erase(left1);
                        ans.push_back(make_pair(end0, left1));

                        s[0].insert(left1);
                        s[1].insert(end0);
                  } else if (!check12()) {
                        //cout << "12!" << endl;

                        int left2 = *s[2].begin();
                        s[2].erase(left2);
                        int right1 = *s[1].rbegin();
                        s[1].erase(right1);
                        ans.push_back(make_pair(right1, left2));

                        s[1].insert(left2);
                        s[2].insert(right1);
                  }

                  //print();
            }

            cout << ans.size() << endl;
            for (auto x : ans) {
                  cout << x.first << " " << x.second << endl;
            }
      }
      return 0;
}
