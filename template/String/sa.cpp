int sa[N], wa[N], wb[N], cnt[N], rank[N], height[N];
void getSA(int *sz, int len){
    int *x = wa, *y = wb, m = 27;
    for (int i = 1; i <= len; i++) cnt[x[i] = sz[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = len; i; i--) sa[cnt[x[i]]--] = i;
    for (int h = 1; h <= len; h <<= 1){
        int pos = 0;
        for (int i = len - h + 1; i <= len; i++) y[++pos] = i;
        for (int i = 1; i <= len; i++) if (sa[i] > h) y[++pos] = sa[i] - h;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= len; i++) cnt[x[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = len; i; i--) sa[cnt[x[y[i]]]--] = y[i];
        swap(x, y); pos = 0; x[sa[1]] = ++pos;
        for (int i = 2; i <= len; i++) 
          x[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + h] == y[sa[i - 1] + h] ? pos : ++pos;
        m = pos;
        if (m == len) break;
    }
}
void getHeight(int *sz, int len){
    for (int i = 1; i <= len; i++) rank[sa[i]] = i;
    int k = 0;
    for (int i = 1; i <= len; i++){
        if (k) k--;
        int p = sa[rank[i] - 1];
        while (sz[p + k] == sz[i + k]) k++;
        height[rank[i]] = k;
    }
}
