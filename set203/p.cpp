#include <bits/stdc++.h>
using namespace std;

// Complete the Projects (hard version)

bool sortFunc(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second > b.first + b.second;
}

void solve(int n, int r, vector<pair<int, int>> pos, vector<pair<int, int>> neg) {
    // Intuition: First do as many positive projects as you can, then do negative ones with knapsack
    // Sort pos array in increasing order
    sort(pos.begin(), pos.end());
    // Sort neg array in decreasing order of rating change
    sort(neg.begin(), neg.end(), sortFunc);

    // Greedily complete as many positive projects as you can
    int posCompleted = 0;
    for (int i = 0; i < pos.size(); i++) {
        // Complete the project if possible, otherwise skip it
        if (r >= pos[i].first) {
            r += pos[i].second;
            posCompleted++;
        }
        else {
            break;
        }
    }

    // Initialize 2D DP
    vector<vector<int>> dp(neg.size() + 1, vector<int>(r + 1, 0));
    for (int i = 0; i < neg.size(); i++) {
        for (int currRating = 0; currRating <= r; currRating ++) {
            // Try taking the project
            if (currRating >= neg[i].first && currRating + neg[i].second >= 0) {
                int orig = dp[i + 1][currRating + neg[i].second];
                int update = dp[i][currRating] + 1;
                dp[i + 1][currRating + neg[i].second] = max(orig, update);
            }
            // Try not taking the project
            dp[i + 1][currRating] = max(dp[i + 1][currRating], dp[i][currRating]);
        }
    }
    
    // Take max of DP as output
    int negCompleted = 0;
    for (int currRating = 0; currRating <= r; currRating ++) {
        negCompleted = max(negCompleted, dp[neg.size()][currRating]);
    }
    cout << negCompleted + posCompleted << '\n';
}
 
int main() {
    int n;
    int r;
    int a;
    int b;
    vector <pair<int, int>> pos, neg;

    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (b >= 0) {
            pos.push_back({a, b});
        }
        else {
            // Set a to be the max rating required for the project
            a = max(a, abs(b));
            neg.push_back({a, b});
        }
    }
    solve(n, r, pos, neg);

    return 0;
}
