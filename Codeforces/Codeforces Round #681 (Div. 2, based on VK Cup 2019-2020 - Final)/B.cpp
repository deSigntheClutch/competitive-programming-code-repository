#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cin >> s;
        int ans = 0;
        int delta = ceil(1.0 * a / b);
        int blocks = 0, conn = 0, fill = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                continue;
            int pt = i;
            blocks += 1;
            while (pt < s.length() && s[pt] == '1')
                pt++;
            if (pt == s.length())
                break;
            int kpt = pt;
            while (kpt < s.length() && s[kpt] == '0')
                kpt++;
            if (kpt == s.length())
                break;
            int num = kpt - pt;

            if (num < delta)
            {
                conn += 1;
                fill += num;
            }

            i = kpt - 1;
        }
        //cout << fill << " " << blocks  << " " << conn << endl;
        cout << fill * b + (blocks - conn) * a << endl;
    }
    return 0;
}
