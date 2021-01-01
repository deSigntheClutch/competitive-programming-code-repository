#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m; 
vector<vector<int> > g, gt;

struct dsu{
 vector<int> par;
 int n;
  dsu(int _n){
      n = _n;
      par = vector<int>(n, -1);
  }

  int find(int u){
      if(par[u] == -1) return u;
      return par[u] = find(par[u]);
  }

  bool merge(int u, int v){
      u = find(u);
      v = find(v);
      if(u == v) return 0;
      par[v] = u;
      return 1;
  }
};


vector<int> compPref(vector<vector<int> > g){
    dsu h(n*m);
    
    vector<int> pref(g.size());
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == 0) count++;
            //cout<<"lol"<<endl;
        }

        //now merge vertically
        for(int j = 0; j < n-1; j++){
            if(g[i][j] == 0 && g[i][j+1] == 0){
                h.merge(i*n + j, i*n + (j+1));
                count--;
            }
        }

        //merge horizontally
        if(i != 0){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 0 && g[i-1][j] == 0){
                    bool rem = h.merge(i*n + j, (i-1)*n + j);
                    if(rem) count--;
                }
            }
        }

        
        pref[i] = count;
    }
    return pref;
}


vector<vector<int> > vis;
void dfs(int x, int y, int lead){
    if(vis[x][y] != -1) return;
    vis[x][y] = lead;
    
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    for(int i = 0; i < dx.size(); i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
        if(g[xx][yy] == 0) continue;
        dfs(xx, yy, lead);
    }
}


signed main(){
    cin>>n>>m;
    g = vector<vector<int> >(m, vector<int>(n));
    gt = g;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin>>c;
            g[j][i] = (c == '1');
        }
    }

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //compute number of white components from 0 to i
    dsu h(n*m);

    vector<int> pref, suff;
    pref = compPref(g);
    auto gt = g;
    reverse(gt.begin(), gt.end());
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<gt[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    suff = compPref(gt); reverse(suff.begin(), suff.end());
    gt.clear();


    // for(int i = 0; i < m; i++){
    //     cout<<pref[i]<<", ";
    // }
    // cout<<endl;

    // for(int i = 0; i < m; i++){
    //     cout<<suff[i]<<", ";
    // }
    // cout<<endl;

    vis = vector<vector<int> >(m, vector<int>(n, -1));

    int bcomp = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == 0) continue;
            if(vis[i][j] != -1) continue;

            bcomp++;
            dfs(i, j, i*n + j);
        }
    }

    pair<int, int> best = {0, 0};
    for(int i = 0; i < m; i++){
        //touching col i
        //compute number of comps
        int w = 0;
        if(i > 0) w += pref[i-1];
        if(i < m-1) w +=suff[i+1];

        int b = bcomp;
        set<int> id;
        for(int j = 0; j < n; j++){
            if(i > 0){
                if(vis[i-1][j] != -1) id.insert(vis[i-1][j]);
            }
            if(i < m-1){
                if(vis[i+1][j] != -1) id.insert(vis[i+1][j]);
            }
            if(vis[i][j] != -1) id.insert(vis[i][j]);
        }

        int sz = id.size();
        //cout<<"SZ "<<sz<<endl;
        b = b - sz + 1;

        if(w + b > best.first + best.second){
            best = {w, b};
        }else if(w + b == best.first  + best.second){
            if(w > best.first) best = {w, b};
        }

        //cout<<"COL "<<i<<" "<<w<<" "<<b<<endl;

    }
    cout<<best.first<<" "<<best.second<<endl;

    
}