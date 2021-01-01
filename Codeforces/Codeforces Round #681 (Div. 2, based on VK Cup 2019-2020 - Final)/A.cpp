#include <bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << 4 << " " << 6 << endl;
            continue;
        }
        int val = 2 * n;
        for (int i = 1; i <= n; i++)
        {
            cout << val << " ";
            val += 2;
        }
        cout << endl;
    }
    return 0;
}
