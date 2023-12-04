#include <bits/stdc++.h>
using namespace std;
 
// Virus
 
void solve(int n, int m, vector<int> arr) {
    // Intuition: Greedily deal with longer segments first.
    // Sort infected houses
    sort(arr.begin(), arr.end());
    
    // Get segment lengths
    vector<int> segments;
    for (int i = 1; i < m; i++) {
        segments.push_back(abs(arr[i] - arr[i - 1]) - 1);
    }
    // Get wrapped segment length since houses are in a circle
    segments.push_back(n - arr.back() + arr[0] - 1);

    // Sort segment lengths in descending order
    sort(segments.begin(), segments.end(), greater<>());
    
    // It takes two days to handle a segment
    // Immunize house on left and right
    int saved = 0;
    int day = 0;
    for (int i = 0; i < m; i++) {
        int seg = segments[i];
        if (seg - 2 * day > 2) {
            // Immunize houses on left and right of segment
            saved += seg - 1 - 2 * day;
            day += 2;
        }
        else if (seg - 2 * day > 0) {
            // We can only immunize one house
            saved += 1;
            day += 1;
        }
        else {
            // All remaining houses have been infected
            break;
        }
    }

    cout << n - saved << '\n';
}
 
int main() {
    int t;
    int n;
    int m;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        solve(n, m, arr);
    }
 
    return 0;
}
