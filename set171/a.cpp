#include <bits/stdc++.h>
using namespace std;
 
// Make it Beautiful
 
void solve(int n, vector<int> arr) {
    // Intuition: If all elements are equal, print NO. Otherwise, print YES, and print the
    //            smallest value, followed by the rest of the array sorted in descending order.
    sort(arr.begin(), arr.end(), greater<int>());

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            cout << "YES\n";
            cout << arr.back();
            for (int j = 0; j < n - 1; j++) {
                cout << " " << arr[j];
            }
            cout << '\n';
            return;
        }
    }

    cout << "NO\n";
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
