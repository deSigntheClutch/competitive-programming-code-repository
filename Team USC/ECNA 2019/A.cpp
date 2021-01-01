#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
#define x first
#define y second

struct trip{
    long long dist;
    int x, y;

};

bool comp(const trip& a, const trip& b){
    if(a.dist == b.dist){
        if(a.x == b.x) return a.y < b.y;
        else return a.x < b.x;
    }else return a.dist < b.dist;
}

long long dist2(ii a, ii b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

signed main() {
    ios::sync_with_stdio(false);
    int n, m, p; cin>>n>>m>>p;

    vector<ii> a(n), b(m), c(p);

    for(int i = 0; i < n; i++){
        cin>>a[i].x>>a[i].y;
    }

    for(int i = 0; i < m; i++){
        cin>>b[i].x>>b[i].y;
    }

    for(int i = 0; i < p; i++){
        cin>>c[i].x>>c[i].y;
    }

    long double ans = 0;

    vector<int> aa(n), bb(m), cc(p);

    vector<trip> edges; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            trip t = {dist2(a[i], b[j]), i, j};
            edges.push_back(t);
        }
    }

    sort(edges.begin(), edges.end(), comp);

    for(trip e : edges){
        if(aa[e.x] == 1 || bb[e.y] == 1) continue;
        aa[e.x] = 1; 
        bb[e.y] = 1;
        ans += sqrt(e.dist);
    }

    aa = vector<int>(n);

    edges.clear(); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            trip t = {dist2(a[i], c[j]), i, j};
            edges.push_back(t);
        }
    }

    sort(edges.begin(), edges.end(), comp);

    for(trip e : edges){
        if(aa[e.x] == 1 || cc[e.y] == 1) continue;
        aa[e.x] = 1; 
        cc[e.y] = 1;
        ans += sqrt(e.dist);
    }

    cout<<fixed << setprecision(10) << ans<<endl;

    return 0;
}