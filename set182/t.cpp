#include <bits/stdc++.h>
using namespace std;
 
// Region Separation

const int MOD = 1000000007;

void solve(int n, vector<long long int> arr, vector<int> p) {
    // Intuition: DP + math
    int out = 0;
    vector<int> f(n + 1);
    vector<int> F(n + 1);

    // arr[i] -> sum of subtree of root i
    // arr[1] -> sum of whole tree
    for(int i = n; i > 1; i--) {
        arr[p[i]] += arr[i];
    }
    
    // arr[i] -> smallest number of regions required to split the tree into subtrees to get the desired
    //           sum (the value of arr[i] before this loop)
	for(int i = n; i > 0; i--) {
        arr[i] = arr[1] / gcd(arr[1], arr[i]);
        // Check to make sure you don't go out of bounds
        if (arr[i] <= n) {
            // f[i] -> number of times a minimum of i regions are required to get the desired sum (the value of arr[i] before this loop)
            f[arr[i]]++;
        }
    }
    
    // F[i] -> Number of ways to get i regions in the last level
    // DP to get f[i] -> the number of subtree sums that are a multiple of arr[1] / i
	for (int i = n; i > 0; i--) {
        for (int j = 2 * i; j <= n; j += i) {
            f[j] += f[i];
        }
    }

    // 1 plan with with the whole kingdom in a single region
    F[1] = 1;
	for (int i = 1; i <=n; i++) {
        // Check if there are i subtree sums that are multiples of arr[1] / i
        if (f[i] == i) {
            // Increase the output with the current number of ways to arrive with F[i] regions in the last level
            out = (out + F[i]) % MOD;
            // Similar DP to before, this time we update all multiples of the current # of regions as a possible second to last level
            for (int j = 2 * i; j <= n; j += i) {
                F[j] = (F[j] + F[i]) % MOD;
            }
        }
    }

	cout << out << '\n';
}

int main() {
    int n;
    vector<long long int> arr;
    vector<int> p;
 
    cin >> n;
    arr.resize(n + 1);
    p.resize(n + 1);
    // Use scanf instead of cin, otherwise TLE!
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    solve(n, arr, p);
 
    return 0;
}
