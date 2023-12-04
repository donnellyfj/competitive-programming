#include <bits/stdc++.h>
using namespace std;
 
// Beautiful Array
 
void solve(long long int n, long long int k, long long int b, long long int s) {
    // Intuition: Start with minimum possible value and add to it
    if (s < k * b || s > k * b + (k - 1) * n) {
        cout << -1 << '\n';
        return;
    }

    vector<long long int> out(n, 0);
    out[0] = k * b;
    long long int currSum = k * b;

    for (int i = 0; i < n; i++) {
        long long int next = min(s - currSum, k - 1);
        if (currSum + next <= s) {
            currSum += next;
            out[i] += next;
        }

        cout << out[i] << ' ';
    }

    cout << '\n';
}
 
int main() {
    int t;
    long long int n;
    long long int k;
    long long int b;
    long long int s;
 
    cin >> t;
    while (t--) {
        cin >> n >> k >> b >> s;
        solve(n, k, b, s);
    }
 
    return 0;
}
