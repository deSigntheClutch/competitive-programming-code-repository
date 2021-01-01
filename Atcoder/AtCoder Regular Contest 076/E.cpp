#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 9e18;
const int N = 1e5 + 10;
 
int x[N][2], y[N][2];
int r, c, n;
 
vector<pair<int, int>> upper, lower, lb, rb;
bool used[N];
void solve1() {
  cin >> r >> c >> n;
  for (int i = 1; i <= n; i++) {
      cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
      int cnt = 0;
      if (x[i][0] == 0 || x[i][0] == r || y[i][0] == 0 || y[i][0] == c) cnt += 1;
      if (x[i][1] == 0 || x[i][1] == r || y[i][1] == 0 || y[i][1] == c) cnt += 1;
      if (cnt != 2) continue;
      if (x[i][0] == 0) {
        upper.push_back({y[i][0], i});
      } else if (y[i][0] == c) {
        rb.push_back({x[i][0], i});
      } else if (x[i][0] == r) {
        lower.push_back({y[i][0], i});
      } else if (y[i][0] == 0) {
        lb.push_back({x[i][0], i});
      }
      if (x[i][1] == 0) {
        upper.push_back({y[i][1], i});
      } else if (y[i][1] == c) {
        rb.push_back({x[i][1], i});
      } else if (x[i][1] == r) {
        lower.push_back({y[i][1], i});
      } else if (y[i][1] == 0) {
        lb.push_back({x[i][1], i});
      }
  }
  sort(upper.begin(), upper.end());
  sort(rb.begin(), rb.end());
  sort(lower.begin(), lower.end(), greater<pair<int, int>>());
  sort(lb.begin(), lb.end(), greater<pair<int, int>>());
  bool flag = true;
  stack<int> S;
  for (auto x : upper) {
   // cout << x.first<< " " << x.second << endl;
    int id = abs(x.second);
    if (used[id] == 1) {
      if (S.top() == id) {
        S.pop();
      } else {
        flag = false;
      }
    } else {
      used[id] = 1;
      S.push(id);
    }
  }
  for (auto x : rb) {
   // cout << x.first<< " " << x.second << endl;
    int id = abs(x.second);
    if (used[id] == 1) {
      if (S.top() == id) {
        S.pop();
      } else {
        flag = false;
      }
    } else {
      used[id] = 1;
      S.push(id);
    }
  }
  for (auto x : lower) {
   // cout << x.first<< " " << x.second << endl;
    int id = abs(x.second);
    if (used[id] == 1) {
      if (S.top() == id) {
        S.pop();
      } else {
        flag = false;
      }
    } else {
      used[id] = 1;
      S.push(id);
    }
  }
  for (auto x : lb) {
   // cout << x.first<< " " << x.second << endl;
    int id = abs(x.second);
    if (used[id] == 1) {
      if (S.top() == id) {
        S.pop();
      } else {
        flag = false;
      }
    } else {
      used[id] = 1;
      S.push(id);
    }
  }
  if (flag == false) cout << "NO" << endl;
  else cout << "YES" << endl; 
}
 
 
 
 
 
 
 
 
 
 
vector<pair<pair<int, int>, int>> v;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return (long long)a.first.first * b.first.second <= (long long)a.first.second * b.first.first;
}
void solve2() {
  cin >> r >> c >> n;
  r *= 2; c *= 2;
  for (int i = 1; i <= n; i++) {
      cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
      x[i][0] *= 2; x[i][1] *= 2; y[i][0] *= 2; y[i][1] *= 2;
      int cnt = 0;
      if (x[i][0] == 0 || x[i][0] == r || y[i][0] == 0 || y[i][0] == c) cnt += 1;
      if (x[i][1] == 0 || x[i][1] == r || y[i][1] == 0 || y[i][1] == c) cnt += 1;
      if (cnt != 2) continue;
      v.push_back(make_pair(make_pair(x[i][0], y[i][0]), i)); v.push_back(make_pair(make_pair(x[i][1], y[i][1]), i));
  }
  stack<int> S;
  sort(v.begin(), v.end(), cmp);
  for (auto t : v) {
    cout << t.first.first << " " << t.first.second << " " << t.second << endl;
    if (!used[t.second]) {
      S.push(t.second);
      used[t.second] = 1;
    } else {
      if (S.top() != t.second) {
        //cout << "NO" << endl;
      } else {
        S.pop();
      }
    }
  }
  cout << "YES" << endl; 
}
 
int main() {
    ios::sync_with_stdio(false);
    //solve1();
    solve2();
    return 0;
}
 
// 1 1 2
// 0 0 1 1
// 1 0 0 1