#include <bits/stdc++.h>
using namespace std;

// Divan and a New Project

void solve(int n, vector<pair<long long int, long long int>> arr) {
    long long int out = 0;
    int dist = 1;
    vector<int> coords(n + 1, 0);
    
    // Intuition: Keep most visited buildings as close to HQ as possible.
    //            Put HQ at 0, most visted building at 1, second most at -1,
    //            third most at 2, fourth most at -2, etc.
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < n; i++) {
        out += arr[i].first * dist * 2;
        if (i % 2) {
            coords[arr[i].second + 1] = -dist;
            dist++;
        }
        else {
            coords[arr[i].second + 1] = dist;
        }
    }

    cout << out << '\n';
    for (int i : coords) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    int n;
    int val;
    vector<pair<long long int, long long int>> arr;

    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        // Store (val, idx) pairs
        for (int i = 0; i < n; i++) {
            cin >> val;
            arr[i] = make_pair(val, i);
        }
        solve(n, arr);
    }

    return 0;
}
