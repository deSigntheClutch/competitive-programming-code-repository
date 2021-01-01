int ppow(int a, int b, int mod) {
    int ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

bool Miller_Rabin(int p) {
    srand(time(0));
    if (p == 1) return false;
    int t = p - 1, c = 0;
    while (t % 2 == 0) t /= 2, c++;
    for (int i = 0; i < 5; i++) {
        int rd = rand() % p + rand();
        int a = ppow(rd, t, p), last = a;
        for (int j = 1; j <= c; j++) {
            last = a * a % p;
            if (last == 1 && a != 1 && a != p - 1) return false;
            a = last;
        }
        if (a != 1) return false;
    }
    return true;
}