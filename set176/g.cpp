#include <bits/stdc++.h>
using namespace std;
 
// Find The Array

void solve(int n, vector<int> arr) {
    // Intuition: Try arrays alternating with 1 and arr[i].
    long long int sum1 = 0;
    long long int sum2 = 0;
    vector<int> arr1(n);
    vector<int> arr2(n);

    for (int i = 0; i < n; i++) {
        if (i % 2) {
            arr1[i] = arr[i];
            arr2[i] = 1;
        }
        else {
            arr2[i] = arr[i];
            arr1[i] = 1;
        }
        sum1 += abs(arr1[i] - arr[i]);
        sum2 += abs(arr2[i] - arr[i]);
    }
    if (sum1 <= sum2) {
        for (int val : arr1) {
            cout << val << ' ';
        }
    }
    else {
        for (int val : arr2) {
            cout << val << ' ';
        }
    }

    cout << '\n';
}
 
int main() {
    int t;
    int n;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }
 
    return 0;
}
