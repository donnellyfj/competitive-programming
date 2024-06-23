#include <bits/stdc++.h>
using namespace std;

// Divide Points

void solve(int n, vector<pair<int, int>> arr) {
    // Intuition: Split points by parity of x and y values.
    vector<int> out;
    
    while (true) {
        // Count even/odd points
        vector<vector<int>> counts(2, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            counts[arr[i].first % 2][arr[i].second % 2]++;
        }

        // Check counts
        if (counts[0][0] + counts[1][1] > 0 && counts[0][1] + counts[1][0] > 0) {
            // Split odd/even sum points
            for (int i = 0; i < n; i++) {
                if ((arr[i].first + arr[i].second) % 2) {
                    out.push_back(i);
                }
            }
            cout << out.size() << '\n';
            for (int idx : out) cout << idx + 1 << ' ';
            cout << '\n';
            return;
        }
        else if (counts[0][0] + counts[0][1] > 0 && counts[1][1] + counts[1][0] > 0) {
            // Split points by x value parity
            for (int i = 0; i < n; i++) {
                if ((arr[i].first) % 2) {
                    out.push_back(i);
                }
            }
            cout << out.size() << '\n';
            for (int idx : out) cout << idx + 1 << ' ';
            cout << '\n';
            return;
        }

        // All points exist in one count index, scale points down by half
        for (int i = 0; i < n; i++) {
            arr[i].first /= 2;
            arr[i].second /= 2;
        } 
    }
}

int main() {
    int n;
    vector<pair<int, int>> arr;
    
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first += 1e6;
        arr[i].second += 1e6;
    }
    solve(n, arr);
 
    return 0;
}
