#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n, q;
int a[N], xorsum[N];
bool vis[N];

void ask(string type, int x, int y) {
    cout << type << " " << x << " " << y << endl;
    fflush(stdout);
}

int receive() {
    int res;
    cin >> res;
    return res;
}

void answer() {
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        ask("XOR", 1, i);
        xorsum[i] = receive();
    }
    map<int, int> state;
    pair<int, int> same_val = make_pair(0, 0);
    for (int i = 2; i <= n; i++) {
        if (state[xorsum[i]] != 0) {
            same_val = make_pair(i, state[xorsum[i]]);
            break;
        }
        if (xorsum[i] == 0) {
            same_val = make_pair(1, i);
            break;
        }
        state[xorsum[i]] = i;
    }
    if (same_val.first == 0) {
        map<int, int> cnt;
        for (int i = 2; i <= n; i++) {
            if (cnt[xorsum[i]] == 0 && cnt[xorsum[i] ^ (n - 1)] == 0) {
                cnt[xorsum[i]] = i;
                cnt[xorsum[i] ^ (n - 1)] = i;
            } else {
                vis[cnt[xorsum[i]]] = true;
                vis[i] = true;
            }
        }
        int single = -1;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) single = i;
        }
        int target = 2;
        if (single == 2) target = 3;
        ask("AND", 1, target);
        int v1 = receive();
        ask("AND", single, target);
        int v2 = receive();
        a[1] = (v1 + v2) ^ xorsum[target];

    } else {
        ask("AND", same_val.first, same_val.second);
        int v = receive();
        a[1] = xorsum[same_val.first] ^ v;
    }
    for (int i = 2; i <= n; i++) {
        a[i] = a[1] ^ xorsum[i];
    }
    answer();
    return 0;
}
