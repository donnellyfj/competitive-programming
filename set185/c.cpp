#include <bits/stdc++.h>
using namespace std;

// Fun with Even Subarrays

void solve(int n, vector<int> arr) {
    // Intuition: Double the suffix of numbers equal to the last element in arr until the whole
    //            array equals the last element.
    int suffixLen = 0;

    // Double the size of the suffix until all elements are equal
    int out = 0;
    while (suffixLen < n) {
        // Find first element from the end of arr not equal to the last element
        for (int i = n - 1 - suffixLen; i >= 0; i--) {
            if (arr[i] != arr.back()) {
                break;
            }
            suffixLen++;
        }

        if (suffixLen < n) {
            out++;
        }
        suffixLen *= 2;
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
