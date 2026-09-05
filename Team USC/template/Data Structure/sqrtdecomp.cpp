int B, a[N], b[N];

void init( int n) {
    B = (int) sqrt (n + .0) + 1; 
    for (int i=0; i < n; ++i)
        b[i / B] += a[i];
}
 
int cal(int l, int r) {
    int sum = 0, c_l = l / B,   c_r = r / B;
    if (c_l == c_r)
        for (int i=l; i<=r; ++i) sum += a[i];
    else {
        for (int i=l, end=(c_l+1)*B-1; i<=end; ++i) sum += a[i];
        for (int i=c_l+1; i<=c_r-1; ++i) sum += b[i];
        for (int i=c_r*B; i<=r; ++i) sum += a[i];
    }
}