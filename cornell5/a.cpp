#include <bits/stdc++.h>
using namespace std;
 
// Eastern Exhibition

void solve(int n, vector<int> xArr, vector<int> yArr) {
    // Intuition: Use range of points between medians.
    sort(xArr.begin(), xArr.end());
    sort(yArr.begin(), yArr.end());

    // Find medians
    long long int numX, numY;
    if (n % 2) {
        numX = 1;
    }
    else {
        numX = xArr[n / 2] - xArr[n / 2 - 1] + 1;
    }

    if (n % 2) {
        numY = 1;
    }
    else {
        numY = yArr[n / 2] - yArr[n / 2 - 1] + 1;
    }

    cout << numX * numY << '\n';
}
 
int main() {
    int t;
    int n;
    vector<int> xArr;
    vector<int> yArr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        int x;
        int y;
        xArr.resize(n);
        yArr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            xArr[i] = x;
            yArr[i] = y;
        }
        solve(n, xArr, yArr);
    }
 
    return 0;
}
