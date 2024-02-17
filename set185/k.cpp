#include <bits/stdc++.h>
using namespace std;

// Maximize the Intersections

bool intersect(vector<int> a, vector<int> b) {
    if (a[0] > b[0]) {
        swap(a, b);
    }

    return a[1] > b[0] and a[1] < b[1];
}

void solve(int n, int k, vector<vector<int>> arr) {
    // Intuition: Connect all free points to the free point directly across from it,
    //            then count intersections.
    int out = 0;
    vector<int> seen(2 * n + 1, 0);
    
    // Find points that are already taken
    for (int i = 0; i < k; i++) {
        seen[arr[i][0]] = 1;
        seen[arr[i][1]] = 1;
    }

    // Find unused points
    vector<int> unused;
    for (int i = 1; i <= 2 * n; i++) {
        if (seen[i] == 0) {
            unused.push_back(i);
        }
    }

    // Connect points that are across from eachother
    for (int i = 0; i < n - k; i++) {
        // Find the unused point directly across from i
        arr.push_back({unused[i], unused[i + n - k]});
    }

    // Count number of intersections
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][0] > arr[i][1]) {
                swap(arr[i][0], arr[i][1]);
            }
            if (arr[j][0] > arr[j][1]) {
                swap(arr[j][0], arr[j][1]);
            }
            // Check intersection
            out += intersect(arr[i], arr[j]);
        }
    }
    
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    int k;
    vector<vector<int>> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> k;
        arr.resize(k);
        for (int i = 0; i < k; i++) {
            arr[i].resize(2);
            cin >> arr[i][0] >> arr[i][1];
        }
        solve(n, k, arr);
    }
 
    return 0;
}
