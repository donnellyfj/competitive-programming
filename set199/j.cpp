#include <bits/stdc++.h>
using namespace std;

// Required Length

long long int n;
int minOut = INT_MAX;
map<pair<long long int, int>, int> memo;
int dfs(long long int x, int depth) {
    // Check if input values have already been seen
    if (memo.find({x, depth}) != memo.end()) {
        return memo[{x, depth}];
    }
    string xStr = to_string(x);
    if (xStr.length() == n) {
        // Add to memo
        memo[{x, depth}] = depth;
        return depth;
    }
    else if (xStr.length() > n || x <= 1 || depth >= minOut) {
        return INT_MAX;
    }

    // Loop through all substrings
    int out = INT_MAX;
    for (int i = 0; i < xStr.length(); i++) {
        string subStr = xStr.substr(i, 1);
        int subStrVal = stoll(subStr);
        if (subStrVal <= 1) {
            continue;
        }
        out = min(out, dfs(x * subStrVal, depth + 1));
        minOut = min(minOut, out);
    }

    // Add to memo
    memo[{x, depth}] = out;
    return out;
}

void solve(long long int x) {
    // Intuition: Brute force
    int out = dfs(x, 0);
    if (out == INT_MAX) {
        cout << -1 << '\n';
    }
    else {
        cout << out << '\n';
    }
}
 
int main() {
    long long int x;

    cin >> n >> x;
    solve(x);

    return 0;
}
