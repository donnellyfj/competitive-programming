#include <bits/stdc++.h>
using namespace std;
 
// Partial Replacement

void solve(int n, int k, string s) {
    // Intuition: Greedily go as far as you can before replacing.
    int firstIdx;
    int out = 0;

    // Replace first and last * with x
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            s[i] = 'x';
            firstIdx = i;
            out++;
            break;
        }
    }
    int lastIdx = firstIdx;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '*') {
            s[i] = 'x';
            lastIdx = i;
            out++;
            break;
        }
    }

    int currDist = 0;
    int prevIdx = 0;
    for (int i = firstIdx; i <= lastIdx; i++) {
        if (s[i] == 'x') {
            currDist = 0;
        }
        if (s[i] == '*') {
            prevIdx = i;
        }
        if (currDist >= k) {
            s[prevIdx] = 'x';
            currDist = i - prevIdx;
            out++;
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
