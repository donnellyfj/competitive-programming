#include <bits/stdc++.h>
using namespace std;

// Almost Triple Deletions

void solve(int n, vector<int> arr) {
    // Intuition: DP where dp[i] represents the longest array possible from the
    //            prefix of size i of the input array while including arr[i]
    int out = 0;
    vector<int> dp(n + 1, 0);
    vector<int> freqs(*max_element(arr.begin(), arr.end()) + 1);
    int maxFreq = 0;
    for (int i = 0; i < n + 1; i++) {
        // Skip if no array is possible
        if (i && dp[i] == 0) {
            continue;
        }
        // Reset frequencies to 0
        maxFreq = 0;
        fill(freqs.begin(), freqs.end(), 0);
        
        // Calculate DP
        for (int j = i + 1; j < n + 1; j++) {
            // Check if the values betweein arr[i] and arr[j] can be deleted
            // If i = 0, then try deleting all values before arr[i]
            if ((j - i) % 2 && maxFreq <= (j - i) / 2 && (i == 0 || arr[i] == arr[j])) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
            // Update maximum frequency of values from i to j
            freqs[arr[j]]++;
            maxFreq = max(maxFreq, freqs[arr[j]]);
        }
    }

    // Work backwards to see if you can delete all values from arr[i + 1] to n
    // Reset frequencies to 0
    maxFreq = 0;
    fill(freqs.begin(), freqs.end(), 0);
    for (int i = n; i >= 0; i--) {
        if ((n + 1 - i) % 2 && maxFreq <= (n + 1 - i) / 2) {
            out = max(out, dp[i]);
        }
        freqs[arr[i]]++;
        maxFreq = max(maxFreq, freqs[arr[i]]);
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
        arr.resize(n + 1);
        for (int i = 1; i < n + 1; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }

    return 0;
}
