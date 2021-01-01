#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, ans[N], x[N], y[N];
int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		vector<pair<int, int> > v;
		cin >> n;
		int rtr = 0;
		for (int i = 0; i < n; i++) {
			int xx, yy;
			cin >> xx >> yy;
			x[i + 1] = xx, y[i + 1] = yy;
			v.push_back({xx, -(i + 1)});
			v.push_back({yy, (i + 1)});
		}
		sort(v.begin(), v.end());
		set<pair<int, int> > st;
		for (int i = 0; i < v.size(); i++) {
			pair<int, int> p = v[i];
			int rn = p.first;
			if (p.second > 0) {
				st.erase({x[p.second], p.second});
				if (st.size() == 0 && v[i - 1].second == -p.second) {
					ans[p.second]--;
				}
				if (st.size() == 0)
					rtr++;
				if (st.size() == 1) {
					pair<int, int> fr = *st.begin();
					if (v[i + 1].second != fr.second)
						ans[fr.second]++;
				}
 
			}
			else {
				st.insert({rn, -p.second});
			}
		}
		int tl = -1;
		for (int i = 1; i <= n; i++) {
//			cout << "i = " << i << " : " << ans[i] << ", ";
			tl = max(tl, ans[i]);
		}
		cout << rtr + tl << "\n";
		for (int i = 0; i <= n; i++) {
			ans[i] = x[i] = y[i] = 0;
		}
	}
	return 0;
}