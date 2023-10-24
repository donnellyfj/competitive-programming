#include <bits/stdc++.h>
using namespace std;
 
// Perfect Square

vector<string> arr;
int getOperations(int n, int row, int col) {
    // Count how many operations it would take to match the max of each cell in rotation
    int out = 0;
    char c1 = arr[row][col];
    char c2 = arr[col][n - row - 1];
    char c3 = arr[n - row - 1][n - col - 1];
    char c4 = arr[n - col - 1][row];
    char maxVal = max({c1, c2, c3, c4});
    out = maxVal - c1 + maxVal - c2 + maxVal - c3 + maxVal - c4;

    return out;
}

void solve(int n) {
    // Intuition: Compare each cell with it's corresponding 90 degree rotations.
    int out = 0;
    for (int row = 0; row < n - 1; row++) {
        for (int col = row; col < n - row - 1; col++) {
            out += getOperations(n, row, col);
        }
    }
    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n);
    }
 
    return 0;
}
