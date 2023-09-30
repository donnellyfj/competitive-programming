#include <bits/stdc++.h>
using namespace std;
 
// Number Replacement
 
void solve(int n, vector<int> arr, vector<char> s) {
    // Intuition: Keep track of all number -> character mappings and check for conflicts.
    //            If there are no conflicts, print YES, otherwise print NO.
    unordered_map<int, char> seen;

    for (int i = 0; i < n; i++) {
        int currVal = arr[i];
        char currChar = s[i];

        if (seen.find(currVal) == seen.end()){
            seen[currVal] = currChar;
        }
        else if (seen[currVal] != currChar) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}
 
int main() {
    int t;
    int n;
    vector<int> arr;
    vector<char> s;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        s.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        solve(n, arr, s);
    }
 
    return 0;
}
