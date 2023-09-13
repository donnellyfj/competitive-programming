#include <bits/stdc++.h>
using namespace std;

// Minimum Width

bool solve( vector<long long int> arr, long long int n, long long int width, long long int idx, long long int numLines) {
    long long int line = 0;
    long long int currWidth = 0;
    int i = 0;

    while (i < n) {
        // If word fits, add to line
        if (currWidth + arr[i] <= width) {
            currWidth += arr[i];

            // If there is still room, add a space
            if (currWidth < width) {
                currWidth++;
            }
            i++;
        }
        // If word doesn't fit, make a new line
        else {
            currWidth = 0;
            line++;
        }

        // If used too many lines, return false
        if (line >= numLines) {
            return false;
        }
    }

    return true;
}

int main() {
    long long int n;
    long long int m;
    cin >> n >> m;

    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Intuition: Binary search over widths to find minimum width that fits
    //            within line limit (m)
    long long int l = 1;
    long long int r = accumulate(arr.begin(), arr.end(), 0LL) + n;

    while (l < r) {
        long long int mid = (r + l) / 2;
        bool fit = solve(arr, n, mid, 0, m);

        // Try smaller width
        if (fit) {
            r = mid;
        }
        else { // Try larger width
            l = mid + 1;
        }
    }
    cout << l << '\n';

    return 0;
}
