#include <bits/stdc++.h>
using namespace std;

// Number of Components

void solve(int n, vector<long long int> arr) {
    // Intuition: Check each value's contribution to the total sum
    long long int out = 0;
    arr.insert(arr.begin(), 0);
    for (int i = 1; i < n + 1; i++) {
        if (arr[i] > arr[i - 1]) {
            // New component starts at arr[i] when arr[i - 1] < l <= arr[i] and r >= arr[i]
            out += (arr[i] - arr[i - 1]) * (n - arr[i] + 1);
        }
        else if (arr[i] < arr[i - 1]) {
            // New component starts at arr[i] when l <= arr[i] and arr[i] <= r < arr[i - 1]
            out += arr[i] * (arr[i - 1] - arr[i]);
        }
    }
    
    cout << out << '\n';
}
 
int main() {
    int n;
    vector <long long int> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, arr);

    return 0;
}
