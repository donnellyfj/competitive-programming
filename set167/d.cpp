#include <bits/stdc++.h>
using namespace std;
 
// Binary Inversions
 
void solve(int n, vector<int> arr) {
    // Intuition: Find max between orignal array, changing far left 0 -> 1,
    //            and changing far right 1 -> 0
    int leftZero = min_element(arr.begin(), arr.end()) - arr.begin();
    int rightOne = n - 1 - (max_element(arr.rbegin(), arr.rend()) - arr.rbegin());
    int oneCount = 0;
    long long int out = 0;
    long long int out1 = 0;
    long long int out2 = 0;

    // Original array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            oneCount++;
        }
        else {
            out += oneCount;
        }
    }

    // Change far left 0 -> 1
    oneCount = 0;
    if (arr[leftZero] == 0) {
        arr[leftZero] = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                oneCount++;
            }
            else {
                out1 += oneCount;
            }
        }

        // Restore original array
        arr[leftZero] = 0;
    }

    // Change far right 1 -> 0
    oneCount = 0;
    if (arr[rightOne] == 1) {
        arr[rightOne] = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                oneCount++;
            }
            else {
                out2 += oneCount;
            }
        }
    }

    cout << max({out, out1, out2}) << '\n';
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
