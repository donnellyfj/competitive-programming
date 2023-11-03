#include <bits/stdc++.h>
using namespace std;
 
// Reverse Sort

void solve(int n, string s) {
    // Intuition: Swap all 1's and 0's that are in the wrong places.
    vector<int> idxs;
    int num0s = 0;

    // Count 0s
    for (char val : s) {
        if (val == '0') {
            num0s++;
        }
    }


    for (int i = 0; i < n; i++) {
        if (i < num0s && s[i] == '1') {
            idxs.push_back(i + 1);
        }
        if (i >= num0s && s[i] == '0') {
            idxs.push_back(i + 1);
        }
    }

    if (idxs.size() == 0) {
        cout << 0 << '\n';
        return;
    }

    cout << 1 << '\n';
    cout << idxs.size() << ' ';
    for (int i : idxs) {
        cout << i << ' ';
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
