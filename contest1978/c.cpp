#include <bits/stdc++.h>
using namespace std;

// Manhattan Permutations

void solve(long long int n, long long int k) {
    // Intuition: Build number starting by largest even number and working down
    long long int maxVal = 0;
    vector<long long int> out(n);
    iota(out.begin(), out.end(), 1);
    // Impossible if k is odd
    if (k % 2) {
        cout << "No\n";
        return;
    }
    for (long long int i = 0; i < n; i++) {
        maxVal += abs(out[n - i - 1] - out[i]);
    }
    // Impossible if k > maxVal
    if (k > maxVal) {
        cout << "No\n";
        return;
    }

    // Add largest even number you can and then work down
    long long int currSum = 0;
    long long int l = 0;
    long long int i = n - 1;
    while (i > 0) {
        if (2 * i + currSum <= k) {
            swap(out[l], out[l + i]);
            currSum += 2 * i;
            i -= 2;
            l++;
        }
        else {
            i--;
        }
    }
    
    cout << "Yes\n";
    for (long long int i : out) {
        cout << i << ' ';
    }

    cout << '\n';
}

int main() {
    int t;
    int n;
    int k;


    cin >> t;
    while (t--) {
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}
