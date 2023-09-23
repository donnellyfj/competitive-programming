#include <bits/stdc++.h>
using namespace std;
 
// Great Graphs
 
void solve(int n, vector<long long int> arr) {
    // Intuition: Sort times. We want to minimize the magnitude of all positive paths and maximize the
    //            magnitude of all negative paths. Sum of all positive paths is max(arr). Rolling sum
    //            of all negative paths is: curr = prev - idx * (curr - prev).

    sort(arr.begin(), arr.end());
    long long int out = arr.back(); // Initiazize as sum of positive paths
    long long int rolling = 0;

    for (int i = 1; i < n; i++) {
        rolling -= i * (arr[i] - arr[i -1]);
        out += rolling;
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
