#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll mod = 1e9+7;
ll mul(ll a,ll b){return ((a%mod)*(b%mod))%mod;}
ll sum(ll a,ll b){return ((a%mod)+(b%mod))%mod;}
ll sub(ll a,ll b){return ((a%mod)-(b%mod))%mod;}
ll power(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1)res = mul(res,a);
		b >>= 1;
		a = mul(a,a);
	}
	return res;
}
const int oo = 1e9;
int N,M;

int dp(int u,vector<vii> &graph){
	int res = 0;
	for(auto &v : graph[u])res = max(res,v.se+dp(v.fi,graph));
	return res;
	
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	vi A(N);
	int maxi = 0;
	forn(i,0,N){
		cin >> A[i];
		maxi = max(maxi,A[i]);
	}
	vii B(M);	
	int mini = oo;
	forn(i,0,M){
		cin >> B[i].se >> B[i].fi;
		mini = min(mini,B[i].fi);
	}
	if(maxi > mini){
		cout << "-1\n";
		return 0;
	}
	sort(all(B));
	vi maxPref(M);
	forn(i,0,M){
		maxPref[i] = B[i].se;
		if(i)maxPref[i] = max(maxPref[i],maxPref[i-1]);
	}

	vi ord(N);
	forn(i,0,N)ord[i] = N - 1 - i;
	int res = oo;
	do{
		//debug(ord);
		vector<vii> graph(N);
		forn(i,0,N){
			int sum = A[ord[i]];
			forn(j,i+1,N){
				sum += A[ord[j]];
				int idx = lower_bound(all(B),ii(sum,-1))-B.begin();
				if(idx){
					//debug(i,j,sum,maxPref[idx-1]);
					graph[i].pb({j,maxPref[idx-1]});
				}
			}
		}
        for (int i = 0; i < N; i++) {
            for (auto x : graph[ord[i]]) {
                cout << x.first << " " << x.second << endl;
            }
            cout << " " << endl;
        }
		int tmp = 0;
		forn(i,0,N)tmp = max(tmp,dp(i,graph));
		//debug(tmp);
		res = min(res,tmp);
	}while(next_permutation(all(ord)));
	cout << res << '\n';
	
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
