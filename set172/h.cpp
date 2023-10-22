#include <bits/stdc++.h>
using namespace std;
 
// Diluc and Kaeya
 
void solve(int n, string s) {
    // Intuition: Reduce ratios to simplest form, and keep track of how many times you've seen each ratio
    map<pair<int, int>, int> seen;
    int numD = 0;
    int numK = 0;

    for (char c : s) {
        if (c == 'D') {
            numD++;
        }
        else {
            numK++;
        }
        int d = numD / int(gcd(numD, numK));
        int k = numK / int(gcd(numD, numK));
        if (seen.find({d, k}) == seen.end()) {
            seen[{d, k}] = 0;
        }
        seen[{d, k}]++;
        cout << seen[{d, k}] << " ";
    }

    cout << '\n';
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
