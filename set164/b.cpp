#include <bits/stdc++.h>
using namespace std;

// Emordnilap

void solve(int n) {
    long long fact = 1;
    long long singleSum = 0;
    int mod = 1000000007;
    
    for (int i = 1; i < n; i++) {
        singleSum += i;
    }
    singleSum = (singleSum * 2) % mod;

    while (n > 0) {
        fact = fact * n % mod;
        n--;
    }
    cout << (singleSum * fact) % mod << '\n';
}

int main() {
    int t;
    int n;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size: ";
        scanf("%d", &n);

        solve(n);
    }
}