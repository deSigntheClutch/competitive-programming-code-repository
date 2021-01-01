#include<bits/stdc++.h>

using namespace std;

#define int long long


struct segtree{
    vector<int> t;
    vector<int> lazy;
    vector<int> sum;
    int sz;

    segtree(int size, vector<int> c){
        sz = size;
        t = vector<int>(sz*4, 0);
        lazy = vector<int>(sz*4, 0);
        sum = vector<int>(sz*4, 0);
        build(1, 0, sz-1, c);
    }

    void build(int i, int s, int e, vector<int>& c){
        if(s == e){
            sum[i] = c[s];
            return;
        }
        int m = (s + e)/2;
        build(i*2, s, m, c);
        build(i*2+1, m+1, e, c);
        sum[i] = sum[i*2] + sum[i*2+1];
    }

    void prop(int i, int s, int e){
        if(lazy[i] == 0) return;
        t[i] = (sum[i]) - t[i];
        if(s != e){
            lazy[i*2] ^= 1;
            lazy[i*2+1] ^= 1;
        }
        lazy[i] = 0;
    }

    int query(){
        prop(1, 0, sz-1);
        return t[1];
    }

    void upd(int i, int s, int e, int l, int r){
        prop(i, s, e);
        if(s > r || e < l || s > e){
            //out of range
            return;
        }
        if(s >= l && e <= r){
            lazy[i] ^= 1;
            prop(i, s, e);
            return;
        }
        int m = (s + e)/2;
        upd(i*2, s, m, l, r);
        upd(i*2+1, m+1, e, l, r);
        t[i] = t[i*2] + t[i*2+1];
    }
};

struct event{
    int x, low, high;
    bool type; //true for exit
};

bool comp(event a, event b){
    // if(a.x != b.x) return a.x < b.x;
    // else return a.type;
    return a.x < b.x;
}



signed main(){
    int n; cin>>n;

    vector<event> e;
    vector<vector<int> > g(n, vector<int>(4));
    vector<int> uny;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; 
        cin>>x1>>y1>>x2>>y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        g[i] = {x1, y1, x2, y2};
        uny.push_back(y1);
        uny.push_back(y2);
    }

    sort(uny.begin(), uny.end());
    uny.resize(unique(uny.begin(), uny.end())-uny.begin());

    vector<int> c;
    for(int i = 0; i < (int)uny.size()-1; i++){
        c.push_back(uny[i+1] - uny[i]);
    }


    for(int i = 0; i < n; i++){

        int y1 = lower_bound(uny.begin(), uny.end(), g[i][1])-uny.begin();
        int y2 = lower_bound(uny.begin(), uny.end(), g[i][3])-uny.begin();
        e.push_back({g[i][0], y1, y2-1, false});
        e.push_back({g[i][2], y1, y2-1, true});
    }

    sort(e.begin(), e.end(), comp);
    int ans = 0;
    int prev = 0;
    
    segtree seg(c.size(), c);

    //cout<<"LOL"<<endl;

    // for(int i = 0; i < e.size(); i++){
    //     cout<<i<<": "<<e[i].x<<" "<<e[i].low<<" "<<e[i].high<<" "<<e[i].type<<endl;
    // }

    for(int i = 0; i < e.size(); i++){
        event cur = e[i];
        //cout<<"UPDING "<<cur.low<<" "<<cur.high<<endl;
        seg.upd(1, 0, seg.sz-1, cur.low, cur.high);
        
        if(i < e.size() -1){
            ans += seg.query()*(e[i+1].x - e[i].x);
            //cout<<"Q: "<<seg.query()<<" "<<(e[i+1].x - e[i].x)<<endl;
        } 
    }
    cout<<ans<<endl;


}