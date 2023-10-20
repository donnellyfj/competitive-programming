#include <bits/stdc++.h>
using namespace std;
 
// Settlement of Guinea Pigs
 
void solve(int n, vector<int> arr) {
    // Intuition: Greedy, update with max.
    int buy = 0;
    int unknown = 0;
    int known = 0;

    for (int val : arr) {
        if (val == 1) {
            unknown++;
        }
        else {
            known += unknown;
            unknown = 0;
        }
        buy = max(buy, unknown + min(known, (known / 2) + 1));
    }

    cout << buy << '\n';
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
