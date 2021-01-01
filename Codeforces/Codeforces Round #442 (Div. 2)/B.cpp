#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void rmax(T &x, U y) { if (x < y) x = y; }

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;
string s;
int n;
int c[N], sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin >>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a')c[i+1]=1;
    }
    n = s.length();
    for(int i=1;i<=n+1;i++){
        sum[i]=sum[i-1]+c[i];
    }

    int ans=0;
    for(int l=0;l<=n;l++){
        for(int r=n+1;r>l;r--){
            int s1=l-(sum[l]-sum[0]);
            int s2=(n+1-r)-(sum[n+1]-sum[r-1]);
            int s3=(l+1==r-1)?0:(sum[r-1]-sum[l]);
            //if(l==1&&r==4)cout<<s1<<s2<<s3<<endl;
            ans=max(ans,n-s1-s2-s3);
        }
    }
    cout<<ans<<endl;
    return 0;
}


