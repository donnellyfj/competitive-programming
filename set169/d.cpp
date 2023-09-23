#include <bits/stdc++.h>
using namespace std;
 
// Palindromic Numbers
 
void solve(int n, vector<int> arr) {
    // Intuition: If leading digit isn't 9, then output the value needed
    //            to make the number all 9s. Otherwise, output the value
    //            needed to make the number all 1s at size n + 1.

    if (arr[0] != 9) {
        // Print the value needed to make a number of n 9s, aka 9 - a[i]
        for (int i  = 0; i < n; i++) {
            cout << 9 - arr[i];
        }
    }
    else {
        // Print the value needed to make a number of n + 1 1s,
        // aka 10 - a[i] with 1 added at the very end
        for (int i  = 0; i < n; i++) {
            arr[i] = 10 - arr[i];
        }
        
        // Add 1 to the end and handle any carrries
        arr[n - 1] += 1;
        for (int i  = n - 1; i >= 1; i--) {
            if (arr[i] >= 10) {
                arr[i] -= 10;
                arr[i - 1] += 1;
            }
        }

        // Print final value
        for (int i = 0; i < n; i++) {
            cout << arr[i];
        }
    }
        cout << '\n';
}
 
int main() {
    int t;
    int n;
    vector<int> arr;
    char temp;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> temp;
            arr[i] = int(temp - '0');
        }
        solve(n, arr);
    }
 
    return 0;
}
