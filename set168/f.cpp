#include <bits/stdc++.h>
using namespace std;
 
// Cake Assembly Line
 
void solve(int n, int w, int h, vector<int> a, vector<int> b) {
    // Intuition: Go from left to right, starting at the center of the far left cake.
    //            Keep track of the padding you have to spare on the left and right.
    //            If the extra space on either the left or right of the cake falls below
    //            zero, meaning a dispensor is out of bounds, print NO, otherwise print YES.

    // Line up left cake at center of far left dispensor
    int shift = b[0] - a[0];
    for (int i = 0; i < n; i++) {
        a[i] += shift;
    }

    // Keep track of padding remaining on left and right sides of cake
    int left = w - h;
    int right = w - h;
    shift = 0;

    // Loop through the rest of the cakes
    for (int i = 1; i < n; i++) {
        // Check if dispensor is within cake bounds (no shift needed)
        if (b[i] - h >= a[i] - w + shift && b[i] + h <= a[i] + w + shift) {
            // Adjust padding
            left = min(left, b[i] - h - (a[i] - w + shift));
            right = min(right, a[i] + w + shift - (b[i] + h));
        }
        else {
            int diff = 0; // How much to adjust shift
            // Shift cakes left
            if (b[i] - h < a[i] - w + shift) {
                diff = a[i] - w + shift - (b[i] - h);
                shift -= diff;
                left = 0;
                right -= diff;
            }
            // Shift cakes right
            else {
                diff = b[i] + h - (a[i] + w + shift);
                shift += diff;
                right = 0;
                left -= diff;
            }
        }

        if (left < 0 || right < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
 
int main() {
    int t;
    int n;
    int w;
    int h;
    vector<int> a;
    vector<int> b;
 
    cin >> t;
    while (t--) {
        cin >> n >> w >> h;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        solve(n, w, h, a, b);
    }
 
    return 0;
}
