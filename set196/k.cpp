#include <bits/stdc++.h>
using namespace std;

// Infinite Set

int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

void solve(int n, int p, vector<int> arr) {
    // Intuition: Remove redundant numbers, split into powers of 2, and do DP.
    set<int> vals;
    vector<int> pow2Bins(p, 0);
    vector<int> dp(p, 0);
    int out = 0;
    sort(arr.begin(), arr.end());

    // Remove redundant numbers: for each value, see if it could've been creted by a previous number
    for (int num : arr) {
        int temp = num;
        bool redundant = false;
        int logNum = log2(num);

        // Exit if current number is greather than or equal to 2^p
        if (logNum >= p) {
            break;
        }

        while (temp > 0) {
            // Check if current value as already been seen, making num redundant
            if (vals.find(temp) != vals.end()) {
                redundant = true;
                break;
            }

            // Check if number is odd (temp = 2 * parent + 1)
            if (temp % 2) {
                temp = (temp - 1) / 2;
            }
            // Check if number is divisible by 4 (temp = 4 * parent)
            else if (temp % 4 == 0) {
                temp /= 4;
            }
            // temp is divisble by 2 but not 4, meaning it isn't redundant, as it has no possible parents
            else {
                break;
            }
        }

        // Insert num into vals if not redundant
        if (!redundant) {
            vals.insert(num);
            // Increment number of values in current power of 2
            pow2Bins[logNum]++;
        }
    }

    // DP based on how many values exist in each power of 2 bin, and sum to find output
    for (int i = 0; i < p; i++) {
        if (i >= 1) {
            dp[i] = add(dp[i], dp[i - 1]);
        }
        if (i >= 2) {
            dp[i] = add(dp[i], dp[i - 2]);
        }
        dp[i] = add(dp[i], pow2Bins[i]);
    }

    // Sum values in dp
    for (int val : dp) {
        out = add(out, val);
    }

    cout << out << '\n';
}

int main() {
    int n;
    int p;
    vector<int> arr;
 
    cin >> n >> p;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, p, arr);
 
    return 0;
}
