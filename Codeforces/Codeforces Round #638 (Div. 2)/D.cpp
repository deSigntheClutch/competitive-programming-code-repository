#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        vector<int> bact_n;
        int start = 1;
        bact_n.push_back(1);
        int sum = 1;
        for (int i = 1; ; i++) {
            if (sum + start > x) {
                sum -= bact_n[bact_n.size() - 1];
                bact_n.pop_back();
                break;
            }           
            start += start;
            bact_n.push_back(start);
            sum += start;
        }
        int diff = x - sum;
        int last = bact_n[bact_n.size() - 1];
        if (diff <= 2 * last && diff >= last) bact_n.push_back(diff);
        else {
            bact_n.push_back(diff / 2);
            bact_n.push_back(diff - diff / 2);
        }
        cout << (int)bact_n.size() - 1 << endl;
        for (int i = 1; i < bact_n.size(); i++) {
            cout << bact_n[i] - bact_n[i - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}