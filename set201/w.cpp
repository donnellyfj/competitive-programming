#include <bits/stdc++.h>
using namespace std;

// Guess the number

long long int maxK = 10000;
long long int numQueries = 5;
long long int maxVal = 20000000000000000ll;
vector<vector<long long int>> memo(numQueries + 1, vector<long long int>(maxK + 1));

// dp(q, l) -> max r for [l, r) bound where we are guaranteed to guess the number in q queries
long long int dp(long long int queries, long long l) {
    // If you can't make any more queries, return the current value
    if (queries == 0) {
        return l;
    }
    // Scale numbers down if out of memo bounds
    if (l > maxK) {
        return min(maxVal, dp(queries, maxK) + l - maxK);
    }
    // Return value if stored in memo
    if (memo[queries][l] != 0) {
        return memo[queries][l];
    }
    // Initialize output r value as l
    long long out = l;
    // Scale left bound from 0 up to l
    for (int i = 0; i < l; i++) {
        // In the case that the target number is between query[i] and query[i + 1],
        // you need to be able to the number in queries - 1 guesses
        out = dp(queries - 1, out);
        out++;
    }
    // Calculate the r bound
    out = dp(queries - 1, out);
    memo[queries][l] = min(maxVal, out);
    return memo[queries][l];
}

int main() {
    // Intuition: Use DP to find largest interval you can guess and guarantee getting the answer
    long long int l = 1;
    long long int r = dp(numQueries, 1);
    // Make quesses
    for (int qRemaining = numQueries - 1; qRemaining >= 0; qRemaining--) {
        // Build values to guess
        vector<long long int> query;
        long long int currL = l;
        for (int i = 0; i < min(l, maxK); i++) {
            long long int end = dp(qRemaining, currL);
            query.push_back(end);
            currL = end + 1;
        }
        // Make guess
        cout << query.size() << '\n';
        for (long long int val : query) {
            cout << val << ' ';
        }
        cout << '\n';
        cout.flush();

        // Read response
        long long int response;
        cin >> response;
        // Terminate program
        if (response < 0) {
            return 0;
        }
        // Adjust l to new interval
        if (response > 0) {
            l = query[response - 1] + 1;
        }
        // Adjust r to new interval
        if (response != query.size()) {
            r = query[response];
        }
    }

    return 0;
}
