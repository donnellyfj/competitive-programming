#include <bits/stdc++.h>
using namespace std;

// Gambling

void solve(int n, vector<int> arr) {
    // Intuition: Track ocurrences of each value, use Kadane's algorithm to find max sum
    map<int, vector<int>> m;
    int a;
    int l;
    int r;
    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        m[arr[i]].push_back(i);
    }

    // Set a to each value in arr (loop through map keys)
    // Create a new array b where b[i] = 1 if arr[i] = a, else b[i] = -1
    // We can ignore values before/after the first/last ocurrences of 1 since we want the max subarray sum
    // Use Kadane's algorithm to find the max subarray sum of this array
    vector<int> b;
    for (auto keyVal = m.begin(); keyVal != m.end(); keyVal++) {
        // Simulate new array b
        vector<int> curr = keyVal -> second;
        b.clear();
        for (int i = 0; i < curr.size(); i++) {
            b.push_back(curr[i]);
            if (i < curr.size() - 1) {
                // Compress all consecutive -1 values into their sum
                b.push_back(-(curr[i + 1] - curr[i] - 1));
            }
        }

        // Kadane's Algorithm
        int currSum = 0;
        int currL = 0;
        for (int currR = 0; currR < b.size(); currR++) {
            if (b[currR] > 0 || currR == 0) {
                currSum += 1;
            }
            else {
                currSum += b[currR];
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                a = keyVal -> first;
                l = b[currL];
                r = b[currR];
            }
            if (currSum < 0) {
                currSum = 0;
                currL = currR + 1;
            }
        }
    }

    cout << a << ' ' << l + 1 << ' ' << r + 1 << '\n';
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
