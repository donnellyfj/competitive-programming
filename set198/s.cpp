#include <bits/stdc++.h>
using namespace std;

// Omkar and Amkar

const int MOD = 1e9 + 7;
const int MAXVAL = 2e6 + 10;
vector<long long int> fact(MAXVAL);
vector<long long int> factInverse(MAXVAL);

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

int comb(int n, int r) {
    if (n < r || r < 0 || n < 0) {
        return 0;
    }
    int numerator = fact[n];
    numerator = mult(numerator, factInverse[r]);
    numerator = mult(numerator, factInverse[n - r]);
    return numerator;
}

void solve(long long int n) {
    // Intuition: Player 2 always wins, calculate combinations of where to place empty spaces.
    long long int out = 0;
    
    // Iterate all possible numbers of empty spaces
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 1) {
            continue;
        }
        int temp = add(comb(i, n - i), comb(i - 1, n - i - 1));
        temp = mult(2, temp);
        temp = mult(temp, fact[i]);

        out = add(out, temp);
    }

    cout << out << '\n';
}

int main() {
    long long int n;

    // Precompute factorial values and their inverses
    fact[0] = 1;
    for (int i = 1; i < MAXVAL; i++) {
        fact[i] = mult(fact[i - 1], i);
    }
    factInverse[0] = 1;
    for (int i = 1; i < MAXVAL; i++) {
        // Euler's thrm to get modular multiplicative inverse of factorials
        factInverse[i] = fastPow(fact[i], MOD - 2);
    }

    cin >> n;
    solve(n);
 
    return 0;
}
