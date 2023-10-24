#include <bits/stdc++.h>
using namespace std;
 
// Hossam and Combinatorics
 
void solve(long long int n, vector<int> arr) {
    // Intuition: Count # of times the max and min appear in the string.
    long long int maxCount = 0;
    long long int minCount = 0;
    int currMax = -1;
    int currMin = 1000000;

    for (int val : arr) {
        if (val > currMax) {
            currMax = val;
            maxCount = 1;
        }
        else if (val == currMax) {
            maxCount++;
        }
        if (val < currMin) {
            currMin = val;
            minCount = 1;
        }
        else if (val == currMin) {
            minCount++;
        }
    }

    if (currMax - currMin == 0) {
        cout << n * (n - 1) << '\n';
    }
    else {
        cout << maxCount * minCount * 2 << '\n';
    }
}
 
int main() {
    int t;
    int n;
    int x;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }
 
    return 0;
}
