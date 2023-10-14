#include <bits/stdc++.h>
using namespace std;
 
// Insert a Progression

long long int helper(int n, int x, vector<int> arr) {
    long long int out = __LONG_LONG_MAX__;
    long long int currScore = 0;

    // Get current score
    for (int i = 0; i < n - 1; i++) {
        currScore += abs(arr[i] - arr[i + 1]);
    }

    // Cost of inserting 1 and x at beginning of array
    long long int oneCost = abs(arr[0] - 1);
    out = min(out, currScore + abs(arr[0] - x) + x - 1);
    // Find the best place to insert 1 and x
    for (int i = 0; i < n - 1; i++) {
        // Insert x after arr[i]
        out = min(out, currScore + oneCost - abs(arr[i] - arr[i + 1]) + abs(abs(arr[i] - x)) + abs(x - arr[i + 1]));
        // Insert 1 and x after arr[i]
        out = min(out, currScore + abs(arr[i] - 1) + (x - 1) - abs(arr[i] - arr[i + 1]) + abs(x - arr[i + 1]));
        // Find the best place to put 1
        oneCost = min(oneCost, (long long int) abs(arr[i] - 1) + abs(1 - arr[i + 1]) - abs(arr[i] - arr[i + 1]));
    }
    // Put x at end of array
    out = min(out, currScore + oneCost + abs(arr.back() - x));

    return out;
}
 
void solve(int n, int x, vector<int> arr) {
    // Intuition: Find the best place to insert 1 and x. All insertions between them are free.
    // Try with 1 coming before x
    long long int out = helper(n, x, arr);
    // Try with x coming before 1
    reverse(arr.begin(), arr.end());
    out = min(out, helper(n, x, arr));

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    int x;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> x;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solve(n, x, arr);
    }
 
    return 0;
}
