#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

struct edge {
    int to;
    int cap;
};

int n, m, k;
vector<edge> G[N];
vector<vector<pair<int, int>>> graph;

void dfs(int u, vector<int>& v) {
    if (u == n) return ;
    for (auto x : G[u]) {
        v.push_back(x.cap);
        dfs(x.to, v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }

    int sum = 0, cur = 0;
    int paths = G[1].size();
    for (auto x : G[1]) {
        vector<int> costs;
        costs.push_back(x.cap);

        dfs(x.to, costs);

        k = costs.size();
        sum += accumulate(costs.begin(), costs.end(), 0ll);
        cur += *min_element(costs.begin(), costs.end());

        sort(costs.begin(), costs.end());
        vector<pair<int, int>> pipe;
        for (int i = 0; i < k; i++) {
            int pt = i;
            while (pt < k && costs[i] == costs[pt]) pt += 1;
            pipe.push_back({costs[i], pt - i});
            i = pt - 1;
        }
        graph.push_back(pipe);
    }

    int flow = sum / k;
    priority_queue<pair<int, pair<int, int>>> heap;
    for (int i = 0; i < paths; i++) {
        heap.push({-graph[i][0].second, {i, 0}});
    }

    if (flow == cur) {
        cout << 0 << endl;
        return 0;
    }
    int operation = 0;
    while (!heap.empty()) {
        auto x = heap.top();
        heap.pop();
        if (-x.first == k) continue;
        int vol = -x.first;
        int pos = x.second.first;
        int pt = x.second.second;

        if (cur + (graph[pos][pt + 1].first - graph[pos][pt].first) >= flow) {
            cout << operation + (flow - cur) * vol << endl;
            return 0;
        } 
        cur += (graph[pos][pt + 1].first - graph[pos][pt].first);
        operation += (graph[pos][pt + 1].first - graph[pos][pt].first) * vol;
        heap.push({-(vol + graph[pos][pt + 1].second), {pos, pt + 1}});
        graph[pos][pt + 1].second += vol;
    }
    return 0;
}


/*

6 6
1 2 2
1 3 4 
3 4 3
2 5 2
4 6 2
5 6 6

*/