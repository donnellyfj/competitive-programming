#include <bits/stdc++.h>
using namespace std;

// Making Towers

void naiveTLE(int n, vector<int> arr) {
    vector<int> maxHeight(n);
    int currColor;
    int parity;
    int currHeight;

    for (int color = 1; color <= n; color++) {
        for (int i = 0; i < n; i++) {
            currColor = arr[i];
            parity = i % 2;
            currHeight = 1;
            for (int j = i; j < n; j++) {
                if (arr[j] == currColor && j % 2 != parity) {
                    parity = j % 2;
                    currHeight += 1;
                }
            }
            maxHeight[currColor - 1] = max(maxHeight[currColor - 1], currHeight);
        }
    }

    // Display results
    for (int color = 0; color < n; color++) {
        cout << maxHeight[color] << ' ';
    }
    cout << '\n';
}

void solveDP (int n, vector<int> arr) {
    vector<vector<int>> dp(2, vector<int> (n, 0));
    int currColor;
    int parity;
    for (int i = 0; i < n; i++) {
        currColor = arr[i];
        parity = i % 2;
        dp[parity][currColor - 1] = max(dp[parity][currColor - 1], dp[(parity + 1) % 2][currColor - 1] + 1);
    }

    // Display results
    for (int color = 0; color < n; color++) {
        cout << max(dp[0][color], dp[1][color]) << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    int n;
    vector<int> arr;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size: ";
        scanf("%d", &n);
        arr.resize(n);
        // cout << "Input array: ";
        for (int idx = 0; idx < n; idx++) {
            scanf("%d", &arr[idx]);
        }

        solveDP(n, arr);
    }
}