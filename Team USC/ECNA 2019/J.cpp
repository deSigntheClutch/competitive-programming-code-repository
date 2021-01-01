#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int n, k;
struct seg{
    vector<int> lazy, low;
    int sz;
    seg(int n, int val){
        sz = n;
        lazy = vector<int>(4*n);
        low = vector<int>(4*n);
        //cout<<"lol"<<endl;
        build(1, 0, n-1, val);
    }

    void build(int i, int s, int e, int val){
        //cout<<s<<" "<<e<<endl
        if(s == e){
            low[i] = val*(s);
            lazy[i] = 0;
            return;
        }
        int m = (s + e)/2;
        build(i*2, s, m, val);
        build(i*2+1, m+1, e, val);
        low[i] = min(low[i*2], low[i*2+1]);
        lazy[i] = 0;
    }


    void pushdown(int i, int s, int e){
        if(lazy[i] == 0) return;
        if(s != e){
            lazy[2*i] += lazy[i];
            lazy[2*i + 1] += lazy[i];
        }
        low[i] += lazy[i];
        lazy[i] = 0;

    }

    void upd(int i, int s, int e, int l, int r, int val){
        pushdown(i, s, e);
        if(l <= s && e <= r){
            lazy[i] -= val;
            pushdown(i, s, e);
            return;
        }
        if(s > r || e < l) return;
        int m = (s + e)/2;
        upd(i*2, s, m, l, r, val);
        upd(i*2+1, m+1, e, l,r, val);
        low[i] = min(low[i*2], low[i*2+1]);
    }

    int query(int i, int s, int e, int l, int r){
        pushdown(i, s, e);
        //cout<<"S: "<<s<<" "<<e<<" "<<low[i]<<endl;
        if(l <= s && e <= r) return low[i];
        if(s > r || e < l) return 1e18;
        int m = (s + e)/2;
        return min(query(i*2, s, m, l, r), query(i*2+1, m+1, e, l, r));
    }
};


struct work {
    int works;
    int time;

};

bool comp(const work& a, const work& b){
    return (long long)a.works * b.time < (long long) b.works * a.time;
}

pair<int, int> yes[N];

signed main() {
    cin >> n >> k;
    vector<pair<int, int> > w(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i].first >> w[i].second; //len and deadline
    }
    sort(w.begin() + 1, w.end());
    
    int low = 1, high = 1e15, mid;
    while(low < high){
        mid = (low + high)/2;
        //cout<<"MID: "<<mid<<endl;
        int left = 0;
        seg tree(1e4 + 10, mid);

        for(int i = 1; i <= n; i++){
            //cout<<i<<endl;
            if(mid< 300){
                //cout<<w[i].first<<" "<<w[i].second<<endl;
                //cout<<"LEFT: "<<tree.query(1, 0, tree.sz-1, w[i].second, tree.sz-1)<<endl;
            }
            if(tree.query(1, 0, tree.sz-1, w[i].second, tree.sz-1) >= w[i].first){
                tree.upd(1, 0, tree.sz-1, w[i].second, tree.sz-1, w[i].first);
            }else{
                left++;
                
            }
        }
        if(left <= k){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    mid = (low + high)/2;
    cout<<mid<<endl;

    return 0;
}