#include <bits/stdc++.h>
using namespace std;
 
// Chat Ban

long long int gSum(long long int n) {
    return n * (n + 1) / 2;
}

long long int binSearchFirst(long long int k, long long int x) {
    long long int l = 0;
    long long int r = k;
    long long int m;

    // Find first message that breaks x
    while (l < r) {
        m = (l + r) / 2;
        if (gSum(m) < x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }

    return l;
}

long long int binSearchSecond(long long int k, long long int x) {
    long long int l = 0;
    long long int r = k;
    long long int m;
    long long int firstHalf = gSum(k);

    // Find first message that breaks x
    while (l < r) {
        m = (l + r + 1) / 2;
        if (2 * firstHalf - k - gSum(m) < x) {
            r = m - 1;
        }
        else {
            l = m;
        }
    }

    return 2 * k - 1 - l;
}

void solve(long long int k, long long int x) {
    // Intuition: Binary search using Gaussian sum
    long long int out = 0;

    // Check and see if you can make it to the halfway point
    long long int check = gSum(k);
    // cout << gSum(k) << '\n';
    if (check >= x) {
        // cout << "first\n";
        out = binSearchFirst(k, x);
    }
    else {
        out = binSearchSecond(k, x);
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    long long int k;
    long long int x;
    vector<long long int> arr;
 
    cin >> t;
    while (t--) {
        cin >> k >> x;
        solve(k, x);
    }
 
    return 0;
}
