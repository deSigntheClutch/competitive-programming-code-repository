/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . ___
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
              find_str Bao You
*/
#include <iostream>
#include <queue>
#include <assert.h>   
#include <vector>
#include <algorithm>
#include <time.h>
#include <numeric>
#include <string>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;
#define ll long long
#define ld long double 
#define pi pair<int, int> 
#define pl pair<ll,ll>  
#define pd pair<ld,ld> 
#define str string  
#define mp make_pair
#define vi vector<int> 
#define vl vector<ll> 
#define vd vector<ld> 
#define vs vector<str> 
#define vpi vector<pi> 
#define vpl vector<pl> 
#define vpd vector<pd> 
#define si set<int> 
#define FF(i,j,n) for(signed i=j;i<=n;i++)  
#define DD(i,j,n) for(signed i=j;i>=n;i--) 
#define F(i,j,n) for(signed i=j;i<n;i++)   
#define D(i,j,n) for(signed i=j;i>n;i--) 
#define mem(a,b) memset(a,b,sizeof(a))
#define ndl cout << endl
#define ull unsigned long long 
 
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
 
 
#define sz(x) (signed)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back() 
#define fi first
#define se second
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
//math
const int mod = 1e9 + 7;
 
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
 
 
//DEBUG, compile with -DLOCAL
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
  DBG(t...); }
#ifdef LOCAL 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define HERE cout << "===GOTHERE===" << endl
#else
#define dbg(...) 42
#define HERE 42
#endif
 
//#define double long double
#define int long long
//#define int unsigned long long
 
const int maxn = 1e5*2+20;
 
int ntn = 387420489;
int stn = 40353607;
 
int n,k;
 
void solve(){
  int inv = (ntn * k) % 11;
  inv = ((inv - 1) + 11) % 11;
  //7 i + j = inv (mod 11)
  int ans = 0;
  FF(s,1,5){
    int t = ((inv - s) + 11) % 11;
    int tm = (stn * t) % 11;
    //dbg(tm);
    ans += ((n/11) + (n%11 >= tm && (tm != 0)));
  }
  cout << ans << endl;
}
 
signed main(){
  //clock_t t1 = clock();  
	IOS
  cin >> n >> k;
  n -= 2;
	solve();
  
  //cout << "THE ALGORITHM TOOK: " << (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << "ms"<< endl;
	return 0;
}