#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int n;
int a[N], b[N];
int p[N];
bool vis[N];

void print() {
  for(int i = 1; i <= n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}

bool check() {
  int u = 0, v = 0;
  for(int i = 1; i <= n; i++) {
    if(a[i] != p[i]) u++;
    if(b[i] != p[i]) v++;
  }
  return u == 1 && v == 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> event;
  for(int i = 1; i <= n; i++) {
    if(a[i] != b[i]) {
      event.push_back(i);
    }
  }
  if((int)event.size() == 1) {
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) {
      if(i != event[0]) {
        vis[a[i]] = 1;
      }
    }
    int key = 0;
    for(int i = 1; i <= n; i++) {
      if(!vis[i]) key = i;
    }
    a[event[0]] = key;
    for(int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  } else {
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) {
      if(i != event[0] && i != event[1]) {
        vis[a[i]] = 1;
      }
    }
    vector<int> v;
    for(int i = 1; i <= n; i++) {
      if(!vis[i]) v.push_back(i);
    }
    for(int i = 1; i <= n; i++) {
      if(i != event[0] && i != event[1]) {
        p[i] = a[i];
      }
    }
    p[event[0]] = v[0];
    p[event[1]] = v[1];
    if(check()) print();
    else {
      swap(p[event[0]], p[event[1]]);
      print();
    }
  }
  return 0;
}

