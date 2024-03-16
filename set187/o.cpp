#include <bits/stdc++.h>
using namespace std;

// Divisor Paths

const int MOD = 998244353;
vector<long long int> primes;
vector<long long int> fact(100);
vector<long long int> factInverse(100);

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   

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

void solve(long long int x, long long int y) {
    // Intuition: Get prime factors, find paths to/from GCD for each query.
    long long int out = 0;
    vector<long long int> xToGCD;
    vector<long long int> gcdToY;

    // To find paths to/from GCD, find out how many of d's prime factors need to be added/removed
    for (long long int prime : primes) {
        int count = 0;
        while (x % prime == 0) {
            x /= prime;
            count--;
        }
        while (y % prime == 0) {
            y /= prime;
            count++;
        }

        if (count < 0) {
            xToGCD.push_back(-count);
        }
        else {
            gcdToY.push_back(count);
        }
    }

    // Permutation with repetitions (multinomial coefficients)
    long long int out1 = fact[accumulate(xToGCD.begin(), xToGCD.end(), 0)];
    for (long long int val : xToGCD) {
        out1 = mult(out1, factInverse[val]);
    }

    long long int out2 = fact[accumulate(gcdToY.begin(), gcdToY.end(), 0)];
    for (long long int val : gcdToY) {
        out2 = mult(out2, factInverse[val]);
    }

    out = mult(out1, out2);

    cout << out << '\n';
}

int main() {
    long long int d;
    long long int t;
    long long int x;
    long long int y;

    // Precompute factorial values and their inverses
    fact[0] = 1;
    for (int i = 1; i < 100; i++) {
        fact[i] = mult(fact[i - 1], i);
    }
    factInverse[0] = 1;
    for (int i = 1; i < 100; i++) {
        // Euler's thrm to get modular multiplicative inverse of factorials
        factInverse[i] = fastPow(fact[i], MOD - 2);
    }

    cin >> d >> t;
    // Get prime factors of d
    for (long long int i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            primes.push_back(i);
            while (d % i == 0) {
                d /= i;
            }
        }
    }

    if (d > 1) {
        primes.push_back(d);
    }

    while (t--) {
        cin >> x >> y;
        solve(x, y);
    }
 
    return 0;
}
