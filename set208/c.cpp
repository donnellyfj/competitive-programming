#include <bits/stdc++.h>
using namespace std;

// Disturbed People

void solve(int n, vector<int> arr) {
    // Intuition: In the case of 1 0 1, have have the 1 on the right turn to 0
    int out = 0;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] == 1 && arr[i] == 0 && arr[i + 1] == 1) {
            out++;
            arr[i + 1] = 0;
        }
    }
    
    cout << out << '\n';
}
 
int main() {
    int n;
    vector<int> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, arr);

    return 0;
}
