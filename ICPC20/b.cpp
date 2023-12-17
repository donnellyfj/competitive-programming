#include <bits/stdc++.h>
using namespace std;
 
// Prinzessin der Verurteilung

void solve(int n, string s) {
    // Intuition: Brute force check increasing mex sequence
    string out = "a";
    // Cycle through minimal combinations of letters
    while (true) {
        while (true) {
            for (int j = 0; j < 26; j++) {
                if (s.find(out) == string::npos) {
                    cout << out << '\n';
                    return;
                }
                out.back()++;
            }
            int idx = out.size() - 1;
            while (idx >= 0 && out[idx] >= 'z') {
                out[idx] = 'a';
                idx--;
            }
            if (idx < 0) {
                break;
            }
            out[idx]++;
        }
        out = string(out.size() + 1, 'a');
    }
}
 
int main() {
    int t;
    int n;
    string s;
 
    cin >> t;
    while (t--) {
        cin >> n >> s;
        solve(n, s);
    }
 
    return 0;
}
