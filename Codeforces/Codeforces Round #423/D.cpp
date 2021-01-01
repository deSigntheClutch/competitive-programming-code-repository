#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    int t = (n - k - 1) / k, md = (n - k - 1) % k;
    int id = k + 2, lid = 1;
    if (md == 1) printf("%d\n", 2 * t + 3);
    else if(md > 1) printf("%d\n", 2 * t + 4);
    else printf("%d\n", 2 * t + 2);
    for (int i = 0; i < md; i++) {
        printf("%d %d\n", k + 1, id++);
        for (int j = 0; j < t; j++) {
            printf("%d %d\n", id - 1, id), id++;
        }
        printf("%d %d\n", id - 1, lid++);
    }
    for (int i = 0; i < k - md; i++) {
        if (t) printf("%d %d\n", k + 1, id++);
        else {
            printf("%d %d\n", k + 1, lid++);
            continue;
        }
        for (int j = 0; j < t - 1; j++) {
            printf("%d %d\n", id - 1, id), id++;
        }
        printf("%d %d\n", id - 1, lid++);
    }
    return 0;
}

