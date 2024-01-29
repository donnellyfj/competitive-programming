#include <bits/stdc++.h>
using namespace std;
 
// Maximal Continuous Rest

void solve(int n, vector<int> arr) {
    // Intuition: Duplicate array, count consecuteve 1s.
    int count = 0;
    int out = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (arr[i]) {
            count += 1;
            out = max(out, count);
        }
        else {
            count = 0;
        }
    }
    
    cout << out << '\n';
}

int main() {
    int n;
    vector<int> arr;
 
    cin >> n;
    arr.resize(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[n + i] = arr[i];
    }
    solve(n, arr);
 
    return 0;
}
