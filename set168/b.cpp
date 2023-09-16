#include <bits/stdc++.h>
using namespace std;
 
// Mex Master
 
void solve(int n, vector<int> arr) {
    // Intuition: Count # of zeros in arr. If this # is <= ceil(n / 2),
    //            print 0. Otherwise, if there is any value greater than 1 or all 0,
    //            print 1, since you can push these values to the left, like
    //            [1, 1, 2, 0, 0, 0]. Otherwise, print 2.
    int numZeros = 0;
    int greaterOne = 0;

    for (int i : arr) {
        if (i == 0) {
            numZeros++;
        }
        else if (i > 1) {
            greaterOne++;
        }
    }

    if (n <= 2) {
        if (numZeros == n) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    else if (numZeros <= n / 2 + n % 2) {
        cout << 0 << '\n';
    }
    else if (greaterOne >= 1 || numZeros == n) {
        cout << 1 << '\n';
    }
    else {
        cout << 2 << '\n';
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
