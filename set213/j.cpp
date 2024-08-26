#include <bits/stdc++.h>
using namespace std;

// Training Session

void solve(long long int n, vector<long long int> a, vector<long long int> b) {
    // Intuition: Find number of ways to choose 3 problems and subtract the illegal groups of 3
    long long int out = n * (n - 1) * (n - 2) / 6;
    vector<long long int> topicCounts(n + 1, 0);
    vector<long long int> diffCounts(n + 1, 0);
    // Count occurrences of each topic/difficulty
    for (int i = 0; i < n; i++) {
        topicCounts[a[i]]++;
        diffCounts[b[i]]++;
    }
    
    // Count illegal triples given (a[i], b[i]) is used
    for (int i = 0; i < n; i++) {
        out -= (topicCounts[a[i]] - 1) * (diffCounts[b[i]] - 1);
    }

    cout << out << '\n';
}

int main() {
    int t;
    long long int n;
    vector<long long int> a;
    vector<long long int> b;

    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        solve(n, a, b);
    }

    return 0;
}
