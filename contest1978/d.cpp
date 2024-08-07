#include <bits/stdc++.h>
using namespace std;

// Elections

void solve(long long int n, long long int c, vector<long long int> arr) {
    // Intuition: Add to the farthest left available candidate
    long long int currSum = 0;
    arr[0] += c;
    long long int maxVal = *max_element(arr.begin(), arr.end());
    bool maxSeen = false;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        if (arr[i] == maxVal && maxSeen == false) {
            cout << 0 << ' ';
            maxSeen = true;
        }
        else if (currSum >= maxVal) {
            cout << i << ' ';
        }
        else {
            cout << i + 1 << ' ';
        }
    }

    cout << '\n';
}

int main() {
    int t;
    long long int n;
    long long int c;
    vector<long long int> arr;

    cin >> t;
    while (t--) {
        cin >> n >> c;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, c, arr);
    }

    return 0;
}
