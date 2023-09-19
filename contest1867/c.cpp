#include <bits/stdc++.h>
using namespace std;
 
// Salyg1n and the MEX Game
 
void solve(int n, vector<int> arr) {
    // Intuition: First, add mex of arr. Then, add whatever value is removed
    // Find mex and add it to arr
    int mex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != i) {
            mex = i;
            break;
        }
    }
    // Check if all values 0 to n - 1 are already in arr
    if (mex == -1) {
        mex = n;
    }

    cout << mex << '\n' << flush; // Flush to prevent idleness limit error

    int y;
    cin >> y;
    while (y != -1) {
        cout << y << '\n' << flush; // Flush to prevent idleness limit error
        cin >> y;
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
