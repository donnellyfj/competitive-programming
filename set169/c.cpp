#include <bits/stdc++.h>
using namespace std;
 
// Polycarp Recovers the Permutation
 
void solve(int n, vector<int> arr) {
    // Intuition: A solution only exists if the max of the array is either the
    //            first or last element. If this is the case, the reverse of the
    //            array will work as a valid starting array.

    int maxVal = *max_element(arr.begin(), arr.end());

    if (arr[0] != maxVal && arr.back() != maxVal) {
        cout << -1 << '\n';
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
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
