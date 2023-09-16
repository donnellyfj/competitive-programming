#include <bits/stdc++.h>
using namespace std;
 
// Binary Inversions
 
void solve(int n, vector<int> arr) {
    // Intuition: Change far left 0 -> 1, and then change far right 1 -> 0,
    //            and also original array, and take the max.
    long long out1 = 0;
    long long out2 = 0;
    long long out3 = 0;

    // Find current value
    int oneCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            oneCount++;
        }
        else {
            out1 += oneCount;
        }
    }

    // Find idx of first 0
    int zeroIdx = min_element(arr.begin(), arr.end()) - arr.begin();

    // Flip first 0 to 1 if possible and calculate # of inversions
    if (arr[zeroIdx] == 0) {
        oneCount = 0;
        arr[zeroIdx] = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                oneCount++;
            }
            else {
                out2 += oneCount;
            }
        }
        // Change 1 back to 0
        arr[zeroIdx] = 0;
    }

    // Find idx of last 1
    int oneIdx = n - 1 - (max_element(arr.rbegin(), arr.rend()) - arr.rbegin());

    // Flip last 1 to 0 if possible and calculate # of inversions
    if (arr[oneIdx] == 1) {
        oneCount = 0;
        arr[oneIdx] = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                oneCount++;
            }
            else {
                out3 += oneCount;
            }
        }
        // Change 0 back to 1
        arr[zeroIdx] = 1;
    }

    cout << max({out1, out2, out3}) << '\n';
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
