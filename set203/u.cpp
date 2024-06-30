#include <bits/stdc++.h>
using namespace std;

// Decinc Dividing

int n;
vector <int> arr;
// Max element of the decreasing sequence up to i assuming i is part of the increasing sequence
vector <int> dpInc;
// Min element of the increasing sequence up to i assuming i is part of the decreasing sequence
vector <int> dpDec;
vector <int> outVals;

void update(int i) {
    // Return if index out of bounds
    if (i > n) {
        return;
    }

    // Max element of the decreasing sequence assuming i is part of the increasing sequence
    int maxDec = 0;
    // Min element of the increasing sequence assuming i is part of the decreasing sequence
    int minInc = n + 1;

    // If the current array value is greater than the min increasing value at the previous index,
    // update the max decreasing value since arr[i - 1] must be removed
    if (dpDec[i - 1] < arr[i]) {
        maxDec = max(maxDec, arr[i - 1]);
    }
    // If current array value is part of an increasing sequence, update the last seen max final value of
    // the decreasing subsequence
    if (arr[i - 1] < arr[i]) {
        maxDec = max(maxDec, dpInc[i - 1]);
    }
    // If the current array value is smaller than the last seen largest decreasing value, update the min
    // increasing value to the previous array value if necessary
    if (dpInc[i - 1] > arr[i]) {
        minInc = min(minInc, arr[i - 1]);
    }
    // If current array value is part of a decreasing sequence, update the last seen min final value of
    // the increasing subsequence
    if (arr[i - 1] > arr[i]) {
        minInc = min(minInc, dpDec[i - 1]);
    }
    // If no changes were made to either DP array, return
    if (maxDec == dpInc[i] && minInc == dpDec[i]) {
        return;
    }
    // Update DP values
    dpInc[i] = maxDec;
    dpDec[i] = minInc;
    outVals[i] = 0;
    // If a new minimum increasing subsequence or a new maximum decreasing subsequence final value was
    // found, feed the new values up the DP
    if (minInc <= n || maxDec) {
        update(i + 1);
        outVals[i] = outVals[i + 1] + 1;
    }
}

void solve() {
    // Intuition: DP, keep track of increasing and decreasing possibilities
    long long int out = 0;

    // Iterate all possible l values from n to 1
    for (int i = n; i >= 1; i--) {
        dpInc[i] = n + 1;
        dpDec[i] = 0;
        update(i + 1);
        outVals[i] = outVals[i + 1] + 1;
        out += outVals[i];
    }
    
    cout << out << '\n';
}
 
int main() {
    cin >> n;
    arr.resize(n + 2);
    dpInc.resize(n + 2);
    dpDec.resize(n + 2);
    outVals.resize(n + 2);
    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }
    solve();

    return 0;
}
