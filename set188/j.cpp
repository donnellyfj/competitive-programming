#include <bits/stdc++.h>
using namespace std;
 
// Zero Path
 
void solve(int n, int m, vector<vector<int>> arr) {
    // Intuition: Keep track of max/min paths.
    vector<vector<int>> maxVals(n, vector<int>(m, 0));
    vector<vector<int>> minVals(n, vector<int>(m, 0));
    
    // Check for odd path length
    if ((m + n - 1) % 2) {
        cout << "NO\n";
        return;
    }
    
    // Set first value
    maxVals[0][0] = arr[0][0];
    minVals[0][0] = arr[0][0];
 
    // Sum first row and column
    for (int i = 1; i < n; i++) {
        maxVals[i][0] = maxVals[i - 1][0] + arr[i][0];
        minVals[i][0] = minVals[i - 1][0] + arr[i][0];
    }
    for (int j = 1; j < m; j++) {
        maxVals[0][j] = maxVals[0][j - 1] + arr[0][j];
        minVals[0][j] = minVals[0][j - 1] + arr[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            maxVals[i][j] = max(maxVals[i - 1][j], maxVals[i][j - 1]) + arr[i][j];
            minVals[i][j] = min(minVals[i - 1][j], minVals[i][j - 1]) + arr[i][j];
        }
    }
 
    if (minVals[n - 1][m - 1] <= 0 && maxVals[n - 1][m - 1] >= 0) {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
 
int main() {
    int t;
    int n;
    int m;
    vector<vector<int>> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i].resize(m);
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        solve(n, m, arr);
    }
 
    return 0;
}
