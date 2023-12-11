#include <bits/stdc++.h>
using namespace std;
 
// Color with Occurrences

void solve(string s, int n, vector<string> arr) {
    // Intuition: Brute force, add the word that exends the prefix of red letters the most.
    // Keep track of firat index that isn't red
    int i = 0;
    int nxtI = i;
    vector<vector<int>> out;

    // Iterate while whole string isn't red
    while (i < s.size()) {
        // Try to fit all of the words in arr onto t, keeping track of the one that colors
        // the most new characters red
        vector<int> curr = {-1, -1};
        for (int wordIdx = 0; wordIdx < n; wordIdx++) {
            string word = arr[wordIdx];
            for (int j = max(0, i - int(word.size()) + 1); j <= i; j++) {
                if (j + word.size() <= s.size() && word == s.substr(j, word.size())) {
                    if (j + word.size() > nxtI) {
                        curr[0] = wordIdx + 1;
                        curr[1] = j + 1;
                        nxtI = j + word.size();
                    }
                }
            }
        }
        // Check if no new characters were colored red
        if (i == nxtI) {
            cout << -1 << '\n';
            return;
        }

        out.push_back(curr);
        i = nxtI;
    }

    // Print output indices
    cout << out.size() << '\n';
    for (vector<int> vals : out) {
        cout << vals[0] << ' ' << vals[1] << '\n';
    }
}
 
int main() {
    int t;
    string s;
    int n;
    vector<string> arr;
 
    cin >> t;
    while (t--) {
        cin >> s >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(s, n, arr);
    }
 
    return 0;
}
