#include <bits/stdc++.h>
using namespace std;
 
// Prefix Purchase
 
void solve(int n, int k, vector<int> c) {
    // Intuition: Sort prices such that the minimum is first. If two prices are equal, use the one with the
    //            greatest index in the original array. Buy as many as you can with the smallest price.
    //            Then, if you have any money left, see if you can replace any previous purchases with the next price.
    //            Continue until you can't make any more purchases.

    for (int i = n - 2; i >= 0; i--) {
        c[i] = min(c[i], c[i + 1]);
    }

    // Buy first with the minimum price
    int out = k / c[0];
    cout << out << " ";
    // Update k based on previous purchase
    k -= c[0] * out;

    // Check for possible substitutions
    for (int i = 1; i < n; i++) {
        if (c[i] > c[i - 1]) {
            out = min(out, k / (c[i] - c[i - 1]));
            k -= (c[i] - c[i - 1]) * out;
        }
        cout << out << " ";
    }
    cout << '\n';
}
 
int main() {
    int t;
    int n;
    int k;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;
        solve(n, k, arr);
    }
 
    return 0;
}
