#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 2e5 + 5;

pair<int, int> food[N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> food[i].first;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> food[i].second;
        }
        sort(food + 1, food + 1 + n);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += food[i].second;
        }
        int ans = sum;
        for (int i = 1; i <= n; i++) {
            sum -= food[i].second;
            ans = min(ans, max(food[i].first, sum));
        }
        cout << ans << endl;
    }
    return 0;
}
