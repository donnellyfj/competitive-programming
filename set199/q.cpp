#include <bits/stdc++.h>
using namespace std;

// Dog Walking

void solve(int n, long long int k, vector<long long int> arr) {
    // Intuition: Rotate array, maximize values that can replace the 0s
    long long int out = 0;

    // Loop through rotations
    for (int i = 0; i < n; i++) {
        vector<int> remainingZeros(n);
        remainingZeros.back() = arr.back() == 0;

        for (int j = n - 2; j >= 0; j--) {
            remainingZeros[j] = (arr[j] == 0) + remainingZeros[j + 1];
        }

        vector<long long int> maxArr = arr;
        long long int totalSum = accumulate(maxArr.begin(), maxArr.end(), 0ll);
        bool flag = true;
        for (int idx = 0; idx < n; idx++) {
            if (maxArr[idx] == 0) {
                // Get number of 0s remaining after the current idx
                long long rz = 0;
                if (idx + 1 < n) {
                    rz = remainingZeros[idx + 1];
                }
                // Maximize current 0 as the farthest right you can move currently
                // knowing you have rz chances to move -k to the left in the future
                maxArr[idx] = min(k, rz * k - totalSum);
                if (maxArr[idx] < -k) {
                    flag = false;
                }
                totalSum += maxArr[idx];
            }
        }

        if (flag) {
            long long int currPos = 0;
            long long int minVal = 0;
            long long int maxVal = 0;
            // Find difference between max position and min position
            for (int j = 0; j < n; j++) {
                currPos += maxArr[j];
                minVal = min(minVal, currPos);
                maxVal = max(maxVal, currPos);
            }
            if (currPos == 0) {
                out = max(out, maxVal - minVal + 1);
            }
        }

        rotate(arr.begin(), arr.begin() + 1, arr.end());
    }
    
    if (out == 0) {
        out = -1;
    }
    cout << out << '\n';
}
 
int main() {
    int n;
    long long int k;
    vector <long long int> arr;

    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, k, arr);

    return 0;
}
