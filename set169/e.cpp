#include <bits/stdc++.h>
using namespace std;
 
// Dolce Vita
 
void solve(long long int n, long long int x, vector<long long int> arr) {
    // Intuition: Sort prices. Create prefix sum of prices in the input array.
    //            Buy all of the items in the array for as many days as you
    //            can, and add n to the total amount. Once you can't afford
    //            them all, subtract the most expensive store from the sum,
    //            decrement n by 1. Repeat until n = 0.

    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i -1];
    }
    long long int bags = 0ll;
    long long int prev = -1ll;

    // Continue to buy while you can afford any of the bags
    while (n > 0) {
        // Buy them all if possible
        if (x - arr[n - 1] >= 0) {
            // Calculate how many days you can buy all bags
            int days = (x - arr[n - 1]) / n;
            if (days > prev) {
                bags += n * (days - prev);
                prev = days;
            }
        }
        n--;
    }
    
    cout << bags << '\n';
}
 
int main() {
    long long int t;
    long long int n;
    long long int x;
    vector<long long int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> x;
        arr.resize(n);
        for (long long int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, x, arr);
    }
 
    return 0;
}
