#include <bits/stdc++.h>
using namespace std;
 
// Detective Task
 
void solve(string s) {
    // Intuition: Count spots between last 1 and first 0.
    // Find first 0
    int zeroIdx = 0;
    while (zeroIdx < s.size() - 1) {
        if (s[zeroIdx] == '0') {
            break;
        }
        zeroIdx++;
    }
    // Find last 1
    int oneIdx = s.size() - 1;
    while (oneIdx > 0) {
        if (s[oneIdx] == '1') {
            break;
        }
        oneIdx--;
    }
    

    cout << zeroIdx - oneIdx + 1 << '\n';
}
 
int main() {
    int t;
    string s;
 
    cin >> t;
    while (t--) {
        cin >> s;
        solve(s);
    }
 
    return 0;
}
