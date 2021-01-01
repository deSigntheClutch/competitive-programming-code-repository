char P[N], T[N];
int pi[N], n, m; // n = len(T), m = len(P)
vector<int> prefix_function (string) {
	pi[0] = -1;
    int k = -1;
    for(int i = 1; i <= m; i++) {
        while(k >= 0 && P[k+1] != P[i]) k = pi[k];
        pi[i] = ++k;
    }
}
void match() {
    int k = 0;
    for(int i = 1; i <= n; i++) {
        while(k >= 0 && P[k+1] != T[i]) k = pi[k];
        k++;
        if(k == m) k = pi[k];
    }
}