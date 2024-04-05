#include <bits/stdc++.h>
using namespace std;

// Sorting Books

void solve(int n, vector<int> arr) {
    // Intuition: Flip the problem, use dp to find max number of books that can remain stationary.
    vector<int> dp(n + 1, 0);
    vector<int> l(n, n + 1);
    vector<int> r(n, 0);
    vector<int> freq(n, 0);
    vector<int> seen(n, 0);

    // Get first and last occurences of each color
    for (int i = 0; i < n; i++) {
        // Update left index
        if (l[arr[i]] == n + 1) {
            l[arr[i]] = i;
        }

        // Update right index
        r[arr[i]] = i;

        // Update frequency
        freq[arr[i]]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1];
        seen[arr[i]]++;
        // Check if current color is the farthest left index of the color
        if (i == l[arr[i]]) {
            // Move all books except for ones with color i
            dp[i] = max(dp[i], freq[arr[i]] + dp[r[arr[i]] + 1]);
        }
        else {
            // Move all occurences of a[i] to the left of i to the end, then move
            // all books between them to the end to put them together
            dp[i] = max(dp[i], seen[arr[i]]);
        }
    }

    cout << n - dp[0] << '\n';
}

int main() {
    int n;
    vector<int> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
    }
    solve(n, arr);
 
    return 0;
}
