#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
string s;

int main() {
    cin >> n;
    cin >> s;
    
    int sum = 0;

    priority_queue<int> heap;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i] - '0';
        heap.push(-(s[i] - '0'));
    }
    int cnt = 0;
    while (sum < n) {
        int x = -heap.top();
        heap.pop();
        cnt += 1;
        sum += 9 - x;
    }
    cout << cnt << endl;
    return 0;
}