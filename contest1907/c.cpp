#include <bits/stdc++.h>
using namespace std;
 
// Removal of Unattractive Pairs
 
void solve(int n, string arr) {
    // Intuition: Count number of most often occurring char
    int maxCount = 0;
    unordered_map<char, int> counts;
    for (int i = 0; i < n; i++) {
        counts[arr[i]]++;
        maxCount = max(maxCount, counts[arr[i]]);
    }

    int out = max(0, maxCount - (n - maxCount));
    if (out == 0 && n % 2) {
        out++;
    }
    
    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    string str;
 
    cin >> t;
    while (t--) {
        cin >> n >> str;
        solve(n, str);
    }
 
    return 0;
}
