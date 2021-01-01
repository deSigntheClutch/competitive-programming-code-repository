#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

string s;
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int ans = 0;
  for(int i=0;i<n;i++) {
    cin >> s;
    if(s == "Tetrahedron") ans += 4;
    else if(s =="Cube") ans += 6;
    else if(s == "Octahedron") ans += 8;
    else if(s == "Dodecahedron") ans += 12;
    else ans += 20;
  }
  cout << ans << endl;
  return 0;
}


