#include <bits/stdc++.h>
using namespace std;
 
// Array Recovery
 
void solve(int n, vector<int> arr) {
    // Intuition: Recover array by generating a partial sum array given the
    //            input array. There is more than one possible answer if any
    //            recovered[i - 1] >= input[i], where i > 1 and input[i] != 0,
    //            since input[i] could have been either positive or negative.
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] >= arr[i] and arr[i] != 0) {
            cout << -1 << '\n';
            return;
        }
        arr[i] += arr[i - 1];
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
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
