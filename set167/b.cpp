#include <bits/stdc++.h>
using namespace std;
 
// Mainak and Array
 
void solve(int n, vector<int> arr) {
    int out = 0;

    if (n > 1) {
        // Case 1: Rotate min value into first spot
        out = max(out, arr.back() - *min_element(arr.begin(), arr.end() - 1));

        // Case 2: Rotate max value into last spot
        out = max(out, *max_element(arr.begin() + 1, arr.end()) - arr[0]);
        
        // Case 3: Test values right next to each other (rotate entire array)
        for (int i = 0; i < n - 1; i++) {
            out = max(out, arr[i] - arr[i + 1]);
        }
    }

    cout << out << '\n';
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
