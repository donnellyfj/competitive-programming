#include <bits/stdc++.h>
using namespace std;
 
// Make it Alternating
 
void solve(string s) {
    // Intuition: Find blocks of adjacent equal elements. Each block will have to be reduced
    //            to 1 element, and there are len(block) ways to do that for each block. By
    //            multiplying all of these values together, we get the number of possible
    //            resulting strings. By multiplying this by the number of permutations of
    //            deleted values, we get the number of ways to make the string alternating.
    
    const int MOD = 998244353;
    int n = s.size();
    vector<int> blockLens = {1};
    char curr = s[0];
    int currLen = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == curr) {
            blockLens.back()++;
        }
        else {
            blockLens.push_back(1);
            curr = s[i];
        }
    }
    
    // Find # of ending strings
    long long int numStrings = 1;
    for (int i : blockLens) {
        numStrings = (numStrings * i) % MOD;
    }
    // Multiply by permutations of deleted values (factorial)
    int numDeleted = s.size() - blockLens.size();
    while (numDeleted) {
        numStrings = (numStrings * numDeleted--) % MOD;
    }

    cout << s.size() - blockLens.size() << ' ' << numStrings << '\n';
}
 
int main() {
    int t;
    int n = 0;
    string s;
 
    cin >> t;
    char temp = 'x';
    while (t--) {
        cin >> s;
        solve(s);
    }
 
    return 0;
}
