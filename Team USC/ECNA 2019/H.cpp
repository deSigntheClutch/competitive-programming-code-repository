#include<bits/stdc++.h>
using namespace std;

typedef int ll;

const int N = 1e6 + 10;

int a, b, c, d, e, f, g;

signed main(){
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d >> e >> f >> g;
    vector<pair<int, int>> boxes;
    for (int i = 1; i <= min(a, b); i++) {
        int width = a - 2 * i;
        ll length = b - 2 * i;
        ll height = i;
        if (width <= 0 || height <= 0|| length <= 0) continue;
        boxes.push_back({width * height * length, i});
    }
    sort(boxes.begin(), boxes.end());
    reverse(boxes.begin(), boxes.end());
    int b = (f - c + boxes[0].first - 1) / boxes[0].first;

    for (int i = b*boxes[0].first + c; i <= g; i += boxes[0].first) {
        //cout << i << endl;
        if (i % boxes[1].first == d && i % boxes[2].first == e) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}