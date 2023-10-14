#include <bits/stdc++.h>
using namespace std;
 
// Absent Remainder
 
void solve(int n, vector<int> arr) {
    // Intuition: Always include the smallest element
    // Find minimum
    int minVal = *min_element(arr.begin(), arr.end());

    // print pairs
    int counter = 0;
    for (int num : arr) {
        if (counter >= n / 2) {
            break;
        }
        if (num == minVal) {
            continue;
        }
        cout << num << ' ' << minVal << '\n';
        counter += 1;
    }
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
