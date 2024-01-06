#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// Array Optimization by Deque

typedef tree <pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
void solve(int n, vector<int> arr) {
    // Intuition: Use ordered set.
    long long int out = 0;
    ordered_set orderedSet;
    for (int i = 0; i < n; i++) {
        // Check if it's best to append to beginning or end of deque
        // Use pair to avoid duplicate values being erased by set
        int begin = orderedSet.order_of_key({arr[i], 0});
        int end = i - orderedSet.order_of_key({arr[i], n});
        out += min(begin, end);
        orderedSet.insert({arr[i], i});
    }

    cout << out << '\n';
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
