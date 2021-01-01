#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

vector<int> prime;
bool is_not_prime[N];

void sieve() {
    for (int i = 2; i < N; i++) {
        if (is_not_prime[i]) continue;
        prime.push_back(i);
        for (int j = 2 * i; j < N; j += i) {
            is_not_prime[j] = true;
        }
    }
}

int main() {
    int n;

    ios::sync_with_stdio(false);
    cin >> n;
    sieve();
    int cnt = 0;
    while (n >= 4) {
        for (int x : prime) {
            if (x == 2) continue;
            if (n >= x && is_not_prime[n - x] == false) {
                cout <<x << " " <<  n << " " << n - x << endl;

                n = (n - x) - x;
                cnt += 1;
                break;
            }
        }
    } 
    cout << cnt << endl;
    return 0;
}

/*

20
30
40

*/
