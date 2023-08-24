#include <bits/stdc++.h>
using namespace std;

// Madoka and Childish Pranks

void solve(int i, int j, vector<vector<char>> arr) {
    int out = 0;
    int cut = 0;
    int numOps = 0;
    vector<vector<int>> ops;

    // Check if possible
    if (arr[0][0] == '1') {
        cout << -1 << '\n';
        return;
    }

    // Calculate number of operations required (number of ones)
    for (int idx = 0; idx < i; idx++) {
        for (int jdx = 0; jdx < j; jdx++) {
            if (arr[idx][jdx] == '1') {
                numOps++;
            }
        }
    }

    // Output
    cout << numOps << '\n';

    // Paint rows black horizontally
    for (int idx = 1; idx <= i; idx++) {
        for (int jdx = j; jdx > 1; jdx--) {
            if (arr[idx - 1][jdx - 1] == '1') {
                numOps++;
                cout << idx << ' ' << jdx - 1 << ' ' << idx << ' ' << jdx << '\n';
            }
        }
    }

    // Paint far left column black vertically
    for (int idx = i; idx > 1; idx--) {
        if (arr[idx - 1][0] == '1') {
            cout << idx - 1 << ' ' << 1 << ' ' << idx << ' ' << 1 << '\n';
        }
    }
}

int main() {
    int t;
    int i;
    int j;
    char temp;
    vector<vector<char>> arr;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size:\n";
        scanf("%d", &i);
        scanf("%d", &j);
        // cout << "Input array: ";
        arr.clear();

        for (int idx = 0; idx < i; idx++) {
            arr.push_back(vector<char>());
            // cout << "Input row " << idx << '\n';
            for (int jdx = 0; jdx < j + 1; jdx++) {
                // cout << "Input col " << jdx << '\n';
                scanf("%c", &temp);
                arr[idx].push_back(temp);
            }
            arr[idx].erase(arr[idx].begin()); // Remove \n from beginning
        }

        solve(i, j, arr);
    }
}
