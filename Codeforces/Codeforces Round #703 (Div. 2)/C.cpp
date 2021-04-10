#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans, n;

int ask(int l, int r) {
    int res;
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    cin >> res;
    return res;
}

void answer(int l) {
    cout << "! " << l << endl;
    fflush(stdout);
}

void solve(int l, int r, int pos1) {
    if (pos1 == -1) {
        pos1 = ask(l, r);
    }
    int md = (l + r) >> 1;
    if (r - l == 1) {
        if (pos1 == l) answer(r);
        else answer(l);
        return ;
    }
    if (r - l == 2) {
        int pos2 = ask(l, md);
        if (pos2 == pos1) {
            if (pos1 == md) answer(l);
            else answer(md);
        } else if (pos2 == l && pos1 == md) {
            answer(md + 1);
        } else if (pos2 == l && pos1 == md + 1) {
            answer(md);
        } else if (pos2 == md && pos1 == md + 1) {
            answer(l);
        } else if (pos2 == md && pos1 == l) {
            answer(md + 1);
        } 
        return;
    }

    if (pos1 <= md) {
        int pos2 = ask(l, md);
        if (pos2 == pos1) solve(l, md, pos2);
        else solve(md + 1, r, -1);
    } else {
        int pos2 = ask(md + 1, r);
        if (pos2 == pos1) solve(md + 1, r, pos2);
        else solve(l, md, -1);
    }
}

void solve2(int start, bool is_left) {
    if (is_left) {
        int l = 1, r = start - 1, md;
        while (l < r) {
            if (r - l == 1) {
                int tmp1 = ask(r, start);
                int tmp2 = ask(l, start);
                if (tmp1 == start) {
                    ans = r;
                    return;
                } else if (tmp2 == start) {
                    ans = l;
                    return;
                }
            }
            md = (l + r) >> 1;
            int tmp = ask(md, start);
            if (tmp == start) {
                l = md;
                if (l == r) {
                    ans = l;
                    return;
                }
            } else {
                r = md - 1;
            }
        } 
    } else {
        int l = start + 1, r = n, md;
        while (l < r) {
            if (r - l == 1) {
                int tmp1 = ask(start, l);
                int tmp2 = ask(start, r);
                if (tmp1 == start) {
                    ans = l;
                    return;
                } else if (tmp2 == start) {
                    ans = r;
                    return;
                }
            }
            md = (l + r) >> 1;
            int tmp = ask(start, md);
            if (tmp == start) {
                r = md;
                if (l == r) {
                    ans = l;
                    return;
                }
            } else {
                l = md + 1;
            }
        } 
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int initv = ask(1, n);
    //solve(1, n, initv);
    solve2(initv, true);
    if (ans == 0) solve2(initv, false);
    answer(ans);
}

// 5
// 5 1 4 2 3
