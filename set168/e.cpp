#include <bits/stdc++.h>
using namespace std;
 
// Prefix Sum Addicts
 
void solve(int n, int k, vector<long long int> arr) {
    // Intuition: Use the last k prefix sums to find the last k - 1
    //            elements in the array. If the element k - 1 from the end
    //            multiplied by the # of elements remaining is greater than or
    //            equal to the first prefix sum in arr, print YES, otherwise NO.

    // Trivial case, k = 1, then there is always an array
    if (k == 1) {
        cout << "YES\n";
        return;
    }

    vector<long long int> a;
    for (int i = 0; i < k - 1; i++) {
        a.push_back(arr[i + 1] - arr[i]);
    }

    // Verify array is sorted
    for (int i = 0; i < k - 2; i++) {
        if (a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }

    // Check if the remaining prefix sum can be created with elements less than or
    // equal to the first element in array
    if (arr[0] <= a[0] * (n - k + 1)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main() {
    int t;
    int n;
    int k;
    vector<long long int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> k;
        arr.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        solve(n, k, arr);
    }
 
    return 0;
}
