#include <bits/stdc++.h>
using namespace std;

// Alice and Books

void solve(int n, vector<int> arr) {
    // Intuition: Add the last element and the max aside from the last element,
    //            since you always have to read the last book
    int last = arr.back();
    arr.pop_back();
    sort(arr.begin(), arr.end(), greater<int>());

    cout << arr[0] + last << '\n';
}

int main() {
    int t;
    int n;
    vector<int> arr;

    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }

    return 0;
}
