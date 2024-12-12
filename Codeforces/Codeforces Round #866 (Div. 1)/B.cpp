#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <utility>
#include <set>
using namespace std;

const int N = 2e5 + 5;

int n;
long long H[N], W[N];
set<pair<long long, long long>> ans;
set<pair<long long, int>> sortH, sortW;

bool solve(bool isH, long long h, long long w) {
    if (h == 0 || w == 0) return true;
    bool removed = false;

    if (isH) {
        long long newW = w;
        while (true) {
            pair<long long, int> hItem = *sortH.lower_bound(make_pair(-h, 0));
            if (hItem.first == -h) {
                removed = true;
                sortH.erase(sortH.lower_bound(hItem));

                pair<long long, int> wItem = make_pair(-W[hItem.second], hItem.second);

                sortW.erase(sortW.lower_bound(wItem));
                newW -= -wItem.first;
            } else {
                break;
            }
        }
        if (removed) return solve(false, h, newW);
    } else {
        long long newH = h;
        while (true) {
            pair<long long, int> wItem = *sortW.lower_bound(make_pair(-w, 0));
            if (wItem.first == -w) {
                removed = true;
                sortW.erase(sortW.lower_bound(wItem));

                pair<long long, int> hItem = make_pair(-H[wItem.second], wItem.second);
                sortH.erase(sortH.lower_bound(hItem));
                newH -= -hItem.first;
            } else {
                break;
            }
        }
        if (removed) return solve(true, newH, w);
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        ans.clear();

        cin >> n;

        long long sum = 0;
        long long maxH = 0, maxW = 0;
        for (int i = 1; i <= n; i++) {
            cin >> H[i] >> W[i];
            sum += H[i] * W[i];
            maxH = max(maxH, H[i]);
            maxW = max(maxW, W[i]);
        }

        if (sum % maxH == 0) {
            sortH.clear(); sortW.clear();
            for (int i = 1; i <= n; i++) {
                sortH.insert(make_pair(-H[i], i));
                sortW.insert(make_pair(-W[i], i));
            }
            bool res = solve(true, maxH, sum / maxH);
            if (res) ans.insert(make_pair(maxH, sum / maxH));
        }

        if (sum % maxW == 0) {
            sortH.clear(); sortW.clear();
            for (int i = 1; i <= n; i++) {
                sortH.insert(make_pair(-H[i], i));
                sortW.insert(make_pair(-W[i], i));
            }
            bool res = solve(false, sum / maxW, maxW);
            if (res) ans.insert(make_pair(sum / maxW, maxW));
        }

        cout << ans.size() << endl;
        for (auto s : ans) {
            cout << s.first << ' ' << s.second << endl;
        }
    }
}
