#include <bits/stdc++.h>
using namespace std;
 
// YetnotherrokenKeoard
 
void solve(string arr) {
    // Intuition: Add/delete elememnts from vector
    vector<int> lower;
    vector<int> upper;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 'b') {
            // Remove last lowercase
            if (!lower.empty()) {
                lower.pop_back();
            }
        }
        else if (arr[i] == 'B') {
            // Remove last uppercase
            if (!upper.empty()) {
                upper.pop_back();
            }
        }
        else if (arr[i] >= 'a' && arr[i] <= 'z') {
            // Add lowercase
            lower.push_back(i);
        }
        else {
            // Add uppercase
            upper.push_back(i);
        }
    }

    int lIdx = 0;
    int uIdx = 0;
    while (lIdx < lower.size() && uIdx < upper.size()) {
        if (lower[lIdx] < upper[uIdx]) {
            cout << arr[lower[lIdx]];
            lIdx++;
        }
        else {
            cout << arr[upper[uIdx]];
            uIdx++;
        }
    }
    while (lIdx < lower.size()) {
        cout << arr[lower[lIdx]];
        lIdx++;
    }
    while (uIdx < upper.size()) {
        cout << arr[upper[uIdx]];
        uIdx++;
    }
    
    cout << '\n';
}
 
int main() {
    int t;
    string str;
 
    cin >> t;
    while (t--) {
        cin >> str;
        solve(str);
    }
 
    return 0;
}
