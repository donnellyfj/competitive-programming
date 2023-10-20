#include <bits/stdc++.h>
using namespace std;
 
// Good Kid
 
void solve(int n, vector<int> arr) {
    // Intuition: Add 1 to smallest number.
    *min_element(arr.begin(), arr.end()) += 1;
    long long out = 1;
    for (int val : arr) {
        out *= val;
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
