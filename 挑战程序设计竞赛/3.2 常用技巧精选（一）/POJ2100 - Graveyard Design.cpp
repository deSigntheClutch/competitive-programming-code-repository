#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

long long n;
vector<pair<int, long long> > ans;

int main() {
  scanf("%lld", &n);
  long long t = sqrt(n) + 1;
  long long cur = 0;
  int num = 0;
  for(long long i = t; i >= 1; i--) {
    cur += i * i;
    num++;
    if(cur == n) {
      ans.push_back(make_pair(-num, i));
    }
    while(cur > n) {
      cur -= (i + num - 1) * (i + num - 1);
      num--;
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    printf("%d", -ans[i].first);
    for(int j = 0; j < -ans[i].first; j++) {
      printf(" %lld", ans[i].second + j);
    }
    printf("\n");
  }
  return 0;
}
