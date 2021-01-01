#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n;
char s[N];

int cnt[666];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        cnt[s[i]]++;
    }
    int res = 1;
    for (int i = 'a'; i <= 'z'; i++) {
        
        res = (long long)res * (cnt[i] + 1) % MOD;
    }
    printf("%d\n", (res - 1 + MOD) % MOD);
    return 0;
}