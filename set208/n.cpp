#include <bits/stdc++.h>
using namespace std;

// Max Median

void solve(int n, int k, vector<int> arr) {
    // Intuition: Binary search and use prefix sums
    int l = 1;
    int r = n;

    // Binary search for answer
    while (l < r) {
        int m = (l + r + 1) / 2;

        // Change all values less than m to -1, and all values greater or equal to m to 1
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            if (arr[i] < m) {
                temp[i] = -1;
            }
            else {
                temp[i] = 1;
            }
        }

        // Create prefix sum
        for (int i = 1; i < n; i++) {
            temp[i] += temp[i - 1];
        }

        // Find max sum of interval at least size k
        int currMax = temp[k - 1];
        int currMin = 0;
        for (int i = k; i < n; i++) {
            currMin = min(currMin, temp[i - k]);
            currMax = max(currMax, temp[i] - currMin);
        }
        // If max sum is positive, then some median exists
        if (currMax > 0) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    
    cout << l << '\n';
}

int main() {
    int n;
    int k;
    vector<int> arr;

    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, k, arr);

    return 0;
}
