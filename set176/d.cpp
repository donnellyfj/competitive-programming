#include <bits/stdc++.h>
using namespace std;
 
// Partial Replacement

void solve(int n, int k, string s) {
    // Intuition: Greedily go as far as you can before changing characters.
    int out = 0;
    int currDist = 1;
    int prev = 0;
    
    // Change first/last * to x
    int firstIdx;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            firstIdx = i;
            out++;
            break;
        }
    }
    int lastIdx = firstIdx;
    for (int i = n - 1; i > firstIdx; i--) {
        if (s[i] == '*') {
            lastIdx = i;
            out++;
            break;
        }
    }
    
    // Change values only when k is reached
    for (int i = firstIdx + 1; i < lastIdx; i++) {
        if (s[i] == '*') {
            prev = i;
        }
        if (currDist >= k) {
            out++;
            currDist = i - prev;
        }
        currDist++;
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    int k;
    string s;
 
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        solve(n, k, s);
    }
 
    return 0;
}
