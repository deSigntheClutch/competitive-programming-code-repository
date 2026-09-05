bool vis[N], used[N];
int64 fac[N];

void init() {
    for (int i = 2; i < N; i++) fac[i] = fac[i - 1] * i;
}

int64 KT(vector<int> v, int len) {
    if (len == 0) return 0;
    int64 sum = 0;
    for (int i = 0; i < len; i++) {
        int t = 0;
        for (int j = i + 1; j < len; j++) {
            if (v[j] < v[i]) t++;
        }
        sum += (int64)t * fac[len - i - 1];
    }
    return ++sum;
}

vector<int> invKT(int u, int now) {
    vector<int> res;
    memset(vis, 0, sizeof(vis));
    now--;
    for (int i = 1; i <= u; i++) {
        int64 t = (int64)now / fac[u - i];
        for (int j = 1; j <= u; j++) {
            if (!vis[j]) {
                if (!t) {
                    res.push_back(j);
                    vis[j] = 1;
                    break;
                }
                t--;
            }
        }
        now %= fac[u - i];
    }
    return res;
}