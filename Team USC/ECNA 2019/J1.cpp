#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;


struct work {
    int books;
    int deadline;
    bool operator < (struct work w) const {
        return deadline < w.deadline;
    }
} w[N];
int n, k;

bool check(long long val) {
    long long sum = 0;
    int cnt_failed_works = 0;
    priority_queue<pair<int, int>> Q;

    for (int i = 1; i <= n; i++) {
        sum += w[i].books;
        Q.push({w[i].books, w[i].deadline});
        while ((sum + w[i].deadline - 1)/ w[i].deadline > val) {
            sum -= Q.top().first;
            Q.pop();
            cnt_failed_works += 1;
        }
    }
    if (cnt_failed_works <= k) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i].books >> w[i].deadline;
    }
    sort(w + 1, w + 1 + n);
    long long l = 1, r = 1e15, md;
    for (int i = 0; i < 51; i++) {
        md = (l + r) >> 1;
        if (check(md)) r = md;
        else l = md + 1;
    }
    cout << r << endl;
    return 0;
}