#include <bits/stdc++.h>
using namespace std;

// Program

void solve(int n, int m, vector<int> arr, vector<int> lArr, vector<int> rArr) {
    // Intuition: Find max/min value for each prefix, as well as max/min future value for each suffix
    vector<int> prefix = arr;
    for (int i = 1; i < n; i++) {
        prefix[i] += prefix[i - 1];
    }

    vector<int> maxPrefix(n, 0);
    vector<int> minPrefix(n, 0);
    maxPrefix[0] = max(arr[0], 0);
    minPrefix[0] = min(arr[0], 0);
    for (int i = 1; i < n; i++) {
        maxPrefix[i] = max(maxPrefix[i - 1], prefix[i]);
        minPrefix[i] = min(minPrefix[i - 1], prefix[i]);
    }

    vector<int> maxSuffix(n, 0);
    vector<int> minSuffix(n, 0);
    maxSuffix.back() = max(arr.back(), 0);
    minSuffix.back() = min(arr.back(), 0);
    for (int i = n - 2; i >= 0; i--) {
        maxSuffix[i] = max(arr[i] + maxSuffix[i + 1], 0);
        minSuffix[i] = min(arr[i] + minSuffix[i + 1], 0);
    }

    // Process queries
    for (int i = 0; i < m; i++) {
        int l = lArr[i] - 1;
        int r = rArr[i] - 1;
        int currMax = 0;
        int currMin = 0;
        if (l > 0) {
            currMax = max(currMax, maxPrefix[l - 1]);
            currMin = min(currMin, minPrefix[l - 1]);
        }
        if (r < n - 1) {
            int lastVal = 0;
            if (l > 0) {
                lastVal = prefix[l - 1];
            }
            currMax = max(currMax, maxSuffix[r + 1] + lastVal);
            currMin = min(currMin, minSuffix[r + 1] + lastVal);
        }

        cout << currMax - currMin + 1 << '\n';
    }
}

int main() {
    int t;
    int n;
    int m;
    vector<int> arr;
    vector<int> lArr;
    vector<int> rArr;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.resize(n);
        lArr.resize(m);
        rArr.resize(m);
        for (int i = 0; i < n; i++) {
            char temp;
            cin >> temp;
            if (temp == '+') {
                arr[i] = 1;
            }
            else if (temp == '-') {
                arr[i] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> lArr[i] >> rArr[i];
        }
        solve(n, m, arr, lArr, rArr);
    }

    return 0;
}
