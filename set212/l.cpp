#include <bits/stdc++.h>
using namespace std;

// Divide and Sum

long long int MOD = 998244353;
int add(long long int x, long long int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   

int mult(long long int a, long long int b) {
    return (a * b) % MOD;
}

int fastPow(long long int a, long long int b) {
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

void solve(long long int n, vector<long long int> arr) {
    // Intuition: All possible costs are the same, so multiply by cost by the number of possible partitions
    long long int numerator = 1;
    long long int denominator = 1;
    long long int cost = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        numerator = mult(numerator, (i + n + 1));
        denominator = mult(denominator, (i + 1));
        cost = add(cost, arr[2 * n - i - 1] - arr[i]);
    }

    // Euler's thrm to get modular multiplicative inverse of factorials
    denominator = fastPow(denominator, MOD - 2);
    cout << mult(mult(numerator, denominator), cost) << '\n';
}

int main() {
    long long int n;
    vector<long long int> arr;

    cin >> n;
    arr.resize(n * 2);
    for (int i = 0; i < n * 2; i++) {
        cin >> arr[i];
    }
    solve(n, arr);

    return 0;
}
