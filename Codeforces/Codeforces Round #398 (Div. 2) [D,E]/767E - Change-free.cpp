#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

template<class T>
class FenwickTree {
public:
    FenwickTree(int n):
        tree(n + 1, 0) {}

    void update(int pos, T value) {
        for (++pos; pos < SZ(tree); pos += pos & -pos) {
            tree[pos] += value;
        }
    }
    T query(int pos) {
        T ret = 0;
        for (++pos; pos > 0; pos -= pos & -pos) {
            ret += tree[pos];
        }
        return ret;
    }
    T query(int left, int right) {
        return query(right) - query(left - 1);
    }
private:
    vector<T> tree;
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<int> all = A;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    vector<int> lmax(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        lmax[i] = max(lmax[i - 1], A[i]);
    }

    vector<int64_t> fans(n + 1, 0);
    FenwickTree<int> count(n + 1);
    FenwickTree<int64_t> sum(n + 1);
    int64_t totalSum = 0;
    int totalCount = 0;
    for (int i = n; i > 0; --i) {
        int ind = lower_bound(all.begin(), all.end(), A[i]) - all.begin();
        totalCount++;
        totalSum += A[i];
        count.update(ind, 1);
        sum.update(ind, A[i]);
        if (lmax[i - 1] >= A[i]) {
            fans[i] = 0;
        } else {
            int ccount = totalCount - count.query(ind);
            int xind = lower_bound(all.begin(), all.end(), lmax[i - 1])
                - all.begin();
            fans[i] = (int64_t) ccount * (A[i] - lmax[i - 1]);
            ccount = count.query(xind, ind);
            int64_t csum = sum.query(xind, ind);
            fans[i] += csum - (int64_t) ccount * lmax[i - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << fans[i] << '\n';
    }
}
/*

10
2 3 5 8 6 21 123 78 153 1000

20
9
16
19
0
65
363
0
60
847
*/
