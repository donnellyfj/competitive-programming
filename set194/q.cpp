#include <bits/stdc++.h>
using namespace std;

// Permutation and Queries

void solve(int n, int q, vector<int> arr, vector<vector<int>> queries) {
    // Intuition: Create a lookahead array to skip trhough the permutations and an array to
    //            reverse the permutation, and adjust when swaps are made.
    int lim = sqrt(n);
    vector<int> skip(n, 0);
    vector<int> rev(n, 0);
    
    // Compute lookahead array
    for (int i = 0; i < n; i++) {
        int curr = i;
        for (int j = 0; j < lim; j++) {
            curr = arr[curr];
        }

        skip[i] = curr;
    }

    // Find reverse permutation
    for (int i = 0; i < n; i++) {
        rev[arr[i]] = i;
    }

    // Read queries
    for (int i = 0; i < q; i++) {
        int x = queries[i][1];
        int y = queries[i][2];
        x--;
        if (queries[i][0] == 1) {
            y--;
            // Swap values in input array and reverse array
            swap(arr[x], arr[y]);
            swap(rev[arr[x]], rev[arr[y]]);

            // Find ending location of new x value in lookahead array
            int newIdx = x;
            for (int j = 0; j < lim; j++) {
                newIdx = arr[newIdx];
            }

            // Step backwards using new reverse permutation
            for (int j = 0; j < lim; j++) {
                skip[x] = newIdx;
                x = rev[x];
                newIdx = rev[newIdx];
            }

            // Find ending location of new y value in lookahead array
            newIdx = y;
            for (int j = 0; j < lim; j++) {
                newIdx = arr[newIdx];
            }

            // Step backwards using new reverse permutation
            for (int j = 0; j < lim; j++) {
                skip[y] = newIdx;
                y = rev[y];
                newIdx = rev[newIdx];
            }
        }
        else {
            // Skip as many times as possible
            while (y > lim) {
                x = skip[x];
                y -= lim;
            }
            while (y > 0) {
                x = arr[x];
                y--;
            }
            cout << x + 1 << '\n';
        }
    }

}

int main() {
    int n;
    int q;
    vector<int> arr;
    vector<vector<int>> queries;
 
    cin >> n >> q;
    arr.resize(n);
    queries.resize(q);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < q; i++) {
        queries[i].resize(3);
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    solve(n, q, arr, queries);
 
    return 0;
}
