#include <bits/stdc++.h>
using namespace std;
 
// Great Graphs
 
void solve(int n, vector<long long int> arr) {
    // Intuition: Maximize the amount of negative roads, minimize the amount of positive roads.
    sort(arr.begin(), arr.end());
    long long int neg = 0;
    long long int out = arr.back();
    long long int prev = arr[0];
    for (int i = 1; i < n; i++) {
        neg += (arr[i] - prev) * i;
        out -= neg;
        prev = arr[i];
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    vector<long long int> arr;
 
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
