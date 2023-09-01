#include <bits/stdc++.h>
using namespace std;

// Increasing and Decreasing

int main() {
    int t;
    int x;
    int y;
    int n;
    vector<int> arr;

    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        arr.clear();

        // Intuition: Start at y (upper bound), decrement by increasing amounts
        //            (y -= 1, y -= 2, y -= 3, ..., y -= n) and append to array.
        //            If y >= x, then print reverse of array with x as the first element.
        //            Otherwise print -1.
        for (int step = 1; step <= n; step++) {
            arr.push_back(y);
            y -= step;
        }
        reverse(arr.begin(), arr.end());
        if (arr.begin()[0] >= x) {
            arr[0] = x;
            for (int i : arr) {
                cout << i << ' ';
            }
        }
        else {
            cout << -1;
        }
        cout << '\n';
    }

    return 0;
}
