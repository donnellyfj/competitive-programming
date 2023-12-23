#include <bits/stdc++.h>
using namespace std;
 
// Radio Towers

const int MOD = 998244353;

int mult(int a, int b) {
    return (1ll * a * b) % MOD;
}

int fastPow(int a, int b) {
    int out = 1;
    while (b > 0) {
        if (b % 2) {
            out = mult(out, a);
        }
        b /= 2;
        a = mult(a, a);
    }

    return out;
}

void solve(int n) {
    // Intuition: Number of ways to split n into a sum of odd numbers is the n-th Fibonacci number.
    vector<int> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    int numWays = fib.back();
    int totalWays = fastPow(2, n);
    int denominator = fastPow(totalWays, MOD - 2);

    cout << mult(numWays, denominator) << '\n';
}
 
int main() {
    int n;
 
    cin >> n;
    solve(n);
 
    return 0;
}
